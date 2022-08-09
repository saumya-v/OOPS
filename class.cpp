#include<iostream>
using namespace std;
class Student{
public:
    int age;
    int rollnumber;
};
int main(){
    Student s1;
    s1.age=20;
    s1.rollnumber=2321;
    Student *s2=new Student;
    s2->age=34;
    (*s2).rollnumber=432;
    cout<<s1.age<<" "<<s1.rollnumber<<endl;
    cout<<s2->age<<" "<<s2->rollnumber;
}
