#include<iostream>
using namespace std;
class Student{
public:
    int age;
    const int rollnumber;
    Student(int a,int r):age(a),rollnumber(r){
    };
    void print(){
        cout<<age<<" "<<rollnumber<<endl;
    }
};
int main(){
    Student s1(12,345);
    s1.print();
}

