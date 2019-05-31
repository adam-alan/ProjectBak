#include <iostream>
using namespace std;
class Rectangle{
private:
    double width;
    double length;
public:
    double getArea(){
        return this->length * this->width;
    }
    Rectangle(int _width,int _length){
        this->width = _width;
        this->length = _length;
    }
};


int main(){
    Rectangle rectangle(5,60);
    cout << rectangle.getArea() << endl;
    return 0;
}