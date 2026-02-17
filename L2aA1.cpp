#include <iostream>
using namespace std;

class Node{
    
    public:
        //attributes
        int data = 0;
        Node *next;

        //constructors

        
        Node(int data){
            this->data=data;
            this->next=NULL;
        }

    };

    //list class as the controller to the nodes

class List{
        
        public:
            //attribute
            Node *head;
            

            //constructors
            List(){
                this->head=NULL;
            }

          

        //search function to get the ppointer of the node searched
        Node* search(int data){
            Node *temp = head;
            while(temp->data != data && temp->next !=NULL){
                temp = temp->next;
            }
            
            return temp;

        }

        //method to insert the node at end
        void insertAtEnd(int data){
            Node *nodePtr = new Node(data);

            if(head == NULL){
                head = nodePtr;
            }
            else{
                Node *temp = head;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = nodePtr;
            }
            return;

        }

        //insert at the beginning 
        void insertAtBeginning(int data){
            Node *nn = new Node(data);
            if(head == NULL){
                head = nn;
                head->next=NULL;
            }
            else{
            nn->next = head;
            head = nn;
            }

            return;

        }
        
        //insert in between
        //after a value
        void insertAfterData(int searchData,int data){
            Node* nn = new Node(data);
            Node *tempPtr = search(searchData);
           
            nn->next = tempPtr->next;
            tempPtr->next= nn;

            return;
        }



        //delete at end
        void deleteAtEnd(){
        
                Node *temp = head;
                Node *beforeTemp = temp;
                while(temp->next!=NULL){
                    beforeTemp = temp; 
                    temp = temp->next;
                    
                }
                beforeTemp->next = NULL;
                delete temp;

                return;
            }

        //delete at the beginning
        void deleteAtStart(){
            Node *temp = head;
            head = head->next;
            delete temp;

            return;
        }


        //delete a user defined node
        void deleteInBetween(int data){

            Node *temp = head;
            Node *beforeTemp = temp;
           
            while(temp->data != data && temp->next !=NULL){
                beforeTemp = temp;
                temp = temp->next;
            }

            beforeTemp->next = temp->next;
            delete temp;

            return;

        }

        void deleteList(){
            Node *temp = head;
            while(head->next != NULL){
                temp = head;
                head = head->next;
                delete temp;
            }

            cout << "THe list has been deleted";
            return;

        }

        //displaying the list
        void displayList(){
            Node *temp = head;
            cout << "Start of the list:" << endl;
            while(temp != NULL){
                cout << " " << temp->data;
                temp = temp->next;
            }

        cout << "\n End of the list." << endl;

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

       /* void displayInReverseR(){
            cout << "display in reverse through loop method" << endl;
            Node *temp = head->next;
            Node *beforeTemp = head;

            while(temp->next != NULL){
                temp = temp->next;
            }

            displayInReverseR()
            
            cout <<temp->data << endl;

            return;
        }
            */

        
    };


    //main test 

   int main(){


    List myList;

    // inserting values
    myList.insertAtEnd(10);
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);

    myList.insertAtBeginning(5);

    myList.insertAfterData(20, 25);



    cout << "After Insertions:\n";
    myList.displayList();

    cout << "in reverse" << endl;
    myList.displayInReverse();

    



    myList.deleteAtStart();

    cout << "\nAfter Deleting at Start:\n";
    myList.displayList();

    myList.deleteAtEnd();

    cout << "\nAfter Deleting at End:\n";
    myList.displayList();

    myList.deleteInBetween(20);

    cout << "\nAfter Deleting 20:\n";
    myList.displayList();

   

    // SEARCH TEST

    Node* found = myList.search(25);

    if(found != NULL && found->data == 25){
        cout << "\n25 Found in the list.\n";
    }
    else{
        cout << "\n25 Not Found.\n";
    }

    // DELETE FULL LIST
    

    myList.deleteList();

    cout << endl;

    

    return 0;
}
