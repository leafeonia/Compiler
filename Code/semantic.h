#include "tree.h"

typedef struct Type_ Type;
typedef struct FieldList_ FieldList;
typedef struct Function_ Function;

#define BASIC_INT 0
#define BASIC_FLOAT 1

struct Type_ {
	enum {BASIC, STRUCTURE, ARRAY} kind;
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

struct Function_{
    Type* returnType;
    FieldList* arg;
};

void Program(Node* root); //
void ExtDefList(Node* root); //
void ExtDef(Node* root); //
Type* Specifier(Node* root); //
void ExtDecList(Node* root, Type* type);
void FunDec(Node* root, Type* type);
void CompSt(Node* root, Type* type, int addLevel);
Type* StructSpecifier(Node* root); //
FieldList* DefList(Node* root); //
FieldList* VarList(Node* root);
FieldList* ParamDec(Node* root);
void StmtList(Node* root);
void Stmt(Node* root);
FieldList* Def(Node* root); //
FieldList* DecList(Node* root, Type* type);
FieldList* Dec(Node* root, Type* type); //
FieldList* VarDec(Node* root, Type* type);//
Type* Exp(Node* root);

int typeEqual(Type* t1, Type* t2);

void test();

