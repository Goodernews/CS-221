#include <iostream>

using namespace std;

int main(){
    int a = 0;
    int b = 1;
    int c = 1;

    if (a==b && b==c){
        cout << 0 << endl;
        return 0;
    }

    if (a!=b && b!=c && a!=c){
        cout << 0 << endl;
        return 0;
    }
    cout << 1 << endl;
    return 1;

}