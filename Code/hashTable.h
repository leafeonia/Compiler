#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "semantic.h"

#define HASH_SIZE 0x3fff
#define DEPTH 64

typedef struct Value_{
    Type* kind;
    int depth; // for 2.2
    void* val;
} Value;

typedef struct Entry_ {
	char* name;
	Value* value;
	struct Entry_* next;
	struct Entry_* prev; // for 2.2, used for delete 
	struct Entry_* crossNext; // for 2.2
} Entry;

Entry* hashtable[HASH_SIZE];
Entry* depthPointers[DEPTH]; // for 2.2
int curDepth;

void hashInit();
unsigned int hash_pjw(char* name);
void hashInsert(char* name, Value* val);
void hashInsertDepth(char* name, Value* val, int depth);
void* hashRead(char* name);
void pushDepth();
void popDepth();
void printTable(); //for debug
