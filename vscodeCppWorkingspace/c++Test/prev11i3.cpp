#include <iostream>
using namespace std;
class CMyClassA {
    int val;
public:
    CMyClassA(int);
    void virtual print();
};
CMyClassA::CMyClassA(int arg) {
    val = arg;
    printf("A:%d\n", val);
}
void CMyClassA::print() {
    printf("%d\n", val);
    return;
}

class CMyClassB:public CMyClassA
{
private:
    int val;

public:
    CMyClassB(const int & _val):CMyClassA(_val*3){
        this->val = _val;
        printf("B:%d\n", this->val);
    }
    void virtual print(){
        printf("%d\n", val);
    }
    ~CMyClassB(){

    }
};



int main(int argc, char** argv) {
    CMyClassA a(3), *ptr;
    CMyClassB b(5);
    ptr = &a;
    ptr->print();
    a = b;
    a.print();
    ptr = &b;
    ptr->print();
    return 0;
}
