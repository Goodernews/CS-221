#Write a MIPS assembly program called count.asm. The program should 
#have a global string called str. The user should enter a character c. 
#The program should have a helper function called countOccurrences that takes two arguments: 
#the address of a string and a character. The countOccurrences function 
#should return the number of times the character argument occurs in the string 
#passed in as an argument. The main function should call the countOccurrences function, 
#passing it the address of str and the character c, and then print out the value returned 
#by countOccurrences before returning from main.



         .data
         .align    2
         .text

         .globl  main

main:
         