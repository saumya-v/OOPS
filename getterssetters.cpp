#include<iostream>
using namespace std;
class Student{
public:
    int age;
private:
    int rollnumber;
public:
    void display(){
        cout<<age<<" "<<rollnumber<<endl;
    }
    int getrollnumber(){
        return rollnumber;
    }
    void setrollnumber(int a){
        rollnumber=a;
    }
};
int main(){
    Student s1;
    s1.age=24;
    s1.setrollnumber(1736);
    s1.display();
    Student *s2=new Student;
    s2->age=9;
    s2->setrollnumber(342);
    s2->display();
}
