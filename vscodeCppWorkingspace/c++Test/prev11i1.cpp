#include<iostream>
#include <string>
using namespace std;

class Vehicle{

protected:
    string NO;
public:
    Vehicle(string n){

        this->NO = n;

    }
    virtual int fee()=0;//计算应收费用

};

class Car:public Vehicle{
private:
    int guest;
    int weight;
public:
    Car(const string & _NO,const int & _guest,const int & _weight):Vehicle(_NO){
        this->guest = _guest;
        this->weight = _weight;
    }
    virtual int fee(){
        return this->guest * 8 + this->weight * 2;
    }
};


class Truck:public Vehicle{
private:
    int weight;
public:
    Truck(const string & _NO,const int & _weight):Vehicle(_NO){
        this->weight = _weight;
    }
    virtual int fee(){
        return this->weight * 5;
    }
};

class Bus:public Vehicle{
private:
    int guest;
public:
    Bus(const string & _NO,const int & _guest):Vehicle(_NO){
        this->guest = _guest;
    }
    virtual int fee(){
        return this->guest * 3;
    }
};

