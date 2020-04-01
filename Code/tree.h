#ifndef TREE_H
#define TREE_H

#define LEN_DATA 64

typedef struct Node{
	struct Node* child;
	struct Node* sibling;
	int line, type;
	char data[LEN_DATA];
}Node;

enum nodeType{
	NONTERMINAL, ENUM_TYPE, OCT, HEX, ENUM_INT, ENUM_FLOAT, ENUM_ID, TERMINAL
};

Node* root;

Node* initNode(int type, char* data, int line);
void insert(Node* parent, Node* child);
void preOrder(Node* current, int depth);
void printTree();
void clear();
void setError(int val); 
int getErrorFlag();
void semanticAnalysis();

#endif
