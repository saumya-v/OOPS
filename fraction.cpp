#include<iostream>
using namespace std;
class Fraction{
    int numerator;
    int denominator;
public:
    //so that passing parameters is necessary
    Fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }
    void print(){
        cout<<numerator<<"/"<<denominator<<endl;
    }
    void add(Fraction f2){
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        this->numerator=(x*numerator)+(y*f2.numerator);
        this->denominator=lcm;
        simplify();
    }
    void simplify(){
        int gcd=1;
        for(int i=1;i<=min(this->numerator,this->denominator);i++){
            if(this->numerator%i==0 && this->denominator%i==0){
                gcd=i;
            }
        }
        this->numerator=this->numerator/gcd;
        this->denominator=this->denominator/gcd;
    }
};
int main(){
    Fraction f1(2,6);
    Fraction f2(4,7);
    f1.add(f2);
    f1.print();
    f2.print();
}
