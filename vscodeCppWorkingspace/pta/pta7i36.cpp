#include <iostream>
#include <complex>
using namespace std;
/*
class Complex{
private:
    double real;
    double imag;
public:
    Complex(){
        this->real = 0;
        this->imag = 0;
    }

    Complex(double _real,double _imag){
        this->real = _real;
        this->imag = _imag;
    }

    Complex(const Complex & obj){
        this->real = obj.real;
        this->imag = obj.imag;
    }
    Complex operator+(const Complex & obj){
        Complex complex;
        complex.set_real(this->get_real() + obj.get_real());
        complex.set_imag(this->get_imag() + obj.get_imag());
        return complex;
    }

    Complex operator-(const Complex & obj){
        Complex complex;
        complex.set_real(this->get_real() + obj.get_real());
        complex.set_imag(this->get_imag() + obj.get_imag());
        return complex;
    }
    void set_real(double _real){
        this->real = _real;
    }

    double get_real()const{
        return this->real;
    }
    
    void set_imag(double _imag){
        this->imag = _imag;
    }

    double get_imag()const{
        return this->imag;
    }
};
*/

void print_complex_result(const complex<double>  & obj){
    if (obj.imag() != 0.000000 && obj.real() != 0.000000){
        printf(" = %.1lf + %.1lfi\n",obj.real(),obj.imag());
    } else if (obj.imag() == 0.000000 && obj.real() != 0.000000){
        printf(" = %.1lf\n",obj.real());
    } else if (obj.imag() != 0.000000 && obj.real() == 0.000000){
        printf(" = %.1lf\n",obj.imag());
    } else {
        printf(" = 0.0\n");
    }
}

void print_two_complex(const complex<double>  & obj1,char oprtor,const complex<double>  & obj2){
    switch (oprtor){
        case '+':
            printf("(%.1lf + %.1lf) + (%.1lf + %.1lf)",obj1.real(),obj1.imag(),obj2.real(),obj2.imag());
            break;
        case '-':
            printf("(%.1lf + %.1lf) - (%.1lf + %.1lf)",obj1.real(),obj1.imag(),obj2.real(),obj2.imag());
            break;
        case '*':
            printf("(%.1lf + %.1lf) * (%.1lf + %.1lf)",obj1.real(),obj1.imag(),obj2.real(),obj2.imag());
            break;
        case '/':
            printf("(%.1lf + %.1lf) / (%.1lf + %.1lf)",obj1.real(),obj1.imag(),obj2.real(),obj2.imag());
            break;
    }
}


int main(){
    
    double real = 0,imag = 0;
    cin >> real >> imag;
    complex<double> num1(real,imag);
    cin >> real >> imag;
    complex<double> num2(real,imag);
    string oprtor = "+-*/";
    complex<double> result;
    for (int i = 0;i < 4;i++){
        switch (oprtor[i])
        {
            case '+':
                result = num1 + num2;
                print_two_complex(num1,'+',num2);
                print_complex_result(result);
                break;
            case '-':
                result = num1 - num2;
                print_two_complex(num1,'-',num2);
                print_complex_result(result);
                break;
            case '*':
                result = num1 * num2;
                print_two_complex(num1,'*',num2);
                print_complex_result(result);
                break;
            case '/':
                result = num1 / num2;
                print_two_complex(num1,'/',num2);
                print_complex_result(result);
                break;
        }
    }
    return 0;
}