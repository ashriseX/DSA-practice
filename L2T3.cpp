#include <iostream>
using namespace std;

//function to passing and returning the pointer to return the maximum marks
int *maxMarks(int *maxPtr, int size){
    int *max = maxPtr;

    for(int i = 0; i < size; i++){
        if(*max < *maxPtr){
            max = maxPtr;
        }
        maxPtr++;
    }

    cout << "The maximum value is: " << *max << "and its address is: " << max << endl;
    return max;

}

//function to update a value py passing the reference
void increment(int &update){
    cout << update << "is the value before modification, enter the value to change the value:" << endl;
    update= update+ ((update*10)/100);
    return;
}


int main(){
    int marks[] = {89, 90, 99, 85, 80, 66};
    int *ptr = marks;
    ptr = maxMarks(ptr, 6);

    cout << marks[1] << endl;
    increment(marks[1]);
    cout << marks[1];



    return 0;
}