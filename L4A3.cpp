//using stack to reverse strings character by character
//Lab Activity 3


#include <iostream>
#include <cstring>
using namespace std;

//Stack array
class Stack{
    public:
        int top;
        int size;
        char arr[];

        //constructor
        Stack(int size){
            this->top = -1;
            this->size = size;
            this->arr[size];

        }

        //push function
        void push(char newChar){
            if(top+1 == size){
                cout << "\nStack overflow" << endl;
                return;

            }
            else {
                arr[++top] = newChar;
                return;
            }
        }

        //pop function
        char pop(){
            if(top == -1){
                cout << "\nStack Underflow, i.e Stack is empty!" << endl;
                return -1;
            }
            else{
                return arr[top--];
            }

        
        }

        //display stack;
        void display(){
            cout << "Stack contains:" << endl;
            for(int i = top; i >= 0; i--){
                cout << "| " << arr[i] << " |" <<endl;
            }
            cout << "|___|" << endl;
            return;
        }
};



int main(){

    char str[] = "i love DSA!";
    int length = strlen(str);
    Stack s1(length);
    s1.pop();

    
    for(int i = 0; i < length; i++){
        s1.push(str[i]);
        
    }

    s1.display();

    cout << s1.pop();
    cout << s1.pop();
    cout << s1.pop();




    return 0;
}