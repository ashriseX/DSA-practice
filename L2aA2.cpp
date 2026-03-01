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

        //checking multiple occurences of data in the the list
        void multipleOcuurrences(){
            Node* stale = head;
            Node* checker;
            int index = 1;

            while(stale->next != NULL){
                checker = stale->next;
                bool match = false;
                int node = 1;
                while(checker->next != NULL){
                    checker = checker->next;
                    if(checker->data == stale->data){
                        match = true;
                        cout << node << " " ;
                    }
                    node++;
                }
                if(match==true){
                    cout <<endl << index << "th index value" << stale->data << " has been repeated at above indexes" << endl;

                }
                
                stale = stale->next;
                index++;
                
            }

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
    list1.insertAtEnd(90);
    list1.insertAtEnd(80);
    list1.insertAtEnd(40);

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

    cout << "multiple occurences of the data" << endl;
    list1.multipleOcuurrences();

    cout << "Successful completion of the program" << endl;


     return 0;
}

    