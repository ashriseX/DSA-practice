//changing strings

#include <iostream>
#include <string>

using namespace std;

int main(){

    string str1;
    str1 = "this is the first String.";

    cout << "String 1: " << str1 << endl;

    str1 += " This is appended text.";
    cout << "After appending text: " << str1 << endl;

    return 0;
    
}