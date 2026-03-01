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
        void insert(int data){
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

        //display list in reverse loop
        void displayInReverse(){
            cout << "display in reverse through loop method" << endl;
            Node *temp = head->next;
            Node *beforeTemp = head;

            while(temp->next != NULL){
                temp = temp->next;
            }

            do{
                beforeTemp= head;
                while(beforeTemp->next != temp){
                    beforeTemp = beforeTemp->next;
                }
                cout << temp->data <<" ";
                temp = beforeTemp;
            }while(temp != head);
            cout <<temp->data << endl;

            return;
        }


        //display in reverse by recursive method

      
        void printRecursion(Node* temp){

                    if(temp->next != NULL){
                        printRecursion(temp->next);
                        }
                    cout << temp->data << " " ;

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

        //reverse a linked list
        void reverseList(){
            Node* prev = NULL;
            Node* curr = head;
            Node* next = NULL;

            while(curr != NULL){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            head = prev;

            return;
        }


        // Function to merge two lists into a new list
        static List mergeLists(List &L1, List &L2) {
    
           
            List mergedList;
    
           
            Node* temp1 = L1.head;
            Node* temp2 = L2.head;
    
            
            while (temp1 != NULL) {
                mergedList.insert(temp1->data);
                temp1 = temp1->next;
            }
    
          
            while (temp2 != NULL) {
                mergedList.insert(temp2->data);
                temp2 = temp2->next;
            }
    
          
            return mergedList;
        }

        //checking multiple occurences of the data
        void findMultipleOccur(int value) {
    
            Node* temp = head;
            int position = 1;
            int count = 0;
    
            while (temp != NULL) {
    
                if (temp->data == value) {
                    cout << "Found at position: " << position << endl;
                    count++;
                }
    
                temp = temp->next;
                position++;
            }
    
            if (count == 0) {
                cout << "Value " << value << " not found in the list." << endl;
            }
            else {
                cout << "Total occurrences: " << count << endl;
            }
        }


    };

    //main test class
    int main(){
    
        List list1;
        List list2;
    
        //inserting data into the first list
        list1.insert(10);
        list1.insert(20);
        list1.insert(30);
        list1.insert(90);
        list1.insert(80);
        list1.insert(40);
    
        cout << "List 1:\n";
        list1.displayList();
    
        //inserting data into the second list
        list2.insert(40);
        list2.insert(50);
        list2.insert(60);
    
        cout << "\nList 2:\n";
        list2.displayList();
    
        //displaying the list in reverse
        cout << "\nDisplaying the list in reverse...\n";
        cout << "in reverse" << endl;
        list1.displayInReverse();
    
        cout << "in reverse through recursion" << endl;
        list2.printRecursion(list2.head);


        //merging the two lists
        List merged = List::mergeLists(list1, list2);
    
        cout << "\nMerged List:\n";
        merged.displayList();
    
        cout << "multiple occurences of the data" << endl;
        merged.findMultipleOccur(40);
    
        cout << "Successful completion of the program" << endl;
    
    
         return 0;
    }