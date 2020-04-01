#include "semantic.h"
#include "hashTable.h"
#include <string.h>


void Program(Node* root){
	if(!root) return;
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
		CompSt(second->sibling, type);
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

}

void FunDec(Node* root, Type* type){

}

void CompSt(Node* root, Type* type){

}

FieldList* DefList(Node* root){
	if(!root || !root->child) return NULL;
	FieldList* ret = Def(root->child);
	FieldList* tail = ret;
	while(tail->next){
		tail = tail->next;
	}
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
	if(!root->child->sibling) return ret;
	ret->next = DecList(root->child->sibling->sibling);
	return ret;
}

FieldList* Dec(Node* root, Type* type){
	
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
