//arrays in c++

#include <iostream>
using namespace std;

int foo [] = {1,2,3,4,5};
int n, result = 0;


int main(){

    for(n = 0; n < 5; n++){
        result += foo[n];
    }
    cout << "The sum of the array elements is: " << result << endl;

    cout << "Enter any five numbers: " << endl;
    int usrArr[5];
    for(n = 0; n < 5; n++){
        cin >> usrArr[n];
    }
    cout << "You entered: ";
    int sum = 0;
    for(n = 0; n < 5; n++){
        cout << usrArr[n] << " ";
        sum += usrArr[n];
    }
    

    return 0;
}