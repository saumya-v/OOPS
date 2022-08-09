#include<iostream>
using namespace std;
class Student{
    static int totalStudents;
public:
    int rollnumber;
    int age;
    Student(){
        totalStudents++;
    }
    int getrollnumber(){
        return rollnumber;
    }
    static int getTotalStudent(){
        return totalStudents;
    }
};
int Student::totalStudents=0;
int main(){
    Student s1;
    Student s2,s3,s4;
    cout<<Student::getTotalStudent()<<endl;
}
