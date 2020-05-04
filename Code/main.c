#include <stdio.h>
#include "tree.h"
#include "semantic.h"

int main(int argc, char** argv){
	if(argc <= 1) return 1;
	FILE* f = fopen(argv[1], "r");
	if(!f){
		perror(argv[1]);
		return 1;
	}
	FILE* irFile = fopen(argv[2], "w");
	if(!irFile){
		perror(argv[2]);
		return 1;
	}
	yyrestart(f);
	yyparse();
	//printTree();
	semanticAnalysis();
	irGenerate(irFile);
	clear();
	return 0;
}
