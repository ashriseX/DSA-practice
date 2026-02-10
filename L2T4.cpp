#include <iostream>
using namespace std;

struct Employee{
    public:
        string name = "Abdul Saboor Hasan";
        int id = 2237;
        int salary = 0;



};

//method to display using the pointer
void display( Employee* ptr){
    cout << ptr->name << endl;
    cout << ptr->id << endl;
    cout << ptr->salary;

    return;

}


int main(){

    Employee e1;
    Employee* ePtr = &e1;

    cout << ePtr->name << endl;
    cout << ePtr->id << endl;
    cout << ePtr->salary << endl;
    ePtr->salary = 1000000;

    display(ePtr);

    return 0;

}