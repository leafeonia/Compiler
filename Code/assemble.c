#include "assemble.h"
#include "ir.h"
#include <stdio.h>

extern InterCode* irHead;
FILE* fp;
char* regs[] = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};
int idx = 0;

void printAssemble(FILE* file){
	fp = file;
	fprintf(fp, ".data\n_prompt: .asciiz \"Enter an integer:\"\n_ret: .asciiz \"\\n\"\n.globl main\n.text\nread:\n  li $v0, 4\n  la $a0, _prompt\n  syscall\n  li $v0, 5\n  syscall\n  jr $ra\n\nwrite:\n  li $v0, 1\n  syscall\n  li $v0, 4\n  la $a0, _ret\n  syscall\n  move $v0, $0\n  jr $ra\n");
	while(irHead){
		irToAssemble(irHead);
		irHead = irHead->next;
	}
}

char* getReg(Operand* op){
	return regs[(idx++) % 10];
}

void irToAssemble(InterCode* ir){
	switch (ir->kind){
		case I_FUNCTION:
			break;
		case I_PARAM:
			break;
		case I_ASSIGN: {
		    Operand* left = ir->u.assign.left;
		    Operand* right = ir->u.assign.right;
		    if (right->kind == OP_NUM){
		        fprintf(fp, "li %s %d\n", getReg(left), right->u.var_no);
		    }
		    else{
		        fprintf(fp, "move %s %s\n", getReg(left), getReg(right));
		    }
            break;
        }
		case I_READ:
		    fprintf(fp, "addi $sp $sp -4\nsw $ra, 0($sp)\njal read\nlw $ra, 0($sp)\naddi $sp, $sp, 4\n");
		    fprintf(fp, "move %s $v0\n", getReg(ir->u.singleOp));
			break;
		case I_WRITE:
		    fprintf(fp, "move $a0 %s\n", getReg(ir->u.singleOp));
            fprintf(fp, "addi $sp $sp -4\nsw $ra, 0($sp)\njal write\nlw $ra, 0($sp)\naddi $sp, $sp, 4\n");
            break;
		case I_CALL:
		    fprintf(fp, "jal %s\n", ir->u.assign.right->u.value);
		    fprintf(fp, "move %s $v0\n", getReg(ir->u.assign.left));
			break;
		case I_ARG:
			break;
		case I_RETURN:
		    fprintf(fp, "move $v0, %s\n", getReg(ir->u.singleOp));
		    fprintf(fp, "jr $ra\n");
			break;
		case I_LABEL:
			fprintf(fp, "label%d:\n", ir->u.singleOp->u.var_no);
			break;
	    case I_GOTO:
	    	fprintf(fp, "j label%d\n", ir->u.singleOp->u.var_no);
	    	break;
	    case I_IFGOTO: {
            char* val = ir->u.triop.relop->u.value;
            if (!strcmp(val, "<")) fprintf(fp, "blt");
            else if (!strcmp(val, ">")) fprintf(fp, "bgt");
            else if (!strcmp(val, "==")) fprintf(fp, "beq");
            else if (!strcmp(val, "!=")) fprintf(fp, "bne");
            else if (!strcmp(val, ">=")) fprintf(fp, "bge");
            else if (!strcmp(val, "<=")) fprintf(fp, "ble");
            fprintf(fp, " %s %s label%d\n", getReg(ir->u.triop.op1), getReg(ir->u.triop.op2), ir->u.triop.op3->u.var_no);
            break;
        }
	    case I_ADD:{
	    	Operand* result = ir->u.binop.result;
	    	Operand* op1 = ir->u.binop.op1;
	    	Operand* op2 = ir->u.binop.op2;
	    	if(ir->u.binop.op2->kind == OP_NUM){
	    		fprintf(fp, "addi %s, %s, %d\n", getReg(result), getReg(op1), op2->u.var_no);
	    	}
	    	else{
	    	    fprintf(fp, "add %s, %s, %s\n", getReg(result), getReg(op1), getReg(op2));
	    	}
	    	break;
	    }
	    case I_MINUS: {
            Operand *result = ir->u.binop.result;
            Operand *op1 = ir->u.binop.op1;
            Operand *op2 = ir->u.binop.op2;
            if (ir->u.binop.op2->kind == OP_NUM) {
                fprintf(fp, "addi %s, %s, %d\n", getReg(result), getReg(op1), -op2->u.var_no);
            } else {
                fprintf(fp, "sub %s, %s, %s\n", getReg(result), getReg(op1), getReg(op2));
            }
            break;
        }
	    case I_STAR:
	        fprintf(fp, "mul %s, %s, %s\n", getReg(ir->u.binop.result), getReg(ir->u.binop.op1), getReg(ir->u.binop.op2));
	    	break;
	    case I_DIV:
            fprintf(fp, "div %s, %s\n", getReg(ir->u.binop.op1), getReg(ir->u.binop.op2));
            fprintf(fp, "mflo, %s\n", getReg(ir->u.binop.result));
	    	break;
	    case I_DEC:
	        fprintf(fp, "TODO DEC\n");
	    	break;
	    default:
	    	break;
	}
}


