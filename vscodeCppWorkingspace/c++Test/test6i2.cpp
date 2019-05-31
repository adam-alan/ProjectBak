#include <iostream>
class complex
{
public:
    complex(double r=0.0,double i=0.0):real(r),imag(i){

    }
    complex (const complex & other){
        *this = other;
    }

    //重载运算符+为友元函数
    friend complex operator + (complex c1,complex c2);
    //重载运算符-为友元函数
    friend complex operator - (complex c1,complex c2);
    complex & operator = (const complex & other){
        copythis(other.real, other.imag);
        return *this;
    }
    void display(); //显示复数的值

private:
//私有成员
    double real;
    double imag;
    void copythis(const double & _real, const double & _imag){
        this->real = _real;
        this->imag = _imag;
    }
};

complex operator + (complex c1,complex c2){
    return complex(c1.real + c2.real, c1.imag + c2.imag);
}
complex operator - (complex c1, complex c2){
    return complex(c1.real - c2.real, c1.imag - c2.imag);
}

//输出复数
void complex::display(){
    if (this->real != 0 && this->imag != 0){
        if (this->real > 0 && this->imag > 0){
            std::cout << this->real << " + " << this->imag << "i" << std::endl;
        } else if(this->real > 0 && this->imag < 0){
            std::cout << this->real << " - " << -this->imag << "i" << std::endl;
        } else if (this->real < 0 && this->imag > 0){
            std::cout << this->real << " + " << this->imag << "i" << std::endl;
        } else {
            std::cout << this->real << " - " << -this->imag << "i" << std::endl;
        }
    } else {
        if (this->real == 0 && this->imag != 0){
            std::cout << this->imag << "i" << std::endl;
        } else if (this->real != 0 && this->imag == 0){
            std::cout << this->real << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
    
}



int main(){
    complex c1(2, 2), c2(2, 2);
    std::cout << "c1 = ";
    c1.display();
    std::cout << "c2 = ";
    c2.display();
    complex c;
    std::cout << "c1 + c2 = ";
    c = c1 + c2;
    c.display();
    std::cout << "c1 - c2 = ";
    c = c1 - c2;
    c.display();
    return 0;
}