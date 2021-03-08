/*
Write a C++ program called q3.cc. There should be a helper function called pow that 
takes two integer parameters, base and exponent, and returns an integer. The pow function 
should calculate baseexponent recursively and return that value. The main function should 
read in two integer values from the user. If either input is less than 1, the main function 
should print out "Both inputs must be positive" and return. If both inputs are positive, the 
main function should call pow, specifying the first user input as the first argument (i.e. base) 
and the second user input as the second argument (i.e. exponent). The main function should then 
print the result returned by pow before returning.
*/

#include <iostream> 
using namespace std;

int pow(int x, int y, int z=0){
    if(z==0){
        z=x;
    }
    if(y=0){
        return 1;
    }
    if(y=1){
        return x;
    }
    return pow(x*z, y-1, z);
}

int main(){
    int base;
    int exponent;
    cout <<"Enter base number: " << endl;
    cin >> base;
    cout <<"Enter exponent number: " << endl;
    cin >> exponent;
    
    if(base<1, exponent<1){
        cout << "Both inputs must be positive" << endl;
    }

    else{
    cout << "Output is: " << pow(base,exponent) << endl;
    }

}