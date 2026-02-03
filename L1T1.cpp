//to find the summation of X^2, where x is starting number and summation is found till last defined number by user

#include <iostream>
using namespace std;

int main(){

    int start, end;
    do{
    cout << "Enter the starting number: " << endl;
    cin >> start;
    cout << "Enter the ending number: " << endl;
    cin >> end;}
    while(end < start);

    int sum = 0;
    for(int i = start; i <= end; i++){
        sum += (i * i);
    }

    cout << "The summation of squares from " << start << " to " << end << " is: " << sum << endl;

    return 0;
}