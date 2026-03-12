

//start of the doubly linked list
//in the following few labs i will practice the codes related to the doubly linked lists
#include <iostream>
using namespace std;
//sinly linked list
class SNode{
    public:
        int data;
        SNode* next;
    
        SNode(int data){
            this->data = data;
            this->next = NULL;
        }
    };
//singly linked list list class
class SinglyList{
    public:
    
        SNode* Shead;
    
        // constructor
        SinglyList(){
            Shead = NULL;

        }
        void insertAtStart(int data){

            SNode* nn = new SNode(data);
        
            nn->next = Shead;
            Shead = nn;
        }
        void deleteAtStart(){

            if(Shead == NULL){
                cout << "List is empty" << endl;
                return;
            }
        
            SNode* temp = Shead;
            Shead = Shead->next;
        
            delete temp;
        }
        void display(){

            SNode* temp = Shead;
        
            while(temp != NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
        
            cout << "NULL" << endl;
        }
    };
//===========================================================================================
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
        
            while(temp != NULL){
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
        
            while(temp != NULL){
                if(num == nodeNum){
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
        
            if(head == NULL){
                head = nn;
                tail = nn;
            }
            else{
                nn->next = head;
                head->prev = nn;
                head = nn;
            }
        }

        //method to insert at the end
        void insertAtEnd(int data){
            Node* nn = new Node(data);
            if(head == NULL){
                head = nn;
                tail = nn;
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

            Node* temp = searchByData(prevData);
        
            if(temp == NULL)
                return;
        
            if(temp == tail){
                insertAtEnd(data);
                return;
            }
        
            Node* nn = new Node(data);
        
            nn->next = temp->next;
            nn->prev = temp;
        
            temp->next->prev = nn;
            temp->next = nn;
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

            if(head == NULL)
                return;
        
            Node* temp = head;
        
            if(head == tail){
                head = NULL;
                tail = NULL;
            }
            else{
                head = head->next;
                head->prev = NULL;
            }
        
            delete temp;
        }
        //delete at end
        void deleteAtEnd(){

            if(tail == NULL)
                return;
        
            Node* temp = tail;
        
            if(head == tail){
                head = NULL;
                tail = NULL;
            }
            else{
                tail = tail->prev;
                tail->next = NULL;
            }
        
            delete temp;
        }
        //delete a specific Node by data
        void deleteByData(int data){

            Node* temp = searchByData(data);
        
            if(temp == NULL)
                return;
        
            if(temp == head){
                deleteAtStart();
            }
            else if(temp == tail){
                deleteAtEnd();
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
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
        
            tail = NULL;
        
            cout << "List deleted successfully!" << endl;
        }

        //------------------------------------------

        //displaying the list
        void displayList(){
            Node* temp = head;
        
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        
            cout << endl;
        }

        //--------------------------------------------------
        //--------------------------TASK 1-------------------------------------
        //reversing the order of the doubly linked list

        void reverseOrder(){

            Node* temp = NULL;
            Node* current = head;
        
            while(current != NULL){
        
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;
        
                current = current->prev;
            }
        
            temp = head;
            head = tail;
            tail = temp;
        }
        //---------------------------------------------------------
        //-----------------TASK 2------------------------------------
        //method to search and swap the two nodes on the basis of data given
        void swapNodes(int data1, int data2){

            if(data1 == data2)
                return;
        
            Node* node1 = searchByData(data1);
            Node* node2 = searchByData(data2);
        
            if(node1 == NULL || node2 == NULL){
                cout << "Data not found!" << endl;
                return;
            }
        
            Node* prev1 = node1->prev;
            Node* next1 = node1->next;
        
            Node* prev2 = node2->prev;
            Node* next2 = node2->next;
        
            // connect neighbors of node1
            if(prev1 != NULL)
                prev1->next = node2;
            else
                head = node2;
        
            if(next1 != NULL)
                next1->prev = node2;
            else
                tail = node2;
        
            // connect neighbors of node2
            if(prev2 != NULL)
                prev2->next = node1;
            else
                head = node1;
        
            if(next2 != NULL)
                next2->prev = node1;
            else
                tail = node1;
        
            // swap internal pointers
            node1->prev = prev2;
            node1->next = next2;
        
            node2->prev = prev1;
            node2->next = next1;
        }

        //-----------------------------------------------------------
        //------------------------Task 3----------------------------
        //method which will convert the singly linked list into a doubly linked list
        Node* convertToDoubly(SNode* Shead){

            if(Shead == NULL)
                return NULL;
        
            SNode* temp = Shead;
        
            Node* head = NULL;
            Node* tail = NULL;
        
            while(temp != NULL){
        
                Node* newNode = new Node(temp->data);
        
                if(head == NULL){
                    head = newNode;
                    tail = newNode;
                }
                else{
                    tail->next = newNode;
                    newNode->prev = tail;
                    tail = newNode;
                }
        
                temp = temp->next;
            }
        
            return head;
        }





};

//list class to control and manage nodes
int main() {

        // Create Doubly Linked List Object
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

        //last task
        // INPUT: create singly linked list
        SinglyList sList;
    
        cout << "Creating Singly Linked List..." << endl;
    
        sList.insertAtStart(10);
        sList.insertAtStart(20);
        sList.insertAtStart(30);
        sList.insertAtStart(40);
        sList.insertAtStart(50);
    
        cout << "Singly Linked List: ";
        sList.display();
    
    
        //convert singly list to doubly list
        cout << "\nConverting to Doubly Linked List..." << endl;
    
        DoubleList dList;
    
        SNode* temp = sList.Shead;
    
        while(temp != NULL){
    
            dList.insertAtEnd(temp->data);
    
            temp = temp->next;
        }
    
    
        cout << "Doubly Linked List: ";
        dList.displayList();
    
    
        return 0;
    }
