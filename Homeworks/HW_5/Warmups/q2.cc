/*
Write a C++ program called q2.cc. There should be a helper function called 
isMultiple which takes two integer parameters and returns a bool. isMultiple 
should return true when the first argument is a multiple of the second argument 
and return false in all other cases. The main function should read in an integer 
from the user using cin and store it in an integer variable, called num. The main function 
should use a loop to read in 10 integers from the user using cin. For each number read in, the 
loop iteration should call the isMultiple function to determine if the number just read in from 
the user is a multiple of the value stored in num. The main function should then print out to standard 
output using cout how many of the 10 numbers were multiples of num. (Do not use any data structures 
that store multiple values such as lists or arrays.)
*/

#include <iostream> 
using namespace std;

int isMultiple(int x, int y){
    if(x%y==0){
        return true;
    }

    return false;
}

int main(){
    int num;
    cin>>num;
    cout << isMultiple(num, num)<< endl;

}