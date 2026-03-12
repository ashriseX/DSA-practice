#include <iostream>
using namespace std;

/*
Node class for Circular Linked List
Each node contains data and pointer to next node
*/
class Node
{
public:
    int data;
    Node* next;
};

/*
Circular Linked List class containing all required operations
*/
class CircularList
{
private:
    Node* head;

public:

    // Constructor initializes empty list
    CircularList()
    {
        head = NULL;
    }

    /*
    Function: createList
    Creates a circular linked list with user defined number of nodes
    */
    void createList(int n)
    {
        Node *temp, *newNode;

        if(n <= 0)
            return;

        for(int i = 1; i <= n; i++)
        {
            newNode = new Node;

            cout << "Enter data for node " << i << ": ";
            cin >> newNode->data;

            if(head == NULL)
            {
                head = newNode;
                newNode->next = head;
                temp = head;
            }
            else
            {
                temp->next = newNode;
                newNode->next = head;
                temp = newNode;
            }
        }
    }

    /*
    Function: display
    Traverses the circular linked list and prints all node values
    */
    void display()
    {
        if(head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        while(temp != head);

        cout << "(Back to Head)\n";
    }

    /*
    Function: insertNode
    Inserts a new node at the end of the circular linked list
    */
    void insertNode(int value)
    {
        Node* newNode = new Node;
        newNode->data = value;

        if(head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    /*
    Function: deleteNode
    Deletes a node containing a specific value
    */
    void deleteNode(int value)
    {
        if(head == NULL)
            return;

        Node *temp = head, *prev = NULL;

        // If head needs to be deleted
        if(head->data == value)
        {
            while(temp->next != head)
                temp = temp->next;

            if(temp == head)
            {
                delete head;
                head = NULL;
                return;
            }

            temp->next = head->next;
            delete head;
            head = temp->next;
            return;
        }

        temp = head->next;

        while(temp != head)
        {
            if(temp->data == value)
            {
                prev->next = temp->next;
                delete temp;
                return;
            }

            prev = temp;
            temp = temp->next;
        }
    }

    /*
    Function: deleteAll
    Deletes the entire circular linked list
    */
    void deleteAll()
    {
        if(head == NULL)
            return;

        Node* temp = head->next;

        while(temp != head)
        {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        delete head;
        head = NULL;

        cout << "Entire list deleted\n";
    }

    /*
    Function: deleteEvenOddValues
    Deletes nodes having even or odd data values
    pass true -> delete even values
    pass false -> delete odd values
    */
    void deleteEvenOddValues(bool deleteEven)
    {
        if(head == NULL)
            return;

        Node *temp = head, *prev = NULL;

        do
        {
            Node* nextNode = temp->next;

            if((deleteEven && temp->data % 2 == 0) ||
               (!deleteEven && temp->data % 2 != 0))
            {
                if(temp == head)
                {
                    Node* last = head;

                    while(last->next != head)
                        last = last->next;

                    head = head->next;
                    last->next = head;

                    delete temp;
                    temp = head;
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
            }
            else
            {
                prev = temp;
                temp = nextNode;
            }

        } while(temp != head);
    }

    /*
    Function: deleteEvenPositionNodes
    Deletes nodes which are at even positions
    (2nd, 4th, 6th ...)
    */
    void deleteEvenPositionNodes()
    {
        if(head == NULL)
            return;

        Node *temp = head;
        int position = 1;

        do
        {
            Node* nextNode = temp->next;

            if(position % 2 == 0)
            {
                Node* prev = head;

                while(prev->next != temp)
                    prev = prev->next;

                prev->next = temp->next;
                delete temp;
            }

            temp = nextNode;
            position++;

        } while(temp != head);
    }

    /*
    Function: josephus
    Solves Josephus Problem using circular linked list
    n = number of people
    k = step count
    */
    void josephus(int n, int k)
    {
        CircularList tempList;

        for(int i = 1; i <= n; i++)
            tempList.insertNode(i);

        Node* ptr = tempList.head;
        Node* prev = NULL;

        while(ptr->next != ptr)
        {
            for(int i = 1; i < k; i++)
            {
                prev = ptr;
                ptr = ptr->next;
            }

            cout << "Eliminated: " << ptr->data << endl;

            prev->next = ptr->next;
            delete ptr;

            ptr = prev->next;
        }

        cout << "Survivor: " << ptr->data << endl;
    }
};

/*
Main function to test the circular linked list
*/
int main()
{
    CircularList list;

    list.createList(5);

    cout << "\nCircular Linked List:\n";
    list.display();

    cout << "\nInsert 99:\n";
    list.insertNode(99);
    list.display();

    cout << "\nDelete node with value 3:\n";
    list.deleteNode(3);
    list.display();

    cout << "\nDelete even value nodes:\n";
    list.deleteEvenOddValues(true);
    list.display();

    cout << "\nDelete nodes at even positions:\n";
    list.deleteEvenPositionNodes();
    list.display();

    cout << "\nJosephus Problem (n=7, k=3):\n";
    list.josephus(7,3);

    cout << "\nDeleting entire list:\n";
    list.deleteAll();

    return 0;
}