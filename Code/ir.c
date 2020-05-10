#include "ir.h"
#include "hashTable.h"
#include "semantic.h"

InterCode* irHead = NULL;
InterCode* irTail = NULL;
int curVarNo = 0;
int curLabelNo = 0;

Operand* newOp(int kind, char* value){
	Operand* op = (Operand*)malloc(sizeof(Operand));
	op->kind = kind;
	op->u.value = value;
	return op;
}

Operand* newOp2(int kind, int var_no){
	Operand* op = (Operand*)malloc(sizeof(Operand));
	op->kind = kind;
	op->u.var_no = var_no;
	return op;
}

InterCode* newIc1(int kind, Operand* op1){
	InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
	ic->kind = kind;
	ic->u.singleOp = op1;
	irInsert(ic);
	return ic;
}

InterCode* newIc2(int kind, Operand* op1, Operand* op2){
	InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
	ic->kind = kind;
	ic->u.assign.left = op1;
	ic->u.assign.right = op2;
	irInsert(ic);
	return ic;
}

InterCode* newIc3(int kind, Operand* op1, Operand* op2, Operand* op3){
	InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
	ic->kind = kind;
	ic->u.binop.result = op1;
	ic->u.binop.op1 = op2;
	ic->u.binop.op2 = op3;
	irInsert(ic);
	return ic;
}

InterCode* newIc4(int kind, Operand* op1, Operand* relop, Operand* op2, Operand* op3){
	InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
	ic->kind = kind;
	ic->u.triop.op1 = op1;
	ic->u.triop.relop = relop;
	ic->u.triop.op2 = op2;
	ic->u.triop.op3 = op3;
	irInsert(ic);
	return ic;
}



void irInsert(InterCode* intercode){
	if(!irHead){
		irHead = irTail = intercode;
		irHead->prev = irHead->next = NULL;
	}
	else{
		irTail->next = intercode;
		intercode->prev = irTail;
		intercode->next = NULL;
		irTail = intercode;
	}
}

void irDelete(InterCode* intercode){
	if(!intercode->prev){
		irHead = intercode->next;
	}
	else{
		intercode->prev->next = intercode->next;
	}
	if(!intercode->next){
		irTail = intercode->prev;
	}
	else{
		intercode->next->prev = intercode->prev;
	}
	
	free(intercode);
}

void irProgram(Node* root){
	irExtDefList(root->child);
}

void irExtDefList(Node* root){
	if(!root) return;
    irExtDef(root->child);
    irExtDefList(root->child->sibling);
}

void irExtDef(Node* root){
	if(!root) return;
    //Type* type = Specifier(root->child);
    //if(!type) return;
    Node* second = root->child->sibling;
    if(!second) return;

	// No global definition in lab3
	
    //Specifier ExtDecList SEMI
    if(!strcmp(second->data, "ExtDecList")){
        return;
    }

    //Specifier SEMI
    if(!strcmp(second->data, "SEMI")){
        return;
    }


    if(!strcmp(second->data, "FunDec")){
        //Specifier FunDec CompSt
        if(!strcmp(second->sibling->data, "CompSt")){
            irFunDec(second);
            irCompSt(second->sibling);
            return;
        }

    }
}

void irFunDec(Node* root){
	Operand* op = (Operand*)malloc(sizeof(Operand));
	op->kind = OP_VALUE;
	op->u.value = root->child->data;
	InterCode* intercode = (InterCode*)malloc(sizeof(InterCode));
	intercode->kind = I_FUNCTION;
	intercode->u.singleOp = op;
	irInsert(intercode);
	//TODO: args
}

void irCompSt(Node* root){
	if(!root || !root->child || !root->child->sibling || !root->child->sibling->sibling) return;

    //LC DefList(**Could be empty**) StmtList RC

    if(!strcmp(root->child->sibling->data, "DefList")){
        //irDefList(root->child->sibling);
        irStmtList(root->child->sibling->sibling);
    }
    else{
        irStmtList(root->child->sibling);
    }
}

/*
void irDefList(Node* root){
	if(!root || !root->child) return;
	irDef(root->child);
	irDefList(root->child->sibling);
}

void irDef(Node* root){
	if(!root || !root->child || !root->child->sibling) return;
    irDecList(root->child->sibling);
}

void irDecList(Node* root){
	if(!root || !root->child) return;
    ret = irDec(root->child);
    if(root->child->sibling) irDecList(root->child->sibling->sibling, type);
}

void irDec(Node* root){
	if(!root || !root->child) return;
	//TODO: ignore here when assign?
	//Value* val = hashRead(root->child->child);
	if(root->child->sibling){
		
	}
}*/

void irStmtList(Node* root){
	if(!root || !root->child) return;
	irStmt(root->child);
	irStmtList(root->child->sibling);
}

void irStmt(Node* root){
	if(!root) return;
    char* keyword = root->child->data;

    //Exp SEMI
    if(!strcmp(keyword, "Exp")){
        irExp(root->child, NULL);
        return;
    }

    //CompSt
    if(!strcmp(keyword, "CompSt")){
        irCompSt(root->child);
        return;
    }

    //RETURN Exp SEMI
    if(!strcmp(keyword, "RETURN")){
    	Operand* op = (Operand*)malloc(sizeof(Operand));
    	op->kind = OP_TEMPVAR;
    	op->u.var_no = getVarNo();
        irExp(root->child->sibling, op);
        InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
        ic->kind = I_RETURN;
        ic->u.singleOp = op;
        irInsert(ic);
        return;
    }


    //IF LP Exp RP Stmt
    //IF LP Exp RP Stmt ELSE Stmt
    if(!strcmp(keyword, "IF")){
    	Operand* label1 = (Operand*)malloc(sizeof(Operand));
    	label1->kind = OP_LABEL;
    	label1->u.var_no = getLabelNo();
    	Operand* label2 = (Operand*)malloc(sizeof(Operand));
    	label2->kind = OP_LABEL;
    	label2->u.var_no = getLabelNo();
        Node* third = root->child->sibling->sibling;
        irCond(third, label1, label2);
        InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
        ic->kind = I_LABEL;
        ic->u.singleOp = label1;
        irInsert(ic);
        Node* fifth = third->sibling->sibling;
        irStmt(fifth);
        if(fifth->sibling) {
        	Operand* label3 = (Operand*)malloc(sizeof(Operand));
    		label3->kind = OP_LABEL;
    		label3->u.var_no = getLabelNo();
    		InterCode* ic3 = (InterCode*)malloc(sizeof(InterCode));
		    ic3->kind = I_GOTO;
		    ic3->u.singleOp = label3;
		    irInsert(ic3);
		    InterCode* ic2 = (InterCode*)malloc(sizeof(InterCode));
		    ic2->kind = I_LABEL;
		    ic2->u.singleOp = label2;
		    irInsert(ic2);
    		irStmt(fifth->sibling->sibling);
    		InterCode* ic4 = (InterCode*)malloc(sizeof(InterCode));
		    ic4->kind = I_LABEL;
		    ic4->u.singleOp = label3;
		    irInsert(ic4);
        }
        else{
        	InterCode* ic2 = (InterCode*)malloc(sizeof(InterCode));
		    ic2->kind = I_LABEL;
		    ic2->u.singleOp = label2;
		    irInsert(ic2);
        }
        return;
    }

    //WHILE LP Exp RP Stmt
    if(!strcmp(keyword, "WHILE")){
    	Operand* label1 = newOp2(OP_LABEL, getLabelNo());
    	Operand* label2 = newOp2(OP_LABEL, getLabelNo());
    	Operand* label3 = newOp2(OP_LABEL, getLabelNo());
    	InterCode* ic1 = newIc1(I_LABEL, label1);
        Node* third = root->child->sibling->sibling;
        irCond(third, label2, label3);
        InterCode* ic2 = newIc1(I_LABEL, label2);
        Node* fifth = third->sibling->sibling;
        irStmt(fifth);
        InterCode* ic3 = newIc1(I_GOTO, label1);
        InterCode* ic4 = newIc1(I_LABEL, label3);
        return;
    }

    assert(0);
    return;
}

void irCond(Node* root, Operand* labelTrue, Operand* labelFalse){
	if(!strcmp(root->child->data, "Exp")){
		char* keyword = root->child->sibling->data;
		if(!strcmp(keyword, "AND")){
			Operand* label1 = newOp2(OP_LABEL, getLabelNo());
			irCond(root->child, label1, labelFalse);
			InterCode* ic = newIc1(I_LABEL, label1);
			irCond(root->child->sibling->sibling, labelTrue, labelFalse);
		}
		else if(!strcmp(keyword, "OR")){
			Operand* label1 = newOp2(OP_LABEL, getLabelNo());
			irCond(root->child, labelTrue, label1);
			InterCode* ic = newIc1(I_LABEL, label1);
			irCond(root->child->sibling->sibling, labelTrue, labelFalse);
		}
		
		// Exp RELOP Exp
		else{
			Operand* t1 = newOp2(OP_TEMPVAR, getVarNo());
			Operand* t2 = newOp2(OP_TEMPVAR, getVarNo());
			irExp(root->child, t1);
			irExp(root->child->sibling->sibling, t2);
			Operand* relop = newOp(OP_VALUE, root->child->sibling->data);
			InterCode* ic = newIc4(I_IFGOTO, t1, relop, t2, labelTrue);
			InterCode* ic2 = newIc1(I_GOTO, labelFalse);
		}
	}
	
	else if(!strcmp(root->child->data, "NOT")){
		irCond(root, labelFalse, labelTrue);
	}
	else{
		Operand* temp = newOp2(OP_TEMPVAR, getVarNo());
		irExp(root, temp);
		Operand* relop = newOp(OP_VALUE, "!=");
		Operand* zero = newOp(OP_CONSTANT, "0");
		newIc4(I_IFGOTO, temp, relop, zero, labelTrue);
		newIc1(I_GOTO, labelFalse);
	}
}

void irExp(Node* root, Operand* place){
	if(!root || !root->child) return;
	
	if(!strcmp(root->child->data, "Exp") || !strcmp(root->child->data, "NOT")){
        char* keyword = root->child->sibling->data;

        // Exp ASSIGNOP Exp
        if(!strcmp(keyword, "ASSIGNOP")){
        	Operand* varName = (Operand*)malloc(sizeof(Operand));
        	varName->kind = OP_VALUE;
        	varName->u.value = root->child->child->data; //TODO: only ID here
        	Operand* t1 = (Operand*)malloc(sizeof(Operand));
        	t1->kind = OP_TEMPVAR;
        	t1->u.var_no = getVarNo();
        	irExp(root->child->sibling->sibling, t1);
        	InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
        	ic->kind = I_ASSIGN;
        	ic->u.assign.left = varName;
        	ic->u.assign.right = t1;
        	irInsert(ic);
        	if(place){
        		InterCode* ic2 = (InterCode*)malloc(sizeof(InterCode));
        		ic2->kind = I_ASSIGN;
        		ic2->u.assign.left = place;
        		ic2->u.assign.right = varName;
        		irInsert(ic2);
        	}
        }
        
        if(!strcmp(keyword, "PLUS") || !strcmp(keyword, "MINUS") || !strcmp(keyword, "STAR") ||
                !strcmp(keyword, "DIV") ){
        	Operand* t1 = (Operand*)malloc(sizeof(Operand));
        	t1->kind = OP_TEMPVAR;
        	t1->u.var_no = getVarNo();
        	Operand* t2 = (Operand*)malloc(sizeof(Operand));
        	t2->kind = OP_TEMPVAR;
        	t2->u.var_no = getVarNo();
        	irExp(root->child, t1);
        	irExp(root->child->sibling->sibling, t2);
        	if(place){
        		InterCode* intercode = (InterCode*)malloc(sizeof(InterCode));
        		if(!strcmp(keyword, "PLUS")) intercode->kind = I_ADD;
        		else if(!strcmp(keyword, "MINUS")) intercode->kind = I_MINUS;
                else if(!strcmp(keyword, "STAR")) intercode->kind = I_STAR;
                else if(!strcmp(keyword, "DIV")) intercode->kind = I_DIV;
        		intercode->u.binop.result = place;
        		intercode->u.binop.op1 = t1;
        		intercode->u.binop.op2 = t2;
        		irInsert(intercode);
        	}
        }

        if(!strcmp(keyword, "AND") || !strcmp(keyword, "OR") || !strcmp(keyword, "RELOP") ||
        !strcmp(keyword, "Exp")){
            Operand* label1 = newOp2(OP_LABEL, getLabelNo());
            Operand* label2 = newOp2(OP_LABEL, getLabelNo());
            Operand* zero = newOp(OP_CONSTANT, "0");
            InterCode* ic = newIc2(I_ASSIGN, place, zero);
            irCond(root, label1, label2);
            InterCode* ic2 = newIc1(I_LABEL, label1);
            Operand* one = newOp(OP_CONSTANT, "1");
            newIc2(I_ASSIGN, place, one);
            newIc1(I_LABEL, label2);
        }
	}

	//MINUS Exp
	else if(!strcmp(root->child->data, "MINUS")){
	    int no = getVarNo();
	    Operand* t1 = newOp2(OP_TEMPVAR, no);
	    irExp(root->child->sibling, t1);
	    char* s = (char*)malloc(10 * sizeof(char));
	    sprintf(s, "#0 - t%d", no);
	    Operand* op = newOp(OP_VALUE, s);
	    newIc2(I_ASSIGN, place, op);
	}
	
	//INT FLOAT
    else if(root->child->type == ENUM_INT || root->child->type == ENUM_FLOAT){
        Operand* op = (Operand*)malloc(sizeof(Operand));
        op->kind = OP_CONSTANT;
        op->u.value = root->child->data;
        InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
        ic->kind = I_ASSIGN;
        ic->u.assign.left = place;
        ic->u.assign.right = op;
        irInsert(ic);
    }
    
    else if(root->child->type == ENUM_ID){
    	char* name = root->child->data;
    	
    	//ID
    	if(!root->child->sibling){
    		Operand* op = (Operand*)malloc(sizeof(Operand));
		    op->kind = OP_VALUE;
		    op->u.value = root->child->data;
		    InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
		    ic->kind = I_ASSIGN;
		    ic->u.assign.left = place;
		    ic->u.assign.right = op;
		    irInsert(ic);
		    return;
    	}
    	
    	Node* third = root->child->sibling->sibling;
        if(!third) return;
        
        //ID LP RP
        //ID LP Args RP
        if(!strcmp(root->child->sibling->data, "LP")){
        	if(!strcmp(name, "read")){
        		InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
        		ic->kind = I_READ;
        		ic->u.singleOp = place;
        		irInsert(ic);
        		return;
        	}
        	if(place){
        		Operand* op = (Operand*)malloc(sizeof(Operand));
        		op->kind = OP_VALUE;
        		op->u.value = name;
        		InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
        		ic->kind = I_CALL;
        		ic->u.assign.left = place;
        		ic->u.assign.right = op;
        		irInsert(ic);
        	}

            if(!strcmp(third->data, "Args")){
            	List* argList = (List*)malloc(sizeof(List));
            	argList->val = NULL;
            	argList->next = NULL;
                irArgs(third, argList);
                if(!strcmp(name, "write")){
                	Operand* op = (Operand*)malloc(sizeof(Operand));
		    		op->kind = OP_VALUE;
		    		op->u.value = argList->val;
		    		InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
		    		ic->kind = I_WRITE;
		    		ic->u.singleOp = op;
		    		irInsert(ic);
		    		if(place) {
                        Operand *op2 = (Operand *) malloc(sizeof(Operand));
                        op2->kind = OP_CONSTANT;
                        op2->u.value = "0";
                        InterCode *ic2 = (InterCode *) malloc(sizeof(InterCode));
                        ic2->kind = I_ASSIGN;
                        ic2->u.assign.left = place;
                        ic2->u.assign.right = op2;
                        irInsert(ic2);
                    }
		    		return;
                }
                
                while(argList->val){
                	Operand* op = (Operand*)malloc(sizeof(Operand));
		    		op->kind = OP_VALUE;
		    		op->u.value = argList->val;
		    		InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
		    		ic->kind = I_ARG;
		    		ic->u.singleOp = op;
		    		irInsert(ic);
                }
                
                Operand* op = (Operand*)malloc(sizeof(Operand));
                op->kind = OP_VALUE;
                op->u.value = name;
                InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
		    	ic->kind = I_FUNCTION;
		    	ic->u.singleOp = op;
		   		irInsert(ic);
            }
        }
    }
}

void irArgs(Node* root, List* argList){
	Operand* op = (Operand*)malloc(sizeof(Operand));
	op->kind = OP_TEMPVAR;
	op->u.var_no = getVarNo();
	irExp(root->child, op);
	if(op->kind == OP_TEMPVAR){
	    char* s = (char*)malloc(50);
	    sprintf(s, "t%d", op->u.var_no);
	    argList->val = s;
	}
	else argList->val = op->u.value;
	List* nextArg = (List*)malloc(sizeof(List));
	nextArg->next = NULL;
	nextArg->val = NULL;
	argList->next = nextArg;
	if(root->child->sibling){
		irArgs(root->child->sibling->sibling, nextArg);
	}
}


void irPrintOperand(Operand* op, FILE* fp){
	switch (op->kind){
		case OP_VALUE:
			fprintf(fp, "%s ", op->u.value);
			break;
		case OP_TEMPVAR:
			fprintf(fp, "t%d ", op->u.var_no);
			break;
		case OP_CONSTANT:
			fprintf(fp, "#%s ", op->u.value);
			break;
		case OP_LABEL:
			fprintf(fp, "label%d ", op->u.var_no);
			break;
		default:
			break;
	}
		
}


void irPrintCode(FILE* fp){
	InterCode* cur = irHead;
	while(cur){
		switch (cur->kind){
			case I_FUNCTION:
				fprintf(fp, "FUNCTION ");
				irPrintOperand(cur->u.singleOp, fp);
				fprintf(fp, ": ");
				break;
			case I_ASSIGN:
				irPrintOperand(cur->u.assign.left, fp);
				fprintf(fp, ":= ");
				irPrintOperand(cur->u.assign.right, fp);
				break;
			case I_ADD:
				irPrintOperand(cur->u.binop.result, fp);
				fprintf(fp, ":= ");
				irPrintOperand(cur->u.binop.op1, fp);
				fprintf(fp, "+ ");
				irPrintOperand(cur->u.binop.op2, fp);
				break;
            case I_MINUS:
                irPrintOperand(cur->u.binop.result, fp);
                fprintf(fp, ":= ");
                irPrintOperand(cur->u.binop.op1, fp);
                fprintf(fp, "- ");
                irPrintOperand(cur->u.binop.op2, fp);
                break;
            case I_STAR:
                irPrintOperand(cur->u.binop.result, fp);
                fprintf(fp, ":= ");
                irPrintOperand(cur->u.binop.op1, fp);
                fprintf(fp, "* ");
                irPrintOperand(cur->u.binop.op2, fp);
                break;
            case I_DIV:
                irPrintOperand(cur->u.binop.result, fp);
                fprintf(fp, ":= ");
                irPrintOperand(cur->u.binop.op1, fp);
                fprintf(fp, "/ ");
                irPrintOperand(cur->u.binop.op2, fp);
                break;
			case I_READ:
				fprintf(fp, "READ ");
				irPrintOperand(cur->u.singleOp, fp);
				break;
			case I_WRITE:
				fprintf(fp, "WRITE ");
				irPrintOperand(cur->u.singleOp, fp);
				break;
			case I_CALL:
				irPrintOperand(cur->u.assign.left, fp);
				fprintf(fp, ":= CALL ");
				irPrintOperand(cur->u.assign.right, fp);
				break;
			case I_ARG:
				fprintf(fp, "ARG ");
				irPrintOperand(cur->u.singleOp, fp);
				break;
			case I_RETURN:
				fprintf(fp, "RETURN ");
				irPrintOperand(cur->u.singleOp, fp);
				break;
			case I_LABEL:
				fprintf(fp, "LABEL ");
				irPrintOperand(cur->u.singleOp, fp);
				fprintf(fp, ":");
				break;
			case I_GOTO:
				fprintf(fp, "GOTO ");
				irPrintOperand(cur->u.singleOp, fp);
				break;
			case I_IFGOTO:
				fprintf(fp, "IF ");
				irPrintOperand(cur->u.triop.op1, fp);
				irPrintOperand(cur->u.triop.relop, fp);
				irPrintOperand(cur->u.triop.op2, fp);
				fprintf(fp, "GOTO ");
				irPrintOperand(cur->u.triop.op3, fp);
			default:
				break;
				
		}
		fprintf(fp, "\n");
		cur = cur->next;
	}
}

int getVarNo(){
	return curVarNo++;
}

int getLabelNo(){
	return curLabelNo++;
}
