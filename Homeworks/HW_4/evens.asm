#Write a MIPS assembly program called evens.asm. The program should have 
#a global integer array named arr as well as a global integer named size; 
#size should indicate the number of entries in the array. The program should 
#have a helper function named numEvens that takes two arguments: the address 
#of an integer array and the number of elements in the array argument. numEvens 
#should return the number of elements in the array that are even. The main function 
#should call the numEvens method, passing it the address of arr and the value of size, 
#and then print out the number returned by numEvens before returning.



#I owe niels my life

         .data

         arr:  .word 1, 2, 4, 5, 6, 8, 9, 11, 10
         size: .word 0
         .align    2
         .text

         .globl  main

main:
         la    $t0, arr
         lw    $t1, size
         li    $t1, 0
         li    $t4, -1 #holder -1 register
         b     is_even

         

is_even: #recursive even or odd, because there is no god     
         lw    $t3, ($t0) #grab relevant number
         beqz  $t3, end
         andi  $t3 , $t3 , 0x0001 #returns 1 if odd
         mul   $t3, $t3, $t4 #turns even (0) to 0, and odd (1) to -1
         addi  $t3, $t3, 1 #adds 1, turns even (0) to 1, and odd (-1) to 0
         add   $t1, $t3, $t1 #adds the last bit from a given int
         la    $t0, 4($t0) # shift four bits
         b     is_even


end:
         #sw    size, $t1
         move  $a0, $t1
         li    $v0, 1 # prep Print
         syscall #print
         jr    $ra
