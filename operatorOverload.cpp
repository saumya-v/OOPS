#include<iostream>
#include<climits>
using namespace std;
class Fraction{
public:
    int numerator,denominator;
    Fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }
    void print(){
        cout<<numerator<<"/"<<denominator<<endl;
    }
    void simplify(){
        int gcd=1;
        for(int i=1;i<=min(this->numerator,this->denominator);i++){
                if(this->numerator%i==0 && this->denominator%i==0){
                    gcd=i;
                }
                this->numerator/=gcd;
                this->denominator/=gcd;
        }
    }
    Fraction operator+(Fraction const &f2) const{
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        int num=numerator*x+f2.numerator*y;
        Fraction fnew(num,lcm);
            fnew.simplify();
            return fnew;
    }
    Fraction operator*(Fraction const &f2)const{
        int d=denominator*f2.denominator;
        int n=numerator*f2.numerator;
        Fraction fnew(n,d);
        fnew.simplify();
        return fnew;
    }
    bool operator==(Fraction const &f2)const{
        return (numerator==f2.numerator && denominator==f2.denominator);
    }
    //pre increment
    Fraction& operator++(){
        numerator=numerator+denominator;
        simplify();
        return *this;
    }
    //post increment
    Fraction operator++(int){
        Fraction fn(numerator,denominator);
        numerator=numerator+denominator;
        simplify();
        fn.simplify();
        return fn ;
    }
};
 int main(){
     Fraction f1(12,5);
     f1.print();
     Fraction f2(3,8);
     f2.print();
     Fraction f3=f1+f2;
     f3.print();
     if(f1==f2){
        cout<<"equal"<<endl;
     }
     else{
        cout<<"not equal"<<endl;
     }
     Fraction f4=f1*f2;
     f4.print();
     Fraction f5=++f1;
     f1.print();
     f5.print();
     Fraction f6=++(++f2);
     f2.print();
     f6.print();
     Fraction f7=f4++;
     f7.print();
     f4.print();
}
