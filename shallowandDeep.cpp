#include<iostream>
using namespace std;
class Student{
    int age;
    char *name;
public:
    void print(){
        cout<<age<<" "<<name<<endl;
    }
    Student(char *name,int age){
        this->name=name;
        this->age=age;
    }
};
int main(){
    char name[100]="abcd";
    Student s1(name,15);
    s1.print();
    name[2]='t';
    Student s2(name,18);
    s1.print();
    s2.print();
}
