         .data
         .align    2
x:       .word    5
y:       .word    2
         .text

         .globl  main

main:
         lw $t0, x #load adress
         lw $t1, y # load y adress
         sub $a0, $t0, $t1  # Subtract and prep for print
         li $v0, 1
         syscall
         jr $ra