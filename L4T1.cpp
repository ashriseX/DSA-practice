#include<iostream>
using namespace std;

// Node class
class Node{
public:
    char data;
    Node* next;

    Node(char d){
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
    
        // Push function
        void push(char x){
            Node* nn = new Node(x);
    
            nn->next = topNode;
            topNode = nn;
        }
    
        // Pop function
        char pop(){
    
            if(topNode == NULL){
                return '\0';
            }
    
            Node* temp = topNode;
            char value = temp->data;
    
            topNode = topNode->next;
            delete temp;
    
            return value;
        }
    
        // Top function
        char top(){
    
            if(topNode == NULL)
                return '\0';
    
            return topNode->data;
        }
    
        // Check empty
        bool isEmpty(){
    
            if(topNode == NULL)
                return true;
            else
                return false;
        }
    };


    bool checkBalanced(string expr){

        Stack s;
    
        for(int i=0;i<expr.length();i++){
    
            char ch = expr[i];
    
            // Opening brackets
            if(ch=='(' || ch=='[' || ch=='{'){
                s.push(ch);
            }
    
            // Closing brackets
            else if(ch==')' || ch==']' || ch=='}'){
    
                if(s.isEmpty())
                    return false;
    
                char top = s.pop();
    
                if(ch==')' && top!='(')
                    return false;
    
                if(ch==']' && top!='[')
                    return false;
    
                if(ch=='}' && top!='{')
                    return false;
            }
        }
    
        return s.isEmpty();
    }



    int main(){

        string expr;
    
        cout<<"Enter bracket expression: ";
        cin>>expr;
    
        if(checkBalanced(expr))
            cout<<"Balanced Expression";
        else
            cout<<"Not Balanced Expression";
    
    }