#Write a MIPS assembly program called bitsset.asm that contains two functions: bitsset and main.

#bitsset takes one integer (word) argument in $a0 and computes in $v0 how many bits in
#the binary representation of the word are set to 1. For example, for the input 17,
#it'll return 2 (the only two set bits are 24 and 20). For the input 7 it'll return 3.
#The function must be recursive and must not use any explicit loops. 
#Hint: you may use bitwise operators like AND and shift.

#main takes one number (integer) from the user and passes it to bitsset,
#and then prints the result of the computation.

         .data
         .align    2
         .text

         .globl  main


main:
         li    $v0, 5 #Get val
         syscall
         move  $t0, $v0
         li    #t2, 0 #number bits seen
         


bitset:
         #break condition
         andi  $t1, $t0, 0x0001
         add   $t2, $t1
         sra   $t0, $t0, 4
end:
         move  $a0, $t2
         li    $v0, 1
         syscall
