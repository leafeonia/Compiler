#include <stdio.h>
#include "ir.h"

void printAssemble(FILE* fp);
void irToAssemble(InterCode* ir);
char* getReg(Operand* op);
