

#include <iostream>
using namespace std;

int size = 0;
int usrArray[10];

int input = 0;

void inserAtEnd(int value){
    if(size < 10){
        usrArray[size] = value;
        size++;
    } else {
        cout << "Array is full. Cannot insert more elements." << endl;
    }
}

void insertAtBeginning(int value){
    if(size < 10){
        for(int i = size; i > 0; i--){
            usrArray[i] = usrArray[i - 1];
        }
        usrArray[0] = value;
        size++;
    } else {
        cout << "Array is full. Cannot insert more elements." << endl;
    }
}

int main(){

    int continueInput = 1;
    while(continueInput){
        cout << "Enter value in integers to add to the list: ";
        cin >> input;

        cout << "press 1 to insert at beginning, 2 to insert at end: ";
        int choice;
        cin >> choice;
        if(choice == 1)
            insertAtBeginning(input);
        else if(choice == 2)
            inserAtEnd(input);
        else
            cout << "Invalid choice!" << endl;

        cout << "Do you want to continue? (1 for yes, 0 for no): ";
        cin >> continueInput;
    }

    cout << "The elements in the array are: ";
    for(int i = 0; i < size; i++){
        cout << usrArray[i] << " ";
    }

    return 0;
}