//start of the doubly linked list
//in the following few labs i will practice the codes related to the doubly linked lists
#include <iostream>
using namespace std;

//node class
class Node{
    public:
        int data;
        Node* prev;
        Node* next;

    //constructor
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;

        }

  
};

//doubly linked list class to manage the doubly Nodes
class DoubleList{
    public:
        Node* head;
        Node* tail;

        //consrtructor
        DoubleList(){
            this->head = NULL;
            this->tail = NULL;

        }

        //------------------------------------------------------

        //search methods Overloaded
        //if the data is given and node is to be found:
        Node* searchByData(int data){
            Node* temp = head;
            while (temp->next != NULL){
                if(temp->data == data){
                    return temp;
                }
                temp = temp->next;
            }
            cout << "No data match found in the existing List" << endl;
            return NULL;
        }
        //if the node number is given;
        Node* searchByNode(int nodeNum){
            Node* temp = head;
            int num = 1;
            while(temp->next != NULL){
                if(num = nodeNum){
                    return temp;
                }
                num++;
                temp = temp->next;
            }
            cout << "The node number provided is out of bounds!" << endl;
            return NULL;
        }
        //----------------------------------------------------------------

        //node insertion methods:

        //method to insert at start
        void insertAtStart(int data){
            Node* nn = new Node(data);

            if (head ==NULL && tail == NULL){
                head = nn;
            }
            else{
                head->prev = nn;
                nn->next = head;
                head = nn;
            }
            return;
        }

        //method to insert at the end
        void insertAtEnd(int data){
            Node* nn = new Node(data);
            if (head == NULL && tail == NULL){
                head = nn;
            }
            else{
                tail->next = nn;
                nn->prev = tail;
                tail = nn;
            }

            return;
        }

        // insert in between nodes by data
        void insertInBetweenData(int prevData, int data){
            Node* nn = new Node(data);
            Node* temp = searchByData(prevData);
            if (temp == NULL){
                return;
            }
            nn->next = temp->next;
            nn->prev = temp;
            temp->next->prev = nn;
            temp->next = nn;

            return; 
        }

        //inserting in between the nodes by node number
        void insertInBetweenNodes(int nodeNum, int data){
            Node* nn = new Node(data);
            Node* temp = searchByNode(nodeNum);
            if (temp == NULL){
                return;
            }
            nn->next = temp->next;
            nn->prev = temp;
            temp->next->prev = nn;
            temp->next = nn;

            return; 
        }
        //---------------------------------------------------------------------

        //deletion methods:

        //delete at start
        void deleteAtStart(){
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;

            return;
        }
        //delete at end
        void deleteAtEnd(){
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;

            delete temp;

            return;
        }
        //delete a specific Node by data
        void deleteByData(int data){
            Node* temp = searchByData(data);
            if(temp == head){
                deleteAtStart();
                return;
            }
            else if (temp == tail){
                deleteAtEnd();
                return;
            }
            else if (temp == NULL){
                return;
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                delete temp;
                return;
            }
        }
        //delete a specific node by node number
        void deleteByNode(int NodeNum){
            Node* temp = searchByNode(NodeNum);
            if(temp == head){
                deleteAtStart();
                return;
            }
            else if (temp == tail){
                deleteAtEnd();
                return;
            }
            else if (temp == NULL){
                return;
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                delete temp;
                return;
            }
        }


        //deleting the whole list:
        void deleteList(){
            
            while(head != NULL){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            cout << "List deleted successfully!" << endl;
            return;
        }

        //------------------------------------------

        //displaying the list
        void displayList(){
            Node* temp = head;
            while (temp->next != NULL){
                cout << temp->data << " " ;
                temp = temp->next;
            }
            cout << endl;
            return;

        }

        //--------------------------------------------------
        //--------------------------TASK 1-------------------------------------
        //reversing the order of the doubly linked list

        void reverseOrder(){
            Node* temp = head;
            while (temp != NULL){
                temp = temp->next;
                temp->prev->next = temp->prev->prev;
                temp->prev->prev = temp;
            }

            temp = head;
            head = tail;
            tail = temp;

            return;

        }

        //---------------------------------------------------------
        //-----------------TASK 2------------------------------------
        //method to search and swap the two nodes on the basis of data given
        void swapNodes(int data1, int data2){
            Node* temp1 = searchByData(data1);
            Node* temp2 = searchByData(data2);
            if(temp1 == NULL || temp2 == NULL ){
                cout << " Data provided not found!" << endl;
                return;
            }
            Node* temp = temp1->next;
            temp1->next = temp2->next;
            temp2->next = temp;

            temp = temp1->prev;
            temp1->prev = temp2->prev;
            temp2->prev = temp;

            return;

        }





};

//list class to control and manage nodes
int main() {

    // INPUT: Create Doubly Linked List Object
    DoubleList list;

    cout << "===== Testing Doubly Linked List =====" << endl;

    // ----------------------------------
    // Insert at Start
    cout << "\nInserting at Start..." << endl;
    list.insertAtStart(10);
    list.insertAtStart(20);
    list.insertAtStart(30);

    cout << "List after inserting at start: ";
    list.displayList();

    // ----------------------------------
    // Insert at End
    cout << "\nInserting at End..." << endl;
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "List after inserting at end: ";
    list.displayList();

    // ----------------------------------
    // Insert in Between (by Data)
    cout << "\nInsert 25 after 20..." << endl;
    list.insertInBetweenData(20, 25);

    cout << "List after inserting in between: ";
    list.displayList();

    // ----------------------------------
    // Search by Data
    cout << "\nSearching for 25..." << endl;
    Node* found = list.searchByData(25);

    if (found != NULL) {
        cout << "Data found: " << found->data << endl;
    }

    // ----------------------------------
    // Delete at Start
    cout << "\nDeleting at Start..." << endl;
    list.deleteAtStart();

    cout << "List after delete at start: ";
    list.displayList();

    // ----------------------------------
    // Delete at End
    cout << "\nDeleting at End..." << endl;
    list.deleteAtEnd();

    cout << "List after delete at end: ";
    list.displayList();

    // ----------------------------------
    // Delete by Data
    cout << "\nDeleting node with data 25..." << endl;
    list.deleteByData(25);

    cout << "List after deleting 25: ";
    list.displayList();

    // ----------------------------------
    // Reverse List
    cout << "\nReversing List..." << endl;
    list.reverseOrder();

    cout << "List after reversing: ";
    list.displayList();

    // ----------------------------------
    // Swap Nodes
    cout << "\nSwapping 20 and 40..." << endl;
    list.swapNodes(20, 40);

    cout << "List after swapping: ";
    list.displayList();

    // ----------------------------------
    // Delete Entire List
    cout << "\nDeleting Entire List..." << endl;
    list.deleteList();

    cout << "\n===== Program Finished Successfully =====" << endl;

    return 0;
}
