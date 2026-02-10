#include <iostream>
using namespace std;

int main(){

    int num;
    cout << "Enter a value in integers: " << endl;
    cin >> num;

    int *numPtr = &num;
    //to print the address of the num and its value
    cout << num << " is the value given by user and it has the address " << numPtr << endl;

    *numPtr += 2;
    cout << *numPtr << " is the value updated by pointer and it has the address " << numPtr << " without accessing the original num variable ie  " << num << endl;


    return 0;

}