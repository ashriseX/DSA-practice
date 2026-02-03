//get the user input

#include <iostream>
using namespace std;

int main(){

    string name;
    cout << "Enter your name" << endl;
    getline(cin, name);

    cout << "enter your age in integers" << endl;
    int age;
    cin >> age;

    cout << "Hello " << name << ", you are " << age << " years old." << endl;
    return 0;
}
