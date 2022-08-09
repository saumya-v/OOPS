#include<iostream>
using namespace std;
class Complex{
    int real,imaginary;
public:
    Complex(int real,int imaginary){
        this->real=real;
        this->imaginary=imaginary;
    }
    void add(Complex c2){
        this->real=real+c2.real;
        this->imaginary=imaginary+c2.imaginary;
    }
    void print(){
        cout<<this->real<<"+"<<"i"<<this->imaginary<<endl;
    }
    void multiply(Complex c2){
        this->real=(real*c2.real)-(imaginary*c2.imaginary);
        this->imaginary=(real*c2.imaginary)+(c2.real*imaginary);
    }
};
int main(){
    Complex c1(3,5);
    Complex c2(7,1);
    c1.multiply(c2);
    c1.print();
    c1.add(c2);
    c1.print();
}


