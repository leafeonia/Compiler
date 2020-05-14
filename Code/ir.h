#ifndef IR_H
#define IR_H

#include "tree.h"
#include <string.h>
#include "semantic.h"

typedef struct Operand_ Operand;
typedef struct InterCode_ InterCode;
typedef struct List_ List; 

struct Operand_{
	enum {OP_VALUE, OP_TEMPVAR, OP_CONSTANT, OP_LABEL, OP_NUM, OP_ADDR, OP_DEREF, OP_NUM2, OP_VAR} kind;
	union{
		int var_no;
		char* value;
	} u;
};

struct InterCode_{
	enum {I_FUNCTION, I_PARAM, I_ASSIGN, I_READ, I_WRITE, I_CALL, I_ARG, I_RETURN, I_LABEL,
	        I_GOTO, I_IFGOTO, I_ADD, I_MINUS, I_STAR, I_DIV, I_DEC} kind;
	union{
		Operand* singleOp;
		struct {Operand* left; Operand* right;} assign;
		struct {Operand* result; Operand* op1; Operand* op2;} binop;
		struct {Operand* op1; Operand* relop; Operand* op2; Operand* op3;} triop;
	} u;
	InterCode* prev;
	InterCode* next;
};

struct List_{
	char* val;
	List* next;
};

void initOp();
void irProgram(Node* root);
void irExtDefList(Node* root);
void irExtDef(Node* root);
void irFunDec(Node* root);
void irVarList(Node* root);
void irParamDec(Node* root);
void irDefList(Node* root);
void irDef(Node* root);
void irDecList(Node* root, Type* type);
void irDec(Node* root, Type* type);
FieldList* irVarDec(Node* root, Type* type, int flag);
void irCompSt(Node* root);
void irInsert(InterCode* intercode);
void irDelete(InterCode* intercode);
void irPrintOperand(Operand* op, FILE* fp);
void irPrintCode(FILE* fp);
void irExp(Node* root, Operand* op);
void irRealExp(Node* root, Operand* op, int depth);
void irArgs(Node* root, List* argList);
void irCond(Node* root, Operand* labelTrue, Operand* labelFalse);
void irStmt(Node* root);
void irStmtList(Node* root);
int getVarNo();
int getLabelNo();

#endif

