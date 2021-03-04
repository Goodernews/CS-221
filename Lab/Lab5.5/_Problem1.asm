         .data
         .align    2
         .text

         .globl  main



#Create a function isLowerCase(char c) that is passed a character in $a0 
#and returns, in $v0, a 1 if the character is considered a lowercase 
$value in ASCII (i.e. 'a' is decimal value 97 in ASCII and 'z' is 122) 
#and 0 otherwise. [Pro tip: You already basically did this for the 
#previous lab.]

isLowerCase:
         



#b) Create a function getUpperCase(char c) that is passed a character, 
#in $a0, that is a lowercase value in ASCII and returns, in $v0, the 
#ASCII value for its corresponding uppercase letter. For example for 
#input 0x61 which is 'a', it would return 0x41 to represent 'A'. 
#This function should return 0 if the argument is not a lowercase letter. 
#[Pro tip: You already basically did this for the last lab]

getUpperCase:



#c) Create a function called convertString that takes the address of a 
#string as an argument in $a0. That function should go through all 
#characters in the string and convert any lowercase letters to uppercase 
#letters in place. (This means that the function will modify the contents 
#of the memory addresses storing the string whose address was passed in 
#as an argument.) This function must use the isLowerCase and getUpperCase 
#functions. (Yes, you could only use one of them, but we want you to use 
#both to create more readable code.)

convertString:
         

# d) In the main function, create a global string called str that 
# initially has space for 20 characters (plus the null terminator). 
# Have the program read in text from the user, storing it into this 
# global string. Then call convertString(), passing it the address of 
# str. Finally, print out the modified str after the function call to 
# convertString() before returning from main.


main:
         