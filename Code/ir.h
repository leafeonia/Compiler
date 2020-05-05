#ifndef IR_H
#define IR_H

#include "tree.h"
#include <string.h>

typedef struct Operand_ Operand;
typedef struct InterCode_ InterCode;

struct Operand_{
	enum {OP_VALUE, OP_TEMPVAR} kind;
	union{
		int var_no;
		char* value;
	} u;
};

typedef struct InterCode_{
	enum {I_FUNCTION,I_ASSIGN, I_ADD, I_SUB, I_MUL} kind;
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
int curVarNo = 0;

void irProgram(Node* root);
void irExtDefList(Node* root);
void irExtDef(Node* root);
void irFunDec(Node* root);
void irCompSt(Node* root);
void irInsert(InterCode* intercode);
void irDelete(InterCode* intercode);
void irPrintOperand(Operand* op, FILE* fp);
void irPrintCode(FILE* fp);
void irExp(Node* root, Operand* op);
int getVarNo();

#endif

