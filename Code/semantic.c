#include "semantic.h"
#include "hashTable.h"
#include <string.h>


void Program(Node* root){
    if(!root) return;
    hashInit();
    ExtDefList(root->child);
}

void ExtDefList(Node* root){
    if(!root) return;
    ExtDef(root->child);
    ExtDefList(root->child->sibling);

}

void ExtDef(Node* root){
    if(!root || !root->child) return;
    Type* type = Specifier(root->child);
    if(!type) return;
    Node* second = root->child->sibling;
    if(!second) return;

    //Specifier ExtDecList SEMI
    if(strcmp(second->data, "ExtDecList") == 0){
        ExtDecList(second, type);
        return;
    }

    //Specifier SEMI
    if(strcmp(second->data, "SEMI") == 0){
        return;
    }

    //Specifier FunDec CompSt
    if(strcmp(second->data, "FunDec") == 0){
        FunDec(second, type);
        CompSt(second->sibling, type, 0);
        return;
    }
    assert(0);
}

Type* Specifier(Node* root){
    if(!root || !root->child) return NULL;
    Node* child = root->child;
    if(strcmp(child->data, "int") == 0){
        Type* ret = (Type*)malloc(sizeof(Type));
        ret->kind = BASIC;
        ret->u.basic = BASIC_INT;
        return ret;
    }
    if(strcmp(child->data, "float") == 0){
        Type* ret = (Type*)malloc(sizeof(Type));
        ret->kind = BASIC;
        ret->u.basic = BASIC_FLOAT;
        return ret;
    }
    if(strcmp(child->data, "StructSpecifier") == 0){
        return StructSpecifier(child);
    }
    assert(0);
    return NULL;
}

Type* StructSpecifier(Node* root){
    if(!root || !root->child || !root->child->sibling) return NULL;
    Node* second = root->child->sibling;

    //STRUCT OptTag LC DefList RC
    if(strcmp(second->data, "OptTag") == 0){
        Type* ret = (Type*)malloc(sizeof(Type));
        ret->kind = STRUCTURE;
        char* name = second->child->data;
        if(hashRead(name)){
            printf("Error type 16 at Line %d: Duplicated name \"%s\".\n", second->line, name);
            return NULL;
        }
        Node* fourth = second->sibling->sibling;
        ret->u.structure = DefList(fourth);
        if(!ret->u.structure){
            free(ret);
            return NULL;
        }
        ret->u.structure->name = name;
        if(name) hashInsert(name, ret);
        return ret;
    }

    //STRUCT Tag
    if(strcmp(second->data, "Tag") == 0){
        void* ret = hashRead(second->child->data);
        if(!ret){
            printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",second->child->line, second->child->data);
            return NULL;
        }
        return (Type*)ret;
    }

    return NULL;
}

void ExtDecList(Node* root, Type* type){
    if(!root || !root->child) return;

    // VarDec
    VarDec(root->child, type);

    // VarDec COMMA ExtDecList
    if(root->child->sibling){
        ExtDecList(root->child->sibling, type);
    }
}

void FunDec(Node* root, Type* type){
    if(!root || !root->child || !root->child->sibling || !root->child->sibling->sibling) return;


    if(hashRead(root->child->data)){
        printf("Error type 4 at Line %d: Redefined function \"%s\".\n", root->child->line, root->child->data);
        return;
    }

    Function* function = (Function*)malloc(sizeof(Function));
    function->returnType = type;
    Node* third = root->child->sibling->sibling;

    FieldList* args = NULL;
    //ID LP VarList RP
    if(!strcmp(third->data, "VarList")){
        args = VarList(third);
    }
    //ID LP RP

    function->arg = args;
    hashInsertDepth(root->child->data, function, 0);
}

FieldList* VarList(Node* root){
    if(!root || !root->child) return NULL;
    pushDepth();
    FieldList* ret = ParamDec(root->child);
    if(!ret) return NULL;
    //ParamDec

    //ParamDec COMMA VarList
    if(root->child->sibling) {
        while(ret->next) ret = ret->next;
        ret->next = VarList(root->child->sibling->sibling);
    }
    return ret;
}

FieldList* ParamDec(Node* root){
    if(!root || !root->child || !root->child->sibling) return NULL;
    Type* type = Specifier(root->child);
    return VarDec(root->child->sibling, type);
}

void CompSt(Node* root, Type* type, int addLevel){
    popDepth();
}

FieldList* DefList(Node* root){
    if(!root || !root->child) return NULL;
    FieldList* ret = Def(root->child);
    if(!ret) return NULL;
    FieldList* tail = ret;
    while(tail->next) tail = tail->next;
    tail->next = DefList(root->child->sibling);
    return ret;
}

FieldList* Def(Node* root){
    if(!root || !root->child || !root->child->sibling) return NULL;
    Type* type = Specifier(root->child);
    return DecList(root->child->sibling, type);
}

FieldList* DecList(Node* root, Type* type){
    if(!root || !root->child) return NULL;
    FieldList* ret = Dec(root->child, type);
    if(!ret) return NULL;

    // Dec
    if(!root->child->sibling) return ret;

    // Dec COMMA DecList
    ret->next = DecList(root->child->sibling->sibling, type);
    return ret;
}

FieldList* Dec(Node* root, Type* type){
    if(!root || !root->child) return NULL;

    //VarDec
    FieldList* ret = VarDec(root->child, type);
    if(!ret) return NULL;

    //VarDec ASSIGNOP Exp
    if(root->child->sibling){
        Type* expType = Exp(root->child->sibling->sibling);
        if(!expType) return NULL;
        if(!typeEqual(ret->type, expType)){
            printf("Error type 5 at Line %d: Type mismatched for assignment.\n", root->child->sibling->sibling->line);
        }
    }

    return ret;
}

//Use FieldList instead of Type because name property is assigned here
FieldList* VarDec(Node* root, Type* type){
    if(!root || !root->child) return NULL;

    //ID
    if(root->child->type == ENUM_ID){
        FieldList* ret = (FieldList*)malloc(sizeof(FieldList));
        ret->name = root->child->data;
        if(hashRead(ret->name)){
            printf("Error type 3 at Line %d: Redefined variable \"%s\".\n", root->child->line, ret->name);
            free(ret);
            return NULL;
        }
        ret->type = type;
        ret->next = NULL;
        hashInsert(ret->name, ret->type);
        return ret;
    }

        //VarDec LB INT RB
    else if(strcmp(root->child->data, "VarDec") == 0){
        int num = atoi(root->child->sibling->sibling->data);
        Type* childType = (Type*)malloc(sizeof(Type));
        childType->kind = ARRAY;
        childType->u.array.elem = type;
        childType->u.array.size = num;
        return VarDec(root->child, childType);
    }

    assert(0);
    return NULL;
}

Type* Exp(Node* root){
    if(!root || !root->child) return NULL;

    if(strcmp(root->child->data, "Exp") == 0){
        char* keyword = root->child->sibling->data;

        // Exp ASSIGNOP Exp
        if(strcmp(keyword, "ASSIGNOP") == 0){
            Type* type1 = Exp(root->child);
            Type* type2 = Exp(root->child->sibling->sibling);
            if(!type1 || !type2) return NULL;
            if(!typeEqual(type1, type2)){
                printf("Error type 5 at Line %d: Type mismatched for assignment.\n", root->child->line);
                return NULL;
            }
            return type1;
        }

        // Exp AND Exp
        // Exp OR Exp
        if(!strcmp(keyword, "AND") || !strcmp(keyword, "OR")){
            Type* type1 = Exp(root->child);
            Type* type2 = Exp(root->child->sibling->sibling);
            if(!type1 || !type2) return NULL;
            if(type1->kind != BASIC || type2->kind != BASIC || type1->u.basic != BASIC_INT || type2->kind != BASIC_INT){
                printf("Error type 7 at Line %d: Type mismatched for operands.\n", root->child->line);
                return NULL;
            }
            return type1;
        }

        // Exp LB Exp RB
        if(!strcmp(keyword, "LB")){
            Type* type1 = Exp(root->child);
            if(!type1) return NULL;
            if(type1->kind != ARRAY){
                printf("Error type 10 at Line %d: \"%s\" is not an array.\n", root->child->line, root->child->child->data);
                return NULL;
            }
            Node* third = root->child->sibling->sibling;
            Type* type2 = Exp(third);
            if(type2->kind != BASIC || type2->u.basic != BASIC_INT){
                printf("Error type 12 at Line %d: \"%s\" is not an integer.\n", third->line, third->child->data);
                return NULL;
            }
            return type1->u.array.elem;
        }

        // Exp DOT ID
        if(!strcmp(keyword, "DOT")){
            Type* type = Exp(root->child);
            if(!type) return NULL;
            if(type->kind != STRUCTURE){
                printf("Error type 13 at Line %d: Illegal use of \".\"\n", root->child->line);
                return NULL;
            }
            char* field = root->child->sibling->sibling->data;
            FieldList* fieldList = type->u.structure;
            while(fieldList){
                if(!strcmp(field, fieldList->name)){
                    return fieldList->type;
                }
                fieldList = fieldList->next;
            }
            printf("Error type 14 at Line %d: Non-existent field \"%s\".", root->child->sibling->sibling->line, field);
            return NULL;
        }

        // Exp RELOP/ADD/MINUS/STAR/DIV Exp
        Type* type1 = Exp(root->child);
        Type* type2 = Exp(root->child->sibling->sibling);
        if(!type1 || !type2) return NULL;
        if(type1->kind != BASIC || type2->kind != BASIC || type1->u.basic != type2->u.basic){
            printf("Error type 7 at Line %d: Type mismatched for operands.\n", root->child->line);
            return NULL;
        }
        return type1;
    }

    //LP Exp RP
    if(!strcmp(root->child->data, "LP")){
        return Exp(root->child->sibling);
    }

    //MINUS Exp
    if(!strcmp(root->child->data, "MINUS")){
        Type* type = Exp(root->child->sibling);
        if(!type) return NULL;
        if(type->kind != BASIC){
            printf("Error type 7 at Line %d: Operands type mismatched\n", root->child->sibling->line);
            return NULL;
        }
        return type;
    }

    //NOT Exp
    if(!strcmp(root->child->data, "NOT")){
        Type* type = Exp(root->child->sibling);
        if(!type) return NULL;
        if(type->kind != BASIC || type->u.basic != BASIC_INT){
            printf("Error type 7 at Line %d: Operands type mismatched\n", root->child->sibling->line);
            return NULL;
        }
        return type;
    }

    if(!strcmp(root->child->data, "ID")){
        //ID
        if(!root->child->sibling){
            Type* varType = (Type*)hashRead(root->child->data);
            if(!varType){
                printf("Error type 1 at Line %d: Undefined variable \"%s\".\n", root->child->line, root->child->data);
                return NULL;
            }
            return varType;
        }

        Node* third = root->child->sibling->sibling;
        if(!third) return NULL;

        //ID LP RP
        if(!strcmp(third->data, "RP")){

        }

        return NULL;

    }

    //INT
    if(!strcmp(root->child->data, "INT")){
        Type* ret = (Type*)malloc(sizeof(Type));
        ret->kind = BASIC;
        ret->u.basic = BASIC_INT;
        return ret;
    }

    //FLOAT
    if(!strcmp(root->child->data, "FLOAT")){
        Type* ret = (Type*)malloc(sizeof(Type));
        ret->kind = BASIC;
        ret->u.basic = BASIC_FLOAT;
        return ret;
    }

    return NULL;
}

int typeEqual(Type* type1, Type* type2){
    if(!type1 || !type2) return 0;
    if(type1->kind != type2->kind) return 0;
    if(type1->kind == BASIC){
        return type1->u.basic == type2->u.basic;
    }
    if(type1->kind == ARRAY){
        return typeEqual(type1->u.array.elem, type2->u.array.elem);
    }
    if(type1->kind == STRUCTURE){
        FieldList* f1 = type1->u.structure;
        FieldList* f2 = type2->u.structure;
        if(!f1 || !f2) return 0;
        while(f1 && f2){
            if(!typeEqual(f1->type, f2->type)) return 0;
            f1 = f1->next;
            f2 = f2->next;
        }
        if(f1 || f2) return 0;
        return 1;

    }
    assert(0);
    return 0;
}

void test(){
    hashInsert("1", NULL);
    printTable();
    hashInsert("2", NULL);
    hashInsert("3", NULL);
    hashInsert("4", NULL);
    hashInsert("5", NULL);
    printTable();
    pushDepth();
    hashInsert("1", NULL);
    hashInsert("2", NULL);
    hashInsert("3", NULL);
    hashInsert("4", NULL);
    printTable();
    hashInsertDepth("6", NULL, 0);
    printTable();
    pushDepth();
    hashInsert("21", NULL);
    hashInsert("22", NULL);
    printTable();
    popDepth();
    printTable();
    hashInsert("15", NULL);
    printTable();
    popDepth();
    printTable();
}
