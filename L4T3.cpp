#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

class Stack{
    private:
        Node* topNode;
    
    public:
    
        Stack(){
            topNode = NULL;
        }
    
        void push(int x){
    
            Node* nn = new Node(x);
            nn->next = topNode;
            topNode = nn;
        }
    
        int pop(){
    
            if(topNode == NULL)
                return -1;
    
            Node* temp = topNode;
            int value = temp->data;
    
            topNode = topNode->next;
            delete temp;
    
            return value;
        }
    
        bool isEmpty(){
    
            if(topNode == NULL)
                return true;
    
            return false;
        }
    };

    int evaluatePostfix(string expr){

        Stack s;
    
        for(int i=0;i<expr.length();i++){
    
            char ch = expr[i];
    
            // If operand (digit)
            if(isdigit(ch)){
                int value = ch - '0';
                s.push(value);
            }
    
            // Operator
            else{
    
                int operand2 = s.pop();
                int operand1 = s.pop();
    
                int result;
    
                if(ch == '+')
                    result = operand1 + operand2;
    
                else if(ch == '-')
                    result = operand1 - operand2;
    
                else if(ch == '*')
                    result = operand1 * operand2;
    
                else if(ch == '/')
                    result = operand1 / operand2;
    
                s.push(result);
            }
        }
    
        return s.pop();
    }

    int main(){

        string postfix;
    
        cout<<"Enter Postfix Expression: ";
        cin>>postfix;
    
        int result = evaluatePostfix(postfix);
    
        cout<<"Result = "<<result<<endl;
    
    }

    