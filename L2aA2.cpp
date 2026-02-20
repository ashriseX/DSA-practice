#include <iostream>
using namespace std;

//node class
class Node{

    public:
        int data;
        Node *next;


    //constructors
        Node(int data){
            this->data = data;
            this->next = NULL;
        }


};

//List class to control the nodes
class List{

    public:
        Node *head;

        List(){
            this->head = NULL;
        }


        //method to add a new node
        void insertAtEnd(int data){
            
        }
}