#Write a MIPS assembly program called evens.asm. The program should have 
#a global integer array named arr as well as a global integer named size; 
#size should indicate the number of entries in the array. The program should 
#have a helper function named numEvens that takes two arguments: the address 
#of an integer array and the number of elements in the array argument. numEvens 
#should return the number of elements in the array that are even. The main function 
#should call the numEvens method, passing it the address of arr and the value of size, 
#and then print out the number returned by numEvens before returning.

         .data
         .align    2
         .text

         .globl  main

main:
         