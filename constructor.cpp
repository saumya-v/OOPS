#include<iostream>
using namespace std;
class Student{
public:
    int age;
    int rollnumber;
    void display(){
        cout<<age<<" "<<rollnumber<<endl;
    }
    Student(){
        cout<<"constructor called"<<endl;
    }
    Student(int age){
        cout<<"constructor 2 called"<<endl;
     //this keyword use
        this->age=age;
    }
    Student(int b,int c){
        cout<<"constructor 3 called"<<endl;
        age=b;
        rollnumber=c;
    }
    //destructor
    ~Student(){
        cout<<"destructor called"<<endl;
    }
};
int main(){
    Student s1;
    s1.display();
    Student s2(3);
    s2.display();
    Student *s3= new Student(2,6);
    s3->display();
    //copy constructor
    Student s4(s2);
    s4.display();
    Student *s5=new Student(*s3);
    Student s6(*s3);
    s5->display();
    s6.display();
    Student s7(9);
    //copy assignment operator
    s7=s2;
    s7.display();
    //for calling destructor on dynamically created objects
    delete s3;
    delete s5;
}
