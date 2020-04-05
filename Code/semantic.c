#include "semantic.h"
#include "hashTable.h"
#include <string.h>

int structFlag;
int funcParamFlag;

void Program(Node* root){
    if(!root) return;
    hashInit();
    structFlag = funcParamFlag = 0;
    ExtDefList(root->child);

    //for 2.1
    for(int i = 0;i < HASH_SIZE;i++){
        if(hashtable[i]){
            Entry* cur = hashtable[i];
            while(cur){
                if(cur->value->kind && cur->value->kind->kind == FUNCTION){
                    Function* func = (Function*) cur->value->val;
                    if(func->status == DECLARE){
                        printf("Error type 18 at Line %d: Undefined function \"%s\".\n", func->line, cur->name);
                    }
                }
                cur = cur->next;
            }
        }
    }
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


    if(strcmp(second->data, "FunDec") == 0){
        //Specifier FunDec CompSt
        if(!strcmp(second->sibling->data, "CompSt")){
            funcParamFlag = 1;
            pushDepth();
            FunDec(second, type, 0);
            funcParamFlag = 0;
            CompSt(second->sibling, type, 0);
            return;
        }

        //Specifier FunDec SEMI
        else{
            funcParamFlag = 1;
            pushDepth();
            FunDec(second, type, 1);
            popDepth();
            funcParamFlag = 0;
            return;
        }

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
            free(ret);
            return NULL;
        }
        Node* fourth = second->sibling->sibling;
        structFlag++;
        ret->u.structure = DefList(fourth);
        structFlag--;

        //struct A{};
//        if(!ret->u.structure){
//            free(ret);
//            return NULL;
//        }
        if(name) {
            Value* value = (Value*)malloc(sizeof(Value));
            value->kind = ret;
            value->val = NULL; // for structure, no other info need to record
            hashInsert(name, value);
        }
        return ret;
    }

    //STRUCT Tag
    if(strcmp(second->data, "Tag") == 0){
        Value* ret = hashRead(second->child->data);
        if(!ret){
            printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",second->child->line, second->child->data);
            return NULL;
        }
        return ret->kind;
    }

    return NULL;
}

void ExtDecList(Node* root, Type* type){
    if(!root || !root->child) return;

    // VarDec
    VarDec(root->child, type);

    // VarDec COMMA ExtDecList
    if(root->child->sibling){
        ExtDecList(root->child->sibling->sibling, type);
    }
}

void FunDec(Node* root, Type* type, int isDeclaration){
    if(!root || !root->child || !root->child->sibling || !root->child->sibling->sibling) return;

    Value* value = hashRead(root->child->data);
    if(value && value->kind->kind == FUNCTION && ((Function*)(value->val))->status == DEFINE && !isDeclaration){
        printf("Error type 4 at Line %d: Redefined function \"%s\".\n", root->child->line, root->child->data);
        return;
    }

    Node* third = root->child->sibling->sibling;

    FieldList* args = NULL;
    //ID LP VarList RP
    if(!strcmp(third->data, "VarList")){
        args = VarList(third);
    }
    //ID LP RP

    if(value && value->kind->kind == FUNCTION){
        if(!fieldListEqual(args, ((Function*)(value->val))->arg) || !typeEqual(type, ((Function*)(value->val))->returnType)){
            printf("Error type 19 at Line %d: Inconsistent declaration of function \"%s\".\n",root->child->line, root->child->data);
        }
    }

    if(!value){
        Function* function = (Function*)malloc(sizeof(Function));
        function->returnType = type;
        function->line = root->child->line;
        function->arg = args;
        function->status = isDeclaration;
        Value* val = (Value*)malloc(sizeof(Value));
        Type* funcType = (Type*)malloc(sizeof(Type));
        funcType->kind = FUNCTION;
        val->kind = funcType;
        val->val = function;
        hashInsertDepth(root->child->data, val, 0);
    }

    if(value && value->kind->kind == FUNCTION && ((Function*)(value->val))->status == DECLARE && !isDeclaration){
        ((Function*)(value->val))->status = DEFINE;
    }

}

FieldList* VarList(Node* root){
    if(!root || !root->child) return NULL;
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

void CompSt(Node* root, Type* returnType, int addLevel){
    if(!root || !root->child || !root->child->sibling || !root->child->sibling->sibling) return;

    //LC DefList(**Could be empty**) StmtList RC
    if(addLevel) pushDepth();
    if(!strcmp(root->child->sibling->data, "DefList")){
        DefList(root->child->sibling);
        StmtList(root->child->sibling->sibling, returnType);
    }
    else{
        StmtList(root->child->sibling, returnType);
    }
    popDepth();
}

void StmtList(Node* root, Type* returnType){
    if(!root) return;
    Stmt(root->child, returnType);
    if(root->child) StmtList(root->child->sibling, returnType);
}

void Stmt(Node* root, Type* returnType){
    if(!root) return;
    char* keyword = root->child->data;

    //Exp SEMI
    if(!strcmp(keyword, "Exp")){
        Exp(root->child);
        return;
    }

    //CompSt
    if(!strcmp(keyword, "CompSt")){
        CompSt(root->child, returnType, 1);
        return;
    }

    //RETURN Exp SEMI
    if(!strcmp(keyword, "RETURN")){
        Type* expType = Exp(root->child->sibling);
        if(!typeEqual(expType, returnType)){
            printf("Error type 8 at Line %d: Type mismatched for return.\n", root->child->sibling->line);
        }
        return;
    }


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

    assert(0);
    return;
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
        if(structFlag){
            printf("Error type 15 at Line %d: Cannot assign value in struct definition.\n", root->child->line);
            return ret;
        }
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
        Value* readVal = hashRead(ret->name);
        if(readVal && (readVal->depth == curDepth || readVal->kind->kind == STRUCTURE || readVal->kind->kind == FUNCTION)){
            if(structFlag) printf("Error type 15 at Line %d: Redefined field \"%s\".\n",root->child->line, ret->name);
            else printf("Error type 3 at Line %d: Redefined variable \"%s\".\n", root->child->line, ret->name);
            free(ret);
            return NULL;
        }
        ret->type = type;
        ret->next = NULL;
        Value* value = (Value*)malloc(sizeof(Value));
        value->kind = type;
        value->val = ret;
        //if(!funcParamFlag) hashInsert(ret->name, value);
        hashInsert(ret->name, value);

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
            Node* child = root->child;
            int error6 = 0;
            Node* first = child->child;
            if(!first) error6 = 1;
            else{
                if(!first->sibling){
                    //ID
                    if(first->type != ENUM_ID) error6 = 1;
                }
                else{
                    Node* second = first->sibling;
                    if(!second) error6 = 1;
                    else{
                        Node* third = second->sibling;
                        if(!third) error6 = 1;
                        else{
                            Node* fourth = third->sibling;
                            if(fourth){
                                //Exp LB Exp RB
                                if(!(!strcmp(first->data, "Exp") && !strcmp(second->data, "LB") && !strcmp(third->data, "Exp") && !strcmp(fourth->data, "RB"))){
                                    error6 = 1;
                                }

                            }
                            //Exp DOT ID
                            else{
                                if(!(!strcmp(first->data, "Exp") && !strcmp(second->data, "DOT") && third->type == ENUM_ID)){
                                    error6 = 1;
                                }
                            }
                        }
                    }
                }
            }
            if(error6){
                printf("Error type 6 at Line %d: The left-hand side of an assignment must be a variable.\n", child->line);
                return NULL;
            }
            Type* type1 = Exp(child);
            Type* type2 = Exp(child->sibling->sibling);
            if(!type1 || !type2) return NULL;
            if(!typeEqual(type1, type2)){
                printf("Error type 5 at Line %d: Type mismatched for assignment.\n", child->line);
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
                printf("Error type 13 at Line %d: Illegal use of \".\".\n", root->child->line);
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
            printf("Error type 14 at Line %d: Non-existent field \"%s\".\n", root->child->sibling->sibling->line, field);
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
            printf("Error type 7 at Line %d: Operands type mismatched.\n", root->child->sibling->line);
            return NULL;
        }
        return type;
    }

    //NOT Exp
    if(!strcmp(root->child->data, "NOT")){
        Type* type = Exp(root->child->sibling);
        if(!type) return NULL;
        if(type->kind != BASIC || type->u.basic != BASIC_INT){
            printf("Error type 7 at Line %d: Operands type mismatched.\n", root->child->sibling->line);
            return NULL;
        }
        return type;
    }

    if(root->child->type == ENUM_ID){
        char* name = root->child->data;
        //ID
        if(!root->child->sibling){
            Value* value = hashRead(name);
            if(!value && !funcParamFlag){
                printf("Error type 1 at Line %d: Undefined variable \"%s\".\n", root->child->line, name);
                return NULL;
            }
            return value->kind;
        }

        Node* third = root->child->sibling->sibling;
        if(!third) return NULL;

        //ID LP RP
        //ID LP Args RP
        if(!strcmp(root->child->sibling->data, "LP")){
            Value* value = hashRead(name);
            if(!value){
                printf("Error type 2 at Line %d: Undefined function \"%s\".\n", root->child->line, name);
                return NULL;
            }
            if(value->kind->kind != FUNCTION){
                printf("Error type 11 at Line %d: \"%s\" is not a function.\n", root->child->line, root->child->data);
                return NULL;
            }
            if(!strcmp(third->data, "Args")){
                FieldList* arg = Args(third);
                FieldList* arg2 = ((Function*)(value->val))->arg;
                if(!fieldListEqual(arg, arg2)) {
                    printf("Error type 9 at Line %d: Function \"%s\" is not applicable for given arguments.\n",
                           third->line, name);
                    return NULL;
                }
            }
            return ((Function*)(value->val))->returnType;
        }

        assert(0);
        return NULL;

    }

    //INT
    if(root->child->type == ENUM_INT){
        Type* ret = (Type*)malloc(sizeof(Type));
        ret->kind = BASIC;
        ret->u.basic = BASIC_INT;
        return ret;
    }

    //FLOAT
    if(root->child->type == ENUM_FLOAT){
        Type* ret = (Type*)malloc(sizeof(Type));
        ret->kind = BASIC;
        ret->u.basic = BASIC_FLOAT;
        return ret;
    }

    return NULL;
}

FieldList* Args(Node* root){
    if(!root || !root->child) return NULL;
    //Exp
    //Exp COMMA Args
    FieldList* ret = (FieldList*)malloc(sizeof(FieldList));
    ret->type = Exp(root->child);

    if(root->child->sibling){
        ret->next = Args(root->child->sibling->sibling);
    }
    else ret->next = NULL;
    return ret;
}

int typeEqual(Type* type1, Type* type2){
    if(!type1 && !type2) return 1;
    if(!type1 || !type2) return 0;
    if(type1->kind != type2->kind) return 0;
    if(type1->kind == BASIC){
        return type1->u.basic == type2->u.basic;
    }
    if(type1->kind == ARRAY){
        return typeEqual(type1->u.array.elem, type2->u.array.elem);
    }
    if(type1->kind == STRUCTURE){
        return fieldListEqual(type1->u.structure, type2->u.structure);
    }
    return 0;
}

int fieldListEqual(FieldList* f1, FieldList* f2){
    if(!f1 || !f2) return 0;
    while(f1 && f2){
        if(!typeEqual(f1->type, f2->type)) return 0;
        f1 = f1->next;
        f2 = f2->next;
    }
    if(f1 || f2) return 0;
    return 1;
}