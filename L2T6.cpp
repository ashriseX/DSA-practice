#include <iostream>
using namespace std;
static int noOfStudents= 0;
class Student{
    private: 
        string name;
        int rollNo;
        double gpa;

        public:
        //constructor
            Student(){
                name = "";
                rollNo = ++noOfStudents;
                gpa = 4.00;

        }


    void getData(){
        cout << "Enter the data of the student:" <<endl;
        cout << "Enter the name of the student:"<<endl;
        cin >> this->name;
        cout << "Enter the GPA of the student:"<<endl;
        cin >> this->gpa;

        return;
    }

    void displayData(){
        cout << this->name<< endl;
        cout << this->rollNo<< endl;
        cout << this->gpa<< endl;

    }
};

int main(){

    cout << "Enter the number of of students you want to enroll."<<endl;
    int num;
    cin >> num;

    Student *stuInfo = new Student[num];

    for(int i = 0; i < num; i++){
        stuInfo[i].getData();
    }

    for(int i = 0; i < num; i++){
        stuInfo[i].displayData();
    }

    delete stuInfo;

    return 0;
}