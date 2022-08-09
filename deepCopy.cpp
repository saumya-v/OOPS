#include<iostream>
#include<cstring>
using namespace std;
class Student{
    int age;
    char *name;
public:
    Student(int age,char *name){
        this->age=age;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }
    void display(){
        cout<<age<<" "<<name<<endl;
    }
};
int main(){
    char name[100]="abcd";
    Student s1(15,name);
    s1.display();
    name[2]='t';
    Student s2(19,name);
    s2.display();
    s1.display();
}
