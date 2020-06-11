#include "assemble.h"
#include "ir.h"
#include <stdio.h>
#include "hashTable.h"

extern InterCode* irHead;
FILE* fp;
int offset = -4;
int paramCount = 0;
#define PUSH_SP { offset -= 4; fprintf(fp, "addi $sp, $fp, %d\n", offset);  }

Value* setValOffset(int off){
    Value* value = (Value*)malloc(sizeof(Value));
    value->depth = 0;
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = off;
    value->val = (void*)ptr;
    return value;
}

char* getOpName(Operand* op){
    char* ret;
    if (op->kind == OP_TEMPVAR){
        ret = (char*)malloc(12);
        sprintf(ret, "t%d", op->u.var_no);
    }
    else{
        ret = (char*)malloc(64);
        sprintf(ret, "%s", op->u.value);
    }
    return ret;
}

int getValOffset(Operand* op){
    Value* value = hashRead(getOpName(op));
    assert(value);
    return *(int*)value->val;
}

void printAssemble(FILE* file){
	fp = file;
	fprintf(fp, ".data\n_prompt: .asciiz \"Enter an integer:\"\n_ret: .asciiz \"\\n\"\n.globl main\n.text\nread:\n  li $v0, 4\n  la $a0, _prompt\n  syscall\n  li $v0, 5\n  syscall\n  jr $ra\n\nwrite:\n  li $v0, 1\n  syscall\n  li $v0, 4\n  la $a0, _ret\n  syscall\n  move $v0, $0\n  jr $ra\n");
	hashInit();
	while(irHead){
		irToAssemble(irHead);
		irHead = irHead->next;
	}
}

void irToAssemble(InterCode* ir){
	switch (ir->kind){
		case I_FUNCTION: {
            paramCount = 0;
            offset = -4;
            char *funcName = ir->u.singleOp->u.value;
            if (!strcmp(funcName, "main")) fprintf(fp, "main:\n");
            else fprintf(fp, "f_%s:\n", funcName);

            //save $sp and $fp
            fprintf(fp, "sw $sp, 0($sp)\n");
            fprintf(fp, "addi $sp, $sp, -4\n");
            fprintf(fp, "sw $fp, 0($sp)\n");
            fprintf(fp, "addi $sp, $sp, -4\n");
            fprintf(fp, "sw $ra, 0($sp)\n");
            fprintf(fp, "addi $sp, $sp, -4\n");
            fprintf(fp, "addi $fp, $sp, 12\n");
            offset = -12;
            break;
        }
		case I_PARAM:
		    paramCount++;
		    hashInsert(getOpName(ir->u.singleOp), setValOffset(4 * paramCount));
			break;
		case I_ASSIGN: {
		    Operand* left = ir->u.assign.left;
		    Operand* right = ir->u.assign.right;
		    if (right->kind == OP_NUM){
		        //sp := #0
		        if (left->kind == OP_VALUE && !strcmp(left->u.value, "sp")){
		            fprintf(fp, "li $t8, 0\n");
                    break;
		        }
		        fprintf(fp, "li $t0, %d\n", right->u.var_no);
		        Value* val = hashRead(getOpName(left));
		        if (val){
		            fprintf(fp, "sw $t0, %d($fp)\n", getValOffset(left));
		        }
		        else{
                    hashInsert(getOpName(left), setValOffset(offset));
                    PUSH_SP
		            fprintf(fp, "sw $t0, %d($fp)\n", offset + 4);

		        }
		    }
		    else{
		        // *tAddr := t0
                if (left->kind == OP_DEREF){
                    fprintf(fp, "lw $t0, %d($fp)\n", getValOffset(right));
                    fprintf(fp, "sub $t7, $fp, $t9\n");
                    fprintf(fp, "sw $t0, 0($t7)\n");
                    break;
                }
                // t3 := *tAddr
                if (right->kind == OP_DEREF){
                    hashInsert(getOpName(left), setValOffset(offset));
                    PUSH_SP
                    fprintf(fp, "sub $t7, $fp, $t9\n");
                    fprintf(fp, "lw $t0, 0($t7)\n");
                    fprintf(fp, "sw $t0, %d($fp)\n", getValOffset(left));
                    break;
                }
                Value* value = hashRead(getOpName(right));
                if (!value){
                    hashInsert(getOpName(right), setValOffset(offset));
                    PUSH_SP
                }
		        fprintf(fp, "lw $t0, %d($fp)\n", getValOffset(right));
		        Value* val = hashRead(getOpName(left));
		        if (val){
		            fprintf(fp, "sw $t0, %d($fp)\n", getValOffset(left));
		        }
		        else{
                    hashInsert(getOpName(left), setValOffset(offset));
                    PUSH_SP
                    fprintf(fp, "sw $t0, %d($fp)\n", offset + 4);

		        }
		    }
            break;
        }
		case I_READ:
		    fprintf(fp, "addi $sp, $sp, -4\nsw $ra, 0($sp)\njal read\nlw $ra, 0($sp)\naddi $sp, $sp, 4\n");
		    fprintf(fp, "move $t0, $v0\n");
		    hashInsert(getOpName(ir->u.singleOp), setValOffset(offset));
		    PUSH_SP
		    fprintf(fp, "sw $t0, %d($fp)\n", offset + 4);
			break;
		case I_WRITE:
		    fprintf(fp, "lw $t0, %d($fp)\n", getValOffset(ir->u.singleOp));
		    fprintf(fp, "move $a0, $t0\n");
            fprintf(fp, "addi $sp, $sp, -4\nsw $ra, 0($sp)\njal write\nlw $ra, 0($sp)\naddi $sp, $sp, 4\n");
            break;
		case I_CALL: {
//		    PUSH_SP
            char *funcName = ir->u.assign.right->u.value;
            if (!strcmp(funcName, "main")) fprintf(fp, "jal main\n");
            else fprintf(fp, "jal f_%s\n", ir->u.assign.right->u.value);
            fprintf(fp, "move $t0, $v0\n");
            hashInsert(getOpName(ir->u.assign.left), setValOffset(offset));
            PUSH_SP
            fprintf(fp, "sw $t0, %d($fp)\n", getValOffset(ir->u.assign.left));
            break;
        }
		case I_ARG: {
            fprintf(fp, "lw $t0, %d($fp)\n", getValOffset(ir->u.singleOp));
            fprintf(fp, "sw $t0, 0($sp)\n");
            PUSH_SP
            break;
        }
		case I_RETURN:
		    fprintf(fp, "lw $v0, %d($fp)\n", getValOffset(ir->u.singleOp));

		    //restore $sp and $fp
		    fprintf(fp, "lw $sp, 0($fp)\n");
            fprintf(fp, "lw $ra, -8($fp)\n");
		    fprintf(fp, "lw $fp, -4($fp)\n");

		    fprintf(fp, "jr $ra\n");
			break;
		case I_LABEL:
			fprintf(fp, "label%d:\n", ir->u.singleOp->u.var_no);
			break;
	    case I_GOTO:
	    	fprintf(fp, "j label%d\n", ir->u.singleOp->u.var_no);
	    	break;
	    case I_IFGOTO: {
            fprintf(fp, "lw $t1, %d($fp)\n", getValOffset(ir->u.triop.op1));
            if (ir->u.triop.op2->kind == OP_NUM){
                fprintf(fp, "li $t0, %d\n", ir->u.triop.op2->u.var_no);
            }
            else {
                fprintf(fp, "lw $t0, %d($fp)\n", getValOffset(ir->u.triop.op2));
            }
            char* val = ir->u.triop.relop->u.value;
            if (!strcmp(val, "<")) fprintf(fp, "blt");
            else if (!strcmp(val, ">")) fprintf(fp, "bgt");
            else if (!strcmp(val, "==")) fprintf(fp, "beq");
            else if (!strcmp(val, "!=")) fprintf(fp, "bne");
            else if (!strcmp(val, ">=")) fprintf(fp, "bge");
            else if (!strcmp(val, "<=")) fprintf(fp, "ble");
            fprintf(fp, " $t1, $t0, label%d\n", ir->u.triop.op3->u.var_no);
            break;
        }
	    case I_ADD:{
	    	Operand* result = ir->u.binop.result;
	    	Operand* op1 = ir->u.binop.op1;
	    	Operand* op2 = ir->u.binop.op2;
	    	// sp := sp + t2
	    	if (result->kind == OP_VALUE && !strcmp(result->u.value, "sp")){
	    	    fprintf(fp, "lw $t0, %d($fp)\n", getValOffset(op2));
	    	    fprintf(fp, "add $t8, $t8, $t0\n");
	    	    break;
	    	}
            // tAddr := &v_a + sp
            // use positive number to represent negative one
            // tAddr := -440($fp) + 8
            // $t9 = 440 - 8
            if (op2->kind == OP_VALUE && !strcmp(op2->u.value, "sp")){
                fprintf(fp, "li $t0, %d\n", -getValOffset(op1));
	    	    fprintf(fp, "sub $t9, $t0, $t8\n");
                break;
	    	}
	    	if(op2->kind == OP_NUM){
	    	    fprintf(fp, "lw $t0, %d($fp)\n", getValOffset(op1));
	    		fprintf(fp, "addi $t2, $t0, %d\n", op2->u.var_no);
	    	}
	    	else{
	    	    fprintf(fp, "lw $t1, %d($fp)\n", getValOffset(op1));
                fprintf(fp, "lw $t0, %d($fp)\n", getValOffset(op2));
	    	    fprintf(fp, "add $t2, $t1, $t0\n");
	    	}
            Value* value = hashRead(getOpName(result));
            if (!value){
                hashInsert(getOpName(result), setValOffset(offset));
                PUSH_SP
            }
	    	fprintf(fp, "sw $t2, %d($fp)\n", getValOffset(result));
	    	break;
	    }
	    case I_MINUS: {
            Operand* result = ir->u.binop.result;
            Operand* op1 = ir->u.binop.op1;
            Operand* op2 = ir->u.binop.op2;
            if(op2->kind == OP_NUM){
                fprintf(fp, "lw $t0, %d($fp)\n", getValOffset(op1));
                fprintf(fp, "addi $t2, $t0, %d\n", -op2->u.var_no);
            }
            else{
                if (op1->kind == OP_NUM){
                    fprintf(fp, "li $t1, 0\n");
                }
                else{
                    fprintf(fp, "lw $t1, %d($fp)\n", getValOffset(op1));
                }
                fprintf(fp, "lw $t0, %d($fp)\n", getValOffset(op2));
                fprintf(fp, "sub $t2, $t1, $t0\n");
            }
            Value* value = hashRead(getOpName(result));
            if (!value){
                hashInsert(getOpName(result), setValOffset(offset));
                PUSH_SP
            }
            fprintf(fp, "sw $t2, %d($fp)\n", getValOffset(result));
            break;
        }
	    case I_STAR: {
            Operand *result = ir->u.binop.result;
            Operand *op1 = ir->u.binop.op1;
            Operand *op2 = ir->u.binop.op2;
            if (op2->kind == OP_NUM){
                fprintf(fp, "li $t0, %d\n", op2->u.var_no);
            }
            else {
                fprintf(fp, "lw $t0, %d($fp)\n", getValOffset(op2));
            }
            fprintf(fp, "lw $t1, %d($fp)\n", getValOffset(op1));
            fprintf(fp, "mul $t2, $t1, $t0\n");
            if (!hashRead(getOpName(result))){
                hashInsert(getOpName(result), setValOffset(offset));
                PUSH_SP
            }
            fprintf(fp, "sw $t2, %d($fp)\n", getValOffset(result));
            break;
        }
	    case I_DIV: {
            Operand *result = ir->u.binop.result;
            Operand *op1 = ir->u.binop.op1;
            Operand *op2 = ir->u.binop.op2;
            if (op2->kind == OP_NUM){
                fprintf(fp, "li $t0, %d\n", op2->u.var_no);
            }
            else {
                fprintf(fp, "lw $t0, %d($fp)\n", getValOffset(op2));
            }
            fprintf(fp, "lw $t1, %d($fp)\n", getValOffset(op1));
            fprintf(fp, "div $t1, $t0\n");
            fprintf(fp, "mflo, $t0\n");
            if (!hashRead(getOpName(result))){
                hashInsert(getOpName(result), setValOffset(offset));
                PUSH_SP
            }
            fprintf(fp, "sw $t0, %d($fp)\n", getValOffset(result));
            break;
        }
	    case I_DEC:
	        offset -= ir->u.assign.right->u.var_no;
	        fprintf(fp, "addi $sp, $fp, %d\n", offset);
	        hashInsert(getOpName(ir->u.assign.left), setValOffset(offset));
	        offset -= 4;
	    	break;
	    default:
	    	break;
	}
}


