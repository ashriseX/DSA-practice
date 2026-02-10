// pointers practice

#include <iostream>
using namespace std;

int main(){

    string str1 = "Abdul Saboor Hasan";
    string *strPtr = &str1;

    cout << strPtr << " and the data stored at this location is :  " << *strPtr << endl;
    string** str2Ptr = &strPtr;

    cout << str2Ptr << endl;
   
    cout << *str2Ptr;

    bool voteEligible = 1;
    bool *boolPtr = &voteEligible;

    cout << boolPtr << " and " << *boolPtr << endl;

    int a = 4;
    int * intPtr = &a;
    cout << intPtr << endl;
    cout << *(intPtr++) << endl;
    cout << *(++intPtr) << endl;
    cout << *(--(--intPtr)) << endl;
    cout << *intPtr;

    return 0;
}