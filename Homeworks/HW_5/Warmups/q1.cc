/*
Write a C++ program called q1.cc. 
The program should read three integer values from standard input using cin, 
storing each input into its own integer variable. 
The program should use if/else statements to determine the smallest value entered 
by the user and should print that value to standard output using cout.
*/
#include <iostream> 
using namespace std;

int main(){
    int max_num;
    int holder;

    cout << "Enter a number: " << endl;
    cin>>max_num;

    cout << "\nEnter a number: ";
    cin >> holder;
    if (holder>max_num)
    {
        max_num = holder;
    }

    cout << "Enter a number: " << endl;
    cin >> holder;
    if (holder>max_num)
    {
        max_num = holder;
    }
    


    cout << "The maximum inputted number is: " << max_num << endl;
    cin >> holder;
}
