#Write a MIPS assembly program called count.asm. The program should 
#have a global string called str. The user should enter a character c. 
#The program should have a helper function called countOccurrences that takes two arguments: 
#the address of a string and a character. The countOccurrences function 
#should return the number of times the character argument occurs in the string 
#passed in as an argument. The main function should call the countOccurrences function, 
#passing it the address of str and the character c, and then print out the value returned 
#by countOccurrences before returning from main.



         .data
         str:  .word Nice name nerds
         

         .align    2
         .text

         .globl  main



main:
         la    $a0, str
         li    $v0, 5 #Get val
         syscall
         move  $a1, $v0 #load char from user
         li    $t0, 0 # intialize counted zero occurnce
         b     countOccurrences
         

countOccurrences:
         lw    $t1, ($t0)
         beqz  $t1, end
         beq   


char_match:

end:
         jr    $ra