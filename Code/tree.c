#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include "semantic.h"
#include "ir.h"

int errorFlag = 0; //0: no error  1: lex error  2: syntax error
int endLine = 1;

Node* initNode(int type, char* data, int line){
	Node* node = (Node*)malloc(sizeof(Node));
	node->child = node->sibling = NULL;
	node->type = type;
	strcpy(node->data, data);
	node->line = line;
}

void insert(Node* parent, Node* child){
	if(!parent){
		root = child;
		return;
	}
	if(!child){
		return;
	}
	if(!parent->child){
		parent->child = child;
		return;
	}
	Node* temp = parent->child;
	while(temp->sibling){
		temp = temp->sibling;
	}
	temp->sibling = child;
}

void preOrder(Node* current, int depth){
	if(!current) {
		return;
	}
	for(int i = 0;i < 2*depth;i++){
		printf(" ");
	}
	switch (current->type){
		case NONTERMINAL:
			printf("%s (%d)\n", current->data, current->line);
			break;
		case TERMINAL:
			printf("%s\n", current->data);
			break;
		case ENUM_FLOAT:
			printf("FLOAT: %f\n", strtof(current->data, NULL));
			break;
		case ENUM_INT:
			printf("INT: %d\n", atoi(current->data));
			break;
		case OCT:
			printf("INT: %d\n", (int)strtol(current->data, NULL, 8));
			break;
		case HEX:
			printf("INT: %d\n", (int)strtol(current->data, NULL, 16));
			break;
		case ENUM_TYPE:
			printf("TYPE: %s\n", current->data);
			break;
		case ENUM_ID:
			printf("ID: %s\n", current->data);
			break;
		default:
			break;
	}
	preOrder(current->child, depth+1);
	preOrder(current->sibling, depth);
	
}

void printTree(){
	if(!errorFlag){
		if(!(root->child)) printf("Program (%d)\n", endLine);
		else preOrder(root, 0);
	}
}

void setError(int val){
	errorFlag = val;
}

int getErrorFlag(){
	return errorFlag;
}

void doClear(Node* current){
	if(!current){
		return;
	}
	doClear(current->child);
	doClear(current->sibling);
	free(current);
}

void clear(){
	doClear(root);
}

void semanticAnalysis(){
	Program(root);
}

void irGenerate(FILE* fp){
	irProgram(root);
	if(fp) irPrintCode(fp);
}

