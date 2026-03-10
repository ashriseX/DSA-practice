#include<iostream>
using namespace std;

// Node class for stack
class Node{
public:
    char data;
    Node* next;

    Node(char d){
        data = d;
        next = NULL;
    }
};

// Dynamic Stack
class Stack{
private:
    Node* topNode;

public:

    Stack(){
        topNode = NULL;
    }

    void push(char x){

        Node* nn = new Node(x);

        nn->next = topNode;
        topNode = nn;
    }

    char pop(){

        if(topNode == NULL)
            return '\0';

        Node* temp = topNode;
        char value = temp->data;

        topNode = topNode->next;
        delete temp;

        return value;
    }

    char top(){

        if(topNode == NULL)
            return '\0';

        return topNode->data;
    }

    bool isEmpty(){

        if(topNode == NULL)
            return true;

        return false;
    }
};

int precedence(char op){

    if(op == '+' || op == '-')
        return 1;

    if(op == '*' || op == '/')
        return 2;

    if(op == '^')
        return 3;

    return 0;
}

string infixToPostfix(string infix){

    Stack s;
    string postfix = "";

    for(int i=0;i<infix.length();i++){

        char ch = infix[i];

        // Operand
        if(isalnum(ch)){
            postfix += ch;
        }

        // Opening bracket
        else if(ch == '('){
            s.push(ch);
        }

        // Closing bracket
        else if(ch == ')'){

            while(!s.isEmpty() && s.top()!='('){
                postfix += s.pop();
            }

            s.pop();
        }

        // Operator
        else{

            while(!s.isEmpty() && precedence(s.top()) >= precedence(ch)){
                postfix += s.pop();
            }

            s.push(ch);
        }
    }

    while(!s.isEmpty()){
        postfix += s.pop();
    }

    return postfix;
}

int main(){

    string infix;

    cout<<"Enter Infix Expression: ";
    cin>>infix;

    string postfix = infixToPostfix(infix);

    cout<<"Postfix Expression: "<<postfix<<endl;

}
