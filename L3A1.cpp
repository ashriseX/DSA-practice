//start of the doubly linked list
//in the following few labs i will practice the codes related to the doubly linked lists


//node class
class Node{
    public:
        int data;
        Node* next;
        Node* prev;

    //constructor
        Node(int data, Node* prev){
            this->data = data;
            this->prev = prev;
            this->next = NULL;

        }


    
};

//list class to control and manage nodes
