//bank class and dynamic objects
#include <iostream>
using namespace std;
static int accounts = 0;
class Bank{
    public:
        
        int accountNumber;
        int balance;
        string acntHolder;

        //constructor

        Bank(int accountNumber, int balance, string acntHolder){
            this->accountNumber=accounts;
            this->balance = balance;
            this->acntHolder = acntHolder;
            accounts++;

        }
        Bank(){
            accountNumber = accounts;
            balance = 0;
            acntHolder = "Null";
        }

    //method to deposit balance
    void deposit(){
        cout << "Enter the amount you want to deposit:" << endl;
        int deposit;
        cin >>deposit;
        balance+=deposit;
        return;
    }

    void display(){
        cout << accountNumber<< endl;
        cout << acntHolder<< endl;
        cout << balance<< "$" << endl;

    }

};

int main(){
    cout << "Start:" << endl;
    Bank *b1 = new Bank;
    b1->acntHolder = "ASH";
    b1->deposit();
    
    Bank *b2 = new Bank;

    b1->display();
    b2->display();

    delete b1;
    delete b2;

    return 0;
}