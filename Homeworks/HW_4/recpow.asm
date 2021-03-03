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
         

pow:
         