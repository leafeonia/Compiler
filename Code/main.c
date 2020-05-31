#include <stdio.h>
#include "tree.h"
#include "semantic.h"
#include "assemble.h"

int main(int argc, char** argv){
	if(argc <= 1) return 1;
	FILE* f = fopen(argv[1], "r");
	if(!f){
		perror(argv[1]);
		return 1;
	}
	FILE* assembleFile = fopen(argv[2], "w");
	if(!assembleFile){
		perror(argv[2]);
		return 1;
	}
	yyrestart(f);
	yyparse();
	//printTree();
	semanticAnalysis();
	irGenerate(NULL);
	printAssemble(assembleFile);
	clear();
	return 0;
}
