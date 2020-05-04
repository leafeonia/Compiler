#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "tree.h"

typedef struct Type_ Type;
typedef struct FieldList_ FieldList;
typedef struct Function_ Function;

#define BASIC_INT 0
#define BASIC_FLOAT 1

struct Type_ {
	enum {BASIC, STRUCTURE, ARRAY, FUNCTION} kind;
	union{
		int basic;
		struct { Type* elem; int size; } array;
		FieldList* structure;
	} u;
};

struct FieldList_{
	char* name;
	Type* type;
	FieldList* next;
};

#define DECLARE 1
#define DEFINE 0
struct Function_{
    Type* returnType;
    FieldList* arg;
    int line, status;
};


void Program(Node* root); //
void ExtDefList(Node* root); //
void ExtDef(Node* root); //
Type* Specifier(Node* root); //
void ExtDecList(Node* root, Type* type);
void FunDec(Node* root, Type* type, int isDeclaration);
void CompSt(Node* root, Type* returnType, int addLevel);
Type* StructSpecifier(Node* root); //
FieldList* DefList(Node* root); //
FieldList* VarList(Node* root);
FieldList* ParamDec(Node* root);
void StmtList(Node* root, Type* returnType);
void Stmt(Node* root, Type* returnType);
FieldList* Def(Node* root); //
FieldList* DecList(Node* root, Type* type);
FieldList* Dec(Node* root, Type* type); //
FieldList* VarDec(Node* root, Type* type);//
Type* Exp(Node* root);
FieldList* Args(Node* root);

int typeEqual(Type* t1, Type* t2);
int fieldListEqual(FieldList* f1, FieldList* f2);

#endif
