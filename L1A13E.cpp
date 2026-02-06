//simple pointer variabe
#include <iostream>
using namespace std;

int main(){
    cout << "Enter ta value for a variable:" << endl;
    int num1;
    cin >> num1;

    int *numPtr;


    
    cout << numPtr << " is the memory address of the " << num1 << " variable" << endl;

    int num2 = 2237;
    int *num2Ptr;

    cout << num2Ptr << " is the pointer of the variable num2" << num2 << endl;
    num2Ptr++;
    cout << num2Ptr << " and " << *num2Ptr << endl;

}