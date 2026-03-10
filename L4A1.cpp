// Stack data structure implementation lab
// Lab tasks from the CSC 211 lab manual
//SP25-BCT-001
//Abdul Saboor Hasan

#include <iostream>
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

    Stack* s1 = new Stack(5);
    s1->pop();
    s1->push('a');
    s1->push('1');
    s1->push('b');
    s1->push('2');
    s1->push('c');
    s1->push('3');
    
    s1->display();
    cout << s1->pop() << endl;
    cout << s1->pop() << endl;
    cout << s1->pop() << endl;

    s1->display();



    return 0;
}