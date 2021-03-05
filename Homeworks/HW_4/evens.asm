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

         arr:  .word 1, 2, 4, 5, 6, 8, 10
         size: .word 0
         .align    2
         .text

         .globl  main

main:
         la    $t0, arr
         la    $t1, size
         li    $t1, 0
         b     is_even

         

is_even: #recursive even or odd, because there is no god
         lw    $t3, ($t0) #grab relevant number
         not   $t3, $t3 #Bit hacking curtesy of Neils
         and   $t3, $t3, $t3 #Bit hacking curtesy of Neils
         #addi  $t3, 1 #if negative 1, then branch end
         #beqz  $t3, end
         #addi  $t3, 2 #adds 2 to counteract for the fact that -2 means even
         add   $t1, $t3, $t1 #adds the last bit from a given int
         la    $t0, 4($t0) # shift four bits
         b     is_even


end:
         #sw    size, $t1
         jr    $ra
