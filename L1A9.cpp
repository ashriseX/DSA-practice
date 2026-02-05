//using do while loop in c++

#include <iostream>
#include <string>
using namespace std;

int main(){

    string str1;

    do {
        cout << "Enter a non-empty string and goodbye to exit: " << endl;
        getline(cin, str1);
        cout << "you entered: " << str1 << endl;
    } 
    while (str1 != "goodbye");
    
    cout << "Goodbye!" << endl;
    return 0;
    


}