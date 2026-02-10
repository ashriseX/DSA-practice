#include <iostream>
using namespace std;

int main(){

    int temperatures[] = {16, 19, 22, 22, 23, 20, 21};

    int *tempPtr = &temperatures[0];
    int avgTemp = 0;
    int i = 0;

    cout << "The temperatures throughout the week are: " << endl;

    while(i < 7){
        cout << *tempPtr << " ";
        avgTemp += *tempPtr;
        tempPtr++;
        i++;
    }
    cout << endl;
    avgTemp /= i;

    cout << " The average temperature fotr the week is: " << avgTemp << " degree Celsius." << endl;

    return 0;

    
}