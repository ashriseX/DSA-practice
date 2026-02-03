//using while loop to print numbers from 1 to n

#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter a positive integer: " << endl;
    cin >> n;

    int i = 1;
    while(i <= n){
        cout << i;
        if(i % 10 == 0 || i == n){
            cout << endl;
        } else {
            cout << ", ";
        }
        i++;
    }
}