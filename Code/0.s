.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
  li $v0, 4
  la $a0, _prompt
  syscall
  li $v0, 5
  syscall
  jr $ra

write:
  li $v0, 1
  syscall
  li $v0, 4
  la $a0, _ret
  syscall
  move $v0, $0
  jr $ra
f_add:
sw $sp, 0($sp)
addi $sp, $sp, -4
sw $fp, 0($sp)
addi $sp, $sp, -4
move $fp, $sp
sw $ra, 0($sp)
lw $t0, 16($fp)
sw $t0, -12($fp)
addi $sp, $sp, -4
lw $t0, 20($fp)
sw $t0, -16($fp)
addi $sp, $sp, -4
lw $t1, -12($fp)
lw $t0, -16($fp)
add $t2, $t1, $t0
addi $sp, $sp, -4
sw $t2, -20($fp)
lw $t0, 24($fp)
sw $t0, -24($fp)
addi $sp, $sp, -4
lw $t1, -20($fp)
lw $t0, -24($fp)
add $t2, $t1, $t0
addi $sp, $sp, -4
sw $t2, -28($fp)
lw $t0, 28($fp)
sw $t0, -32($fp)
addi $sp, $sp, -4
lw $t1, -28($fp)
lw $t0, -32($fp)
add $t2, $t1, $t0
addi $sp, $sp, -4
sw $t2, -36($fp)
lw $t0, 32($fp)
sw $t0, -40($fp)
addi $sp, $sp, -4
lw $t1, -36($fp)
lw $t0, -40($fp)
add $t2, $t1, $t0
addi $sp, $sp, -4
sw $t2, -44($fp)
lw $t0, -44($fp)
sw $t0, -48($fp)
addi $sp, $sp, -4
lw $t0, -48($fp)
sw $t0, -52($fp)
addi $sp, $sp, -4
lw $t0, -52($fp)
move $a0, $t0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
li $t0, 0
sw $t0, -56($fp)
addi $sp, $sp, -4
lw $v0, -56($fp)
lw $sp, 8($fp)
lw $ra, 0($fp)
lw $fp, 4($fp)
jr $ra
main:
sw $sp, 0($sp)
addi $sp, $sp, -4
sw $fp, 0($sp)
addi $sp, $sp, -4
move $fp, $sp
sw $ra, 0($sp)
TODO DEC
li $t0, 0
sw $t0, -12($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -16($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -20($fp)
addi $sp, $sp, -4
li $t0, #4
lw $t1, -20($fp)
addi $sp, $sp, -4
mul $t2, $t1, $t0
sw $t2, -24($fp)
lw $t1, -16($fp)
lw $t0, -24($fp)
add $t2, $t1, $t0
sw $t2, -16($fp)
lw $t1, 16($fp)
lw $t0, -16($fp)
add $t2, $t1, $t0
addi $sp, $sp, -4
sw $t2, -28($fp)
lw $t0, -12($fp)
sw $t0, -32($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -36($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -16($fp)
li $t0, 1
sw $t0, -40($fp)
addi $sp, $sp, -4
li $t0, #4
lw $t1, -40($fp)
addi $sp, $sp, -4
mul $t2, $t1, $t0
sw $t2, -44($fp)
lw $t1, -16($fp)
lw $t0, -44($fp)
add $t2, $t1, $t0
sw $t2, -16($fp)
lw $t1, 16($fp)
lw $t0, -16($fp)
add $t2, $t1, $t0
sw $t2, -28($fp)
lw $t0, -36($fp)
sw $t0, -32($fp)
li $t0, 2
sw $t0, -48($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -16($fp)
li $t0, 2
sw $t0, -52($fp)
addi $sp, $sp, -4
li $t0, #4
lw $t1, -52($fp)
addi $sp, $sp, -4
mul $t2, $t1, $t0
sw $t2, -56($fp)
lw $t1, -16($fp)
lw $t0, -56($fp)
add $t2, $t1, $t0
sw $t2, -16($fp)
lw $t1, 16($fp)
lw $t0, -16($fp)
add $t2, $t1, $t0
sw $t2, -28($fp)
lw $t0, -48($fp)
sw $t0, -32($fp)
li $t0, 3
sw $t0, -60($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -16($fp)
li $t0, 3
sw $t0, -64($fp)
addi $sp, $sp, -4
li $t0, #4
lw $t1, -64($fp)
addi $sp, $sp, -4
mul $t2, $t1, $t0
sw $t2, -68($fp)
lw $t1, -16($fp)
lw $t0, -68($fp)
add $t2, $t1, $t0
sw $t2, -16($fp)
lw $t1, 16($fp)
lw $t0, -16($fp)
add $t2, $t1, $t0
sw $t2, -28($fp)
lw $t0, -60($fp)
sw $t0, -32($fp)
li $t0, 4
sw $t0, -72($fp)
addi $sp, $sp, -4
lw $t0, -72($fp)
sw $t0, 20($fp)
li $t0, 0
sw $t0, -16($fp)
li $t0, 0
sw $t0, -76($fp)
addi $sp, $sp, -4
li $t0, #4
lw $t1, -76($fp)
addi $sp, $sp, -4
mul $t2, $t1, $t0
sw $t2, -80($fp)
lw $t1, -16($fp)
lw $t0, -80($fp)
add $t2, $t1, $t0
sw $t2, -16($fp)
lw $t1, 16($fp)
lw $t0, -16($fp)
add $t2, $t1, $t0
sw $t2, -28($fp)
lw $t0, -28($fp)
sw $t0, -84($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -16($fp)
li $t0, 1
sw $t0, -88($fp)
addi $sp, $sp, -4
li $t0, #4
lw $t1, -88($fp)
addi $sp, $sp, -4
mul $t2, $t1, $t0
sw $t2, -92($fp)
lw $t1, -16($fp)
lw $t0, -92($fp)
add $t2, $t1, $t0
sw $t2, -16($fp)
lw $t1, 16($fp)
lw $t0, -16($fp)
add $t2, $t1, $t0
sw $t2, -28($fp)
lw $t0, -28($fp)
sw $t0, -96($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -16($fp)
li $t0, 2
sw $t0, -100($fp)
addi $sp, $sp, -4
li $t0, #4
lw $t1, -100($fp)
addi $sp, $sp, -4
mul $t2, $t1, $t0
sw $t2, -104($fp)
lw $t1, -16($fp)
lw $t0, -104($fp)
add $t2, $t1, $t0
sw $t2, -16($fp)
lw $t1, 16($fp)
lw $t0, -16($fp)
add $t2, $t1, $t0
sw $t2, -28($fp)
lw $t0, -28($fp)
sw $t0, -108($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -16($fp)
li $t0, 3
sw $t0, -112($fp)
addi $sp, $sp, -4
li $t0, #4
lw $t1, -112($fp)
addi $sp, $sp, -4
mul $t2, $t1, $t0
sw $t2, -116($fp)
lw $t1, -16($fp)
lw $t0, -116($fp)
add $t2, $t1, $t0
sw $t2, -16($fp)
lw $t1, 16($fp)
lw $t0, -16($fp)
add $t2, $t1, $t0
sw $t2, -28($fp)
lw $t0, -28($fp)
sw $t0, -120($fp)
addi $sp, $sp, -4
lw $t0, 20($fp)
sw $t0, -124($fp)
addi $sp, $sp, -4
lw $t0, -124($fp)
sw $t0, 0($sp)
addi $sp, $sp, -4
lw $t0, -120($fp)
sw $t0, 0($sp)
addi $sp, $sp, -4
lw $t0, -108($fp)
sw $t0, 0($sp)
addi $sp, $sp, -4
lw $t0, -96($fp)
sw $t0, 0($sp)
addi $sp, $sp, -4
lw $t0, -84($fp)
sw $t0, 0($sp)
addi $sp, $sp, -4
addi $sp, $sp, -4
jal f_add
move $t0, $v0
addi $sp, $sp, -4
sw $t0, -152($fp)
li $t0, 0
sw $t0, -156($fp)
addi $sp, $sp, -4
lw $v0, -156($fp)
lw $sp, 8($fp)
lw $ra, 0($fp)
lw $fp, 4($fp)
jr $ra
