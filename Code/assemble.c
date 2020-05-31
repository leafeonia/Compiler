#include "assemble.h"
#include <stdio.h>

extern InterCode* irHead;
FILE* fp;
char* regs[] = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};
int index = 0;

void printAssemble(FILE* file){
	fp = file;
	fprintf(fp, ".data\n_prompt: .asciiz \"Enter an integer:\"\n_ret: .asciiz \"\\n\"\n.globl main\n.text\nread:\n  li $v0, 4\n  la $a0, _prompt\n  syscall\n  li $v0, 5\n  syscall\n  jr $ra\n\nwrite:\n  li $v0, 1\n  syscall\n  li $v0, 4\n  la $a0, _ret\n  syscall\n  move $v0, $0\n  jr $ra\n");
	while(irHead){
		irToAssemble(irHead);
		irHead = irHead->next;
	}
}

char* getReg(Operand* op){
	return regs[(index++) % 10];
}

void irToAssemble(InterCode* ir){
	switch (ir->kind){
		case I_FUNCTION:
			break;
		case I_PARAM:
			break;
		case I_ASSIGN:
			break;
		case I_READ:
			break;
		case I_WRITE:
			break;
		case I_CALL:
			break;
		case I_ARG:
			break;
		case I_RETURN:
			break;
		case I_LABEL:
			fprintf(fp, "label%d:\n", ir->u.singleOp->u.var_no);
			break;
	    case I_GOTO:
	    	fprintf(fp, "j label%d\n", ir->u.singleOp->u.var_no);
	    	break;
	    case I_IFGOTO:
	    	break;
	    case I_ADD:{
	    	Operand* result = ir->u.binop.result;
	    	Operand* op1 = ir->u.binop.op1;
	    	Operand* op2 = ir->u.binop.op2;
	    	if(ir->u.binop.op2->kind == OP_NUM){
	    		fprintf(fp, "addi %s, %s, %d\n", getReg(result), getReg(op1), op2->u.var_no);
	    	}
	    	break;
	    }
	    case I_MINUS:
	    	break;
	    case I_STAR:
	    	break;
	    case I_DIV:
	    	break;
	    case I_DEC:
	    	break;
	    default:
	    	break;
	}
}


