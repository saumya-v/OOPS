#include<iostream>
using namespace std;
class DynamicArray{
    int *data;
    int nextIndex;
    int capacity;
public:
    DynamicArray(){
        data=new int[5];
        nextIndex=0;
        capacity=5;
    }
    void add(int element){
        if(nextIndex==capacity){
            int *newdata= new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newdata[i]=data[i];
            }
            delete[] data;
            data=newdata;
            capacity=capacity*2;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    int get(int i){
        if(i<nextIndex){
            return data[i];
        }
        else{
            return -1;
        }
    }
    void add(int i,int element){
        if(i<nextIndex){
            data[i]=element;
        }
        else if(i==nextIndex){
            add(element);
        }
        else{
            return;
        }
    }
    //deep copy for copy constructor
    DynamicArray(DynamicArray const &d){
        this->data=new int[d.capacity];
        for(int i=0;i<d.capacity;i++){
           this->data[i]=d.data[i];
        }
        this->nextIndex=d.nextIndex;
        this->capacity=d.capacity;
    }
    void print(){
        for(int i=0;i<nextIndex;i++){
           cout<<data[i]<<" ";
        }
        cout<<endl;
    }

};
int main(){
     DynamicArray d1;
     d1.add(10);
     d1.add(20);
     d1.add(30);
     d1.add(40);
     d1.add(50);
     d1.add(60);
     d1.print();
     DynamicArray d2(d1);
     d1.add(0,100);
     d2.print();
     d1.print();
}
