#include<iostream>
using namespace std;

// Node class
class Node{
public:
    char data;
    Node* link;

    Node(char newChar){
        data = newChar;
        link = NULL;
    }
};

// Stack class
class Stack{
private:
    Node* head;

public:
    Stack(){
        head = NULL;
    }

    // push
    void push(char newChar){
        Node* nn = new Node(newChar);

        if(head == NULL){
            head = nn;
        }
        else{
            nn->link = head;
            head = nn;
        }
    }

    // pop
    char pop(){
        if(head == NULL){
            cout << "Stack Underflow" << endl;
            return -1;
        }

        Node* temp = head;
        char value = temp->data;
        head = temp->link;
        delete temp;

        return value;
    }

    // top
    char top(){
        if(head == NULL)
            return -1;

        return head->data;
    }

    // empty
    bool empty(){
        if(head == NULL)
            return true;
        else
            return false;
    }
};


// Balanced Parenthesis function
bool isBalanced(string expr){

    Stack s;
    char ch;

    for(int i=0; i<expr.length(); i++){

        // push opening brackets
        if(expr[i]=='(' || expr[i]=='[' || expr[i]=='{'){
            s.push(expr[i]);
            continue;
        }

        // if closing bracket appears but stack empty
        if(s.empty())
            return false;

        switch(expr[i]){

            case ')':
                ch = s.top();
                s.pop();
                if(ch=='{' || ch=='[')
                    return false;
                break;

            case '}':
                ch = s.top();
                s.pop();
                if(ch=='(' || ch=='[')
                    return false;
                break;

            case ']':
                ch = s.top();
                s.pop();
                if(ch=='(' || ch=='{')
                    return false;
                break;
        }
    }

    return s.empty();
}


// Main
int main(){

    string expr = "[{}(){()}]";

    if(isBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";

}