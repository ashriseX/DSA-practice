#include <iostream>
using namespace std;

int addition(int a, int b){
    int sum = a + b;
    return sum;
}

int main(){
    int num1, num2;

    cout<< "Enter two numbers: " << endl;
    cin >> num1 >> num2;

    int result = addition(num1, num2);

    cout << "The sum of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
    
}