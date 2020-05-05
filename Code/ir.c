#include "ir.h"
#include "hashTable.h"


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
	//TODO: ignore here?
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
        
        return;
    }

/*
    //IF LP Exp RP Stmt
    //IF LP Exp RP Stmt ELSE Stmt
    if(!strcmp(keyword, "IF")){
        Node* third = root->child->sibling->sibling;
        Type* type = Exp(third);
        //if(!type) return;
        if(type && (type->kind != BASIC || type->u.basic != BASIC_INT)){
            printf("Error type 11 at Line %d: Not an integer in if statement.\n", third->line);
            return;
        }
        Node* fifth = third->sibling->sibling;
        Stmt(fifth, returnType);
        if(fifth->sibling) Stmt(fifth->sibling->sibling, returnType);
        return;
    }

    //WHILE LP Exp RP Stmt
    if(!strcmp(keyword, "WHILE")){
        Node* third = root->child->sibling->sibling;
        Type* type = Exp(third);
        if(!type) return;
        if(type->kind != BASIC || type->u.basic != BASIC_INT){
            printf("Error type 11 at Line %d: Not an integer in while statement.\n", third->line);
            return;
        }
        Node* fifth = third->sibling->sibling;
        Stmt(fifth, returnType);
        return;
    }
*/
    assert(0);
    return;
}

void irExp(Node* root, Operand* place){
	if(!root || !root->child) return;
	
	if(!strcmp(root->child->data, "Exp")){
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
        
        if(!strcmp(keyword, "PLUS")){
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
        		intercode->kind = I_ADD;
        		intercode->u.binop.result = place;
        		intercode->u.binop.op1 = t1;
        		intercode->u.binop.op2 = t2;
        		irInsert(intercode);
        	}
        }
	}
	
	//INT
    if(root->child->type == ENUM_INT){
        Operand* op = (Operand*)malloc(sizeof(Operand));
        op->kind = OP_VALUE;
        op->u.value = root->child->data;
        InterCode* ic = (InterCode*)malloc(sizeof(InterCode));
        ic->kind = I_ASSIGN;
        ic->u.assign.left = place;
        ic->u.assign.right = op;
        irInsert(ic);
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
