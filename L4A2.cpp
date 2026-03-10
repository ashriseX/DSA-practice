//Stack implementation using dynamic linked list
//lab activity 2

#include <iostream>
using namespace std;

//Node class to store each level of the  stack
class Node{
    public:
        char data;
        Node* link;

        //constructor
        Node(char newChar){
            this->data = newChar;
            this->link = NULL;
        }
};

//stack class
class Stack{
    private: 
        Node* head;
    
    public:
        //constructor
        Stack(){
            this->head = NULL;

        }

        //methods
        //push function
        void push(char newChar){
            Node* nn = new Node(newChar);
            if(head == NULL){
                head = nn;
            }
            else{
                nn->link = head;
                head = nn;

            }
           
            return;
        
        }

        //pop function
        char pop(){
            if(head == NULL){
                cout << "\nStack Underflow, i.e Stack is empty!" << endl;
                return -1;
            }
            else{
                Node* temp = head;
                char T = temp->data;
                head = temp->link;
                delete temp;
                return T;

            }

        
        }

        //display stack;
        void display(){
            cout << "Stack contains:" << endl;
            Node* temp = head;
            while(temp != NULL){
                cout << "| " << temp->data << " |" <<endl;
                temp = temp->link;
            }
            cout << "|___|" << endl;
            return;
        }


};

int main(){

    Stack* s1 = new Stack();
    s1->pop();
    s1->push('O');
    s1->push('L');
    s1->push('L');
    s1->push('E');
    s1->push('H');
    s1->push('-');
    
    s1->display();
    cout << s1->pop() << endl;
    cout << s1->pop() << endl;
    cout << s1->pop() << endl;

    s1->display();

    return 0;
}