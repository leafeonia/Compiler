#ifndef IR_H
#define IR_H

#include "tree.h"
#include <string.h>

typedef struct Operand_ Operand;
typedef struct InterCode_ InterCode;

struct Operand_{
	enum {OP_VALUE} kind;
	union{
		int var_no;
		char* value;
	} u;
};

typedef struct InterCode_{
	enum {I_FUNCTION,ASSIGN, ADD, SUB, MUL} kind;
	union{
		Operand* singleOp;
		struct {Operand* left; Operand* right;} assign;
		struct {Operand* result; Operand* op1; Operand* op2;} binop;
	} u;
	InterCode* prev;
	InterCode* next;
} InterCode;

InterCode* irHead = NULL;
InterCode* irTail = NULL;


void irProgram(Node* root);
void irExtDefList(Node* root);
void irExtDef(Node* root);
void irFunDec(Node* root);
void irCompSt(Node* root);
void irInsert(InterCode* intercode);
void irDelete(InterCode* intercode);
void irPrintOperand(Operand* op, FILE* fp);
void irPrintCode(FILE* fp);

#endif

