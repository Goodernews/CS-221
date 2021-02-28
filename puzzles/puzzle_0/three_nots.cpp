#include <iostream> 

using namespace std;

bool x_or(bool x, bool y){
    /*
    Goal: Build XOR with only &&, ||, TRUE, and FALSE
    Notes: The second boolean whould allows be TRUE in practice

    */
   return (x && y && !y) || x && !y;
}

int main(){
    bool a = false;
    bool b = true;
    bool c = false;
    /*
    
    */

    cout << "Input" << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;


    bool work_around_false = not_a && a;
    bool work_around_true = not_a || a;
    /*
    a given boolean and the not of the same boolean always 
    returns false 
    */

   cout << a ||  


    cout << "Output" << endl;

    a = not_a;
    b = x_or(b, work_around_true);
    c = x_or(c, work_around_true);
    /*
    Anything that is ANDed with false flips the bool
    */

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}