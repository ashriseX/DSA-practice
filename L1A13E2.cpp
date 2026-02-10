// pointers practice

#include <iostream>
using namespace std;

int main(){

    string str1 = "Abdul Saboor Hasan";
    string *strPtr = &str1;

    cout << strPtr << " and the data stored at this location is :  " << *strPtr << endl;
   

    bool voteEligible = 1;
    bool *boolPtr = &voteEligible;

    cout << boolPtr << " and " << *boolPtr << endl;
    return 0;
}