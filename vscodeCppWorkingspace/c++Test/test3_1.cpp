#include <iostream>

using namespace std;

class counter{
private:
    int value;
public: 
    counter(int num){
        this->value = num;
    }
    void increment(){
        this->value += 1;
    }
    void decrement(){
        this->value -= 1;
    }
    void print(){
        cout << this->value << endl;
    }
    int getvalue(){
        return this->value;
    }
};


int main(){
    counter my_counter(8);
    cout << "init counter : " << endl;
    my_counter.print();
    my_counter.increment();
    cout << "increse counter : " << endl;
    my_counter.print();
    my_counter.decrement();
    cout << "decrese counter : " << endl;
    my_counter.print();
    cout << "getvalue of counter: " << endl;
    cout << my_counter.getvalue() << endl;
    cout << my_counter.value << endl;
    return 0;
}