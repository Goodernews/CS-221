         .data
         .align    2
         .text

         .globl  main

main:
         # get first val
         li $v0, 5
         syscall
         move $t0, $v0 #move input to temp
         li $v0, 5
         syscall
         move $t1, $v0 #move input to temp
         bgt $t0, $t1, first_larger # if greater than load to be printed
         b second_larger

first_larger:
         move $t3, $t0
         b exit

second_larger:
         move $t3, $t1
         b exit

exit:
         move $a0, $t3
         li $v0, 1 # prep Print
         syscall
         jr $ra