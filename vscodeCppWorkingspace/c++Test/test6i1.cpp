#include<iostream>
//复数类声明
class complex {
public:
    //外部接口
    complex(double r=0.0,double i=0.0):real(r),imag(i){
    
    }
    complex (const complex & other){
        *this = other;
    }

    //+重载为成员函数
    complex operator + (const complex & other){
        return complex(this->real + other.real, this->imag + other.imag);
    }
    //-重载为成员函数
    complex operator - (const complex & other){
        return complex(this->real - other.real, this->imag - other.imag);
    }
    
    //输出复数
    void display();
    complex & operator = (const complex & other){
        copythis(other.real, other.imag);
        return *this;
    }
private:
    //私有数据成员
    double real; //复数实部
    double imag; //复数虚部
    void copythis(const double & _real, const double & _imag){
        this->real = _real;
        this->imag = _imag;
    }
};


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
    complex c1(1, 1), c2(2, 2);
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