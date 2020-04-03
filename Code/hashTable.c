#include "hashTable.h"

void hashInit(){
	for(int i = 0;i < HASH_SIZE;i++){
		hashtable[i] = NULL;
	}
	for(int i = 0;i < DEPTH;i++){
		depthPointers[i] = NULL;
	}
	curDepth = 0;
}

unsigned int hash_pjw(char* name){
	unsigned int val = 0, i;
	for (; *name; ++name){
		val = (val<< 2) + *name;  
		if (i = val& ~HASH_SIZE) val = (val ^ (i>> 12)) & HASH_SIZE;
	}
	return val % HASH_SIZE;
}

void hashInsert(char* name, void* val){
	hashInsertDepth(name, val, curDepth);
}

void hashInsertDepth(char* name, void* val, int depth) {
	unsigned int hash = hash_pjw(name) % HASH_SIZE; 
	Entry* entry = (Entry*)malloc(sizeof(Entry));
	entry->name = name;
	entry->value = val;
	entry->next = !hashtable[hash] ? NULL : hashtable[hash];
	entry->crossNext = !depthPointers[curDepth] ? NULL : depthPointers[depth];
	entry->prev = NULL;
	if(hashtable[hash]) hashtable[hash]->prev = entry;
	hashtable[hash] = entry;
	depthPointers[depth] = entry;
}

void* hashRead(char* name){
	unsigned int hash = hash_pjw(name) % HASH_SIZE;
	Entry* entry = hashtable[hash];
	while(entry){
		if(strcmp(entry->name, name) == 0){
			return entry->value;
		}
		entry = entry->next;
	}
	return NULL;
}

void pushDepth(){
	curDepth++;
}

void popDepth(){
	if(curDepth == 0) return; //bottom
	Entry* entry = depthPointers[curDepth];
	while(entry){
		Entry* del = entry;
		entry = entry->crossNext;
		if(del->prev){
			del->prev->next = del->next;
		}
		else{
			hashtable[hash_pjw(del->name)] = del->next;  
		}
		if(del->next){
			del->next->prev = del->prev;
		}
		free(del);
	}
	curDepth--;
}

void printTable(){ //for debug
	for(int i = 0;i < HASH_SIZE;i++){
		if(hashtable[i]){
			printf("| %4d | : ", i);
			Entry* entry = hashtable[i];
			while(entry){
				printf(" -> %s ", entry->name);
				entry = entry->next;
			}
			printf("\n");
		}
		
	}
	printf("\n");
}
