#include "semantic.h"
#include "hashTable.h"

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
