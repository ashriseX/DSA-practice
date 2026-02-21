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
        void mergeList(Node *head2){
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = head2;

             return;
        }
};

//main test class
int main(){

    List list1;
    List list2;

    //inserting data into the first list
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list1.insertAtEnd(30);

    cout << "List 1:\n";
    list1.displayList();

    //inserting data into the second list
    list2.insertAtEnd(40);
    list2.insertAtEnd(50);
    list2.insertAtEnd(60);

    cout << "\nList 2:\n";
    list2.displayList();

    //merging the two lists
    list1.mergeList(list2.head);

    cout << "\nMerged List:\n";
    list1.displayList();

     return 0;
}