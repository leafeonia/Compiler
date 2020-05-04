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
		
}

void irPrintOperand(Operand* op, FILE* fp){
	switch (op->kind){
		case OP_VALUE:
			fprintf(fp, "%s ", op->u.value);
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
			default:
				break;
				
		}
		fprintf(fp, "\n");
		cur = cur->next;
	}
}
