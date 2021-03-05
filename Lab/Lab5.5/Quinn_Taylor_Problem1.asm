         .data
         str:  .word  20
         .align    2
         .text

         .globl  main

#Create a function isLowerCase(char c) that is passed a character in $a0 
#and returns, in $v0, a 1 if the character is considered a lowercase 
$value in ASCII (i.e. 'a' is decimal value 97 in ASCII and 'z' is 122) 
#and 0 otherwise. [Pro tip: You already basically did this for the 
#previous lab.]

isLowerCase:
         li    $v0, 1
         b     is_lower_greater

is_lower_greater: #met first 
         addi  $t1, $t1, -97 
         bgezal $t1, is_lower_less #meets lower bound ascii
         b not_lowercase

is_lower_less:
         addi  $t1, $t0, -25
         bgezal   $t1, exit_lower_case #meets lower bound ascii
         b     not_lowercase
         
not_lowercase:
         li    $v0, 0
         b     exit_lower_case

exit_lower_case:
         jr    $ra

#b) Create a function getUpperCase(char c) that is passed a character, 
#in $a0, that is a lowercase value in ASCII and returns, in $v0, the 
#ASCII value for its corresponding uppercase letter. For example for 
#input 0x61 which is 'a', it would return 0x41 to represent 'A'. 
#This function should return 0 if the argument is not a lowercase letter. 
#[Pro tip: You already basically did this for the last lab]

getUpperCase:
         move  $t0, $a0 # load to temporary value
         li    $t1, 0 #default return value
         b     is_greater

is_greater: #met first 
         addi  $t0, $t0, -97 
         bgezal $t0, is_less #meets lower bound ascii
         b exit

is_less:
         addi  $t0, $t0, -25
         bgezal $t0, exit #meets lower bound ascii
         addi  $t1, $v0, -32
         b exit
         
exit:
         move  $v0, $t1
         jr    $ra

#c) Create a function called convertString that takes the address of a 
#string as an argument in $a0. That function should go through all 
#characters in the string and convert any lowercase letters to uppercase 
#letters in place. (This means that the function will modify the contents 
#of the memory addresses storing the string whose address was passed in 
#as an argument.) This function must use the isLowerCase and getUpperCase 
#functions. (Yes, you could only use one of them, but we want you to use 
#both to create more readable code.)

convertString:
         lb    $sp, $a0
         #intialize
         #load first character
         b     recurse_convert
         
recurse_convert:
         #trigger base case
         j     isLowerCase
         bgtz  $a0,  do_the_thing
         #     shift to next character
         b     recurse_convert

do_the_thing: #zhu li
         j     getUpperCase
         #store byte back
         #     shift to next character
         b     recurse_convert


convert_string_break: #if base case reached (no more letters!)
         jr    $ra

# d) In the main function, create a global string called str that 
# initially has space for 20 characters (plus the null terminator). 
# Have the program read in text from the user, storing it into this 
# global string. Then call convertString(), passing it the address of 
# str. Finally, print out the modified str after the function call to 
# convertString() before returning from main.


main:
         li    $v0, 5
         syscall
         lw    str, $v0
         la    $a0, str 

         j     convertString

         #load fixed text into $a0
         li    $v0, 1
         syscall
         jr    $ra
