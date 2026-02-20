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
            Node *nn = new Node(data);
            if(head == NULL){
                head = nn;
                return;

            }
            else {
                Node *tempPtr = head;
                while(tempPtr->next != NULL){
                    tempPtr = tempPtr->next;
                }
                tempPtr->next = nn;
            }
        }

        //display the list
        void displayList(){
            Node *temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;

            return;
        }

        //merge two lists taking the head of the second list as a parameter
        void mergeList(No)
}