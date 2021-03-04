#Write a MIPS assembly program called recpow.asm that contains two functions: 
#main and pow.

#pow takes two arguments in $a0 and $a1, and computes in $v0 their 
#exponentiation: $a0$a1. This is very similar to the pow example we 
#saw in class, except the function must be recursive and must not use 
#any explicit loops.

#main takes two numbers (unsigned integers) from the user and passes 
#them to pow, then prints the result of the computation.

         .data
         .align    2
         .text

         .globl  main


main:
         li    $t0, 1 #Register that holds the value 1 for comaprison 
         li    $v0, 5 #Get val
         syscall
         move  $a0, $v0 #load first int from user
         move  $t1, $a0 # Holder for original number
         li    $v0, 5 #Get val
         syscall
         move  $a1, $v0 #load first int from user
         beqz  $a1, exponent_zero #if exponent 0
         j     pow

         
exponent_zero: #return one if exponent zero
         move $a0, $t0
         j     end
pow:
         beq   $t0, $a1, end  #If exponent 1, then return
         mul   $a0, $a0, $t1  #
         addi  $a1, -1
         j     pow   

end:
         li $v0, 1 # prep Print
         syscall #print
         jr    $ra #return