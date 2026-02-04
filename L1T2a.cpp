#include <iostream>
using namespace std;

class UsrArray {
    public :
        int size;
        int usrArray[];

        //constructor
        UsrArray() {
            size = 0;
        }

        //method to search for a index of a vlue in the array
        int search(int value) {
            for (int i = 0; i < 10; i++){
                if (usrArray[i] == value){
                    return i;
                }
                else {
                    return -1;
                }
            }
        }

        //method to add value at the beginning
        void insertAtTheEnd(int value){
            if(size >= 10){
                cout << "Array is full cannot add any more elements." << endl;
                return;
            }
            else  {
                usrArray[size] = value;
                size++;
                cout << "value added at the end of the array." << endl;
            }

        }

        //method to add the vakue at start of the array
        void insertAtTheBeginning(int value){
            if(size >= 10){
                cout << "Array is full, cannot add any more elements." << endl;
                return;
            }
            else {
                for (int i = size; i > 0; i--)  {
                    usrArray[i] = usrArray[i-1];
                }
                usrArray[0] = value;
                size++;
                cout << "The value has been added at the index 0." << endl;
            }
        }

        //method to add value afterr a specific value
        void insertAfterValue(int value){

            cout << "Enter the value after which you want to insert the value: ";
            int searchValue;
            cin >> searchValue;

            int index = search(searchValue);
            if (index == -1){
                cout << "Value not found in the data." << endl;
                return;
            }
            else{
                if(size >= 10){
                    cout << "Array is full, cannot add any more elements." << endl;
                    return;
                }
                else{
                    for (int i = size; i > index; i--){
                        usrArray[i] = usrArray[i - 1];
                    }
                    usrArray[index + 1] = value;
                    size++;
                    cout << "Value inserted after " << searchValue << endl;
                }
            }
        }

        //method to add the value before a specified value
        void insertBeforeValue(int value){

            cout << "Enter the value before which you want to insert the value: ";
            int searchValue;
            cin >> searchValue;

            int index = search(searchValue);
            if (index == -1){
                cout << "Value not found in the data." << endl;
                return;
            }
            else{
                if(size >= 10){
                    cout << "Array is full, cannot add any more elements." << endl;
                    return;
                }
                else{
                    for (int i = size; i > index; i--){
                        usrArray[i] = usrArray[i - 1];
                    }
                    usrArray[index] = value;
                    size++;
                    cout << "Value inserted before " << searchValue << endl;
                }
            }
        }


        //method to display the array elements
        void displayArray(){
            cout << "The elements in the array are : " << endl;
            for (int i = 0; i < size; i++){
                cout << usrArray[i] << " " ;
            }
            cout << endl;
        }

        //method to delete a value from the array and end
        void deleteValue(int value){
            int index = search(value);
            if (index == -1){
                cout << "Value not found in the data." << endl;
                return;
            }
            else {
                if (size == 0){
                    cout << "Array is empty cannot add any more elements." << endl;
                    return;
                }
                else if(index == size -1){
                    size--;
                    cout << "Value " << value << " deleted from the array." << endl;
                    return;
                }
                else{
                    for (int i = index; i < size -1; i++){
                    usrArray[i] = usrArray[i + 1];
                    }
                    size--;
                    cout << "Value " << value << " deleted from the array." << endl;
                }
            }
        }

        //method to delete the value from the begining
        void deleteFromBeginning(){
            if (size == 0){
                cout << "Array is empty cannot delete any more elements." << endl;
                return;
            }
            else{
                for (int i = 0; i < size -1; i++){
                    usrArray[i] = usrArray[i + 1];
                }
                size--;
                cout << "Value deleted from the beginning of the array." << endl;
            }
        }

        //method to delete the entire array
        void deleteArray(){
            size = 0;
            cout << "All elements deleted from the array." << endl;
        }
};

int main(){
    UsrArray arr;
    int choice = -1;
    while(choice != 0){
        cout << "Press the integer value of option you want to perform: " << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert after a specific value" << endl;
        cout << "4. Insert before a specific value" << endl;
        cout << "5. Delete a specific value" << endl;
        cout << "6. Delete from the beginning" << endl;
        cout << "7. Delete entire array" << endl;
        cout << "8. Display the array elements" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

    
        cin >> choice;
        int value;
        while (choice < 0 || choice > 8){
            cout << "Invalid choice! Please enter a valid choice between 0 and 8: ";
            cin >> choice;
            }
        switch(choice){
            case 1:
                cout << "Enter the value to insert at the beginning: ";
                cin >> value;
                arr.insertAtTheBeginning(value);
                break;
            case 2:
                cout << "Enter the value to insert at the end: ";
                cin >> value;
                arr.insertAtTheEnd(value);
                break;
            case 3:
                cout << "Enter the value to insert after a specific value: ";
                cin >> value;
                arr.insertAfterValue(value);
                break;
            case 4:
                cout << "Enter the value to insert before a specific value: ";
                cin >> value;
                arr.insertBeforeValue(value);
                break;
            case 5:
                cout << "Enter the value to delete: ";
                cin >> value;
                arr.deleteValue(value);
                break;
            case 6:
                arr.deleteFromBeginning();
                break;
            case 7:
                arr.deleteArray();
                break;
            case 8:
                arr.displayArray();
                break;
            default:
                if(choice != 0){
                    cout << "Invalid choice!" << endl;
                }
                else{
                    cout << "Exiting the program." << endl;
                }
                break;
        }

    }

    return 0;

}
