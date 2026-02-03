//primitive datatypes

#include <iostream>
using namespace std;

int main(){

    int myNum = 5;               // Integer (whole number)
    float myFloatNum = 5.99;    // Floating point number
    double myDoubleNum = 9.98;  // Double precision floating point number
    char myLetter = 'D';        // Character
    bool myBoolean = true;      // Boolean
    string myText = "Hello";    // String

    cout << "Integer: " << myNum << endl;
    cout << "Float: " << myFloatNum << endl;
    cout << "Double: " << myDoubleNum << endl;
    cout << "Character: " << myLetter << endl;
    cout << "Boolean: " << myBoolean << endl;
    cout << "String: " << myText << endl;

    cout << (myNum + myFloatNum) << endl;
    
    cout << (myDoubleNum / 2) << endl;

    return 0;
}