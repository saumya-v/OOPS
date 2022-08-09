#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Polynomial {
    public:
    int *degCoeff;
    int capacity;// Name of your array (Don't change this)

    Polynomial(){
        degCoeff=new int[10];
        capacity=10;
        for(int i=0;i<10;i++){
            degCoeff[i]=0;
        }
    }
    Polynomial(Polynomial const &p){
        degCoeff=new int[p.capacity];
        for(int i=0;i<p.capacity;i++){
            degCoeff[i]=p.degCoeff[i];
        }
        capacity=p.capacity;
    }
    void operator=(Polynomial const &p){
        delete[] degCoeff;
        degCoeff=new int[p.capacity];
        for(int i=0;i<p.capacity;i++){
            degCoeff[i]=p.degCoeff[i];
        }
        capacity=p.capacity;
    }
    void setCoefficient(int degree,int coeff){
        if(degree>=capacity){
            int size=2*capacity;
            while(size<=degree){
                size*=2;
            }
            int *newDegCoeff=new int[size];
            for(int i=0;i<size;i++){
                newDegCoeff[i]=0;
            }
            for(int i=0;i<capacity;i++){
                newDegCoeff[i]=degCoeff[i];
            }
            capacity=size;
            delete[] degCoeff;
            degCoeff=newDegCoeff;
        }
        degCoeff[degree]=coeff;
    }
    void print(){
        for(int i=0;i<capacity;i++){
            if(degCoeff[i]!=0){
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
    // Complete the class
    Polynomial operator+(Polynomial const &p){
        Polynomial pNew;
        int i=0,j=0;
        while(i<this->capacity && j<p.capacity){
            int deg=i;
            int coeff=this->degCoeff[i]+p.degCoeff[j];
            pNew.setCoefficient(deg,coeff);
            i++;
            j++;
        }
        while(i<capacity){
            pNew.setCoefficient(i,degCoeff[i]);
            i++;
        }
        while(j<p.capacity){
            pNew.setCoefficient(j,p.degCoeff[j]);
            j++;
        }
        return pNew;
    }
    Polynomial operator-(Polynomial const &p){
        Polynomial pNew;
        int i=0,j=0;
        while(i<this->capacity && j<p.capacity){
            int deg=i;
            int coeff=this->degCoeff[i]-p.degCoeff[j];
            pNew.setCoefficient(deg,coeff);
            i++;
            j++;
        }
        while(i<capacity){
            pNew.setCoefficient(i,degCoeff[i]);
            i++;
        }
        while(j<p.capacity){
            pNew.setCoefficient(j,(-1*p.degCoeff[j]));
            j++;
        }
        return pNew;
    }
    int getCoefficient(int degree){
        if(degree>=capacity){
            return 0;
        }
        return degCoeff[degree];
    }
    Polynomial operator*(Polynomial p){
        Polynomial pNew;
        for(int j=0;j<p.capacity;j++){
            for(int i=0;i<capacity;i++){
                int deg=i+j;
                int coeff=pNew.getCoefficient(deg)+(this->degCoeff[i]*p.degCoeff[j]);
                pNew.setCoefficient(deg,coeff);
            }
        }
        return pNew;
    }

};

//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }

    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }

    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }

    cin >> choice;

    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

    }

    return 0;
}
