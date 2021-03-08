/*
Write a C++ program called q4.cc. There should be a helper function called 
log that takes two integer parameters, num and base, and returns an integer. 
The log function should iteratively (i.e. use a loop) calculate the logarithm of 
num when base is used as the base and return that value. For the purposes of this question, 
the log function should return the floor of the logarithm for numbers that are not powers of 
the base. For example, the log of 4 base 2 is 2 because 4 is a power of 2 but the floor of the 
log of 6 base 2 is also 2 as the actual log of 6 base 2 is somewhere between 2 and 3. The main 
function should read in two integer values from the user. If either input is negative, the main 
function should print out "Both inputs must be non-negative" and return. If both inputs are positive, 
the main function should call log, specifying the first user input as the first argument (i.e. num) 
and the second user input as the second argument (i.e. base). The main function should then print 
the result returned by log before returning.
*/

