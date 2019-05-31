#include <iostream>
using namespace std;

class Fraction{
private:
    int molecule;       //分子
    int denominator;    //分母
    int gcd(int a,int b);                           //最大公因数
    void foftacd(Fraction & obj);                   //通分
    void reduction();                               //约分
    int mcm(int a,int b);                           //最小公倍数

public:
    Fraction();                                     //无参构造
    Fraction(const Fraction & obj);                 //拷贝构造
    Fraction(int _molecule,int _denominator);       //有参构造
    
   
    Fraction operator + (Fraction & obj);           //重载 +
    Fraction & operator / (int num);                //重载 /
    friend ostream & operator << (ostream & os,Fraction & obj);          //重载 <<
    friend istream & operator >> (istream & is,Fraction & obj);
    int get_molecule(){
        return this->molecule;
    }
    void set_molecule(int _molecule){
        this->molecule = _molecule;
    }
    int get_denominator(){
        return this->denominator;
    }
    void set_denominator(int _denominator){
        this->denominator = _denominator;
    }
};

Fraction::Fraction(){
    this->molecule = 0;
    this->denominator = 1;
}

Fraction::Fraction(int _molecule,int _denominator){
    this->molecule = _molecule;
    this->denominator = _denominator;
}

Fraction::Fraction(const Fraction & obj){
    this->molecule = obj.molecule;
    this->denominator = obj.denominator;
}

int Fraction::gcd(int a,int b){
    return (b == 0) ? a : gcd(b,a % b);
}

int Fraction::mcm(int a,int b){
    int num = gcd(a,b);
    return a * b / num;
}

void Fraction::reduction(){
    int num = gcd(this->molecule,this->denominator);
    this->molecule /= num;
    this->denominator /= num;
}

void Fraction::foftacd(Fraction & obj){
    int num = mcm(this->denominator,obj.denominator);
    this->molecule *= num / this->denominator;
    this->denominator *= num / this->denominator;
    obj.molecule *= num / obj.denominator;
    obj.denominator *= num / obj.denominator;
    //cout << this->molecule << "  " << this->denominator << endl;
    //cout << obj.molecule << "  " << obj.denominator << endl;
}

Fraction Fraction::operator + (Fraction & obj){
    foftacd(obj);
    Fraction sum;
    sum.set_molecule(this->molecule + obj.molecule);
    sum.set_denominator(this->denominator);
    sum.reduction();
    return sum;
}

Fraction & Fraction::operator / (int num){
    this->denominator *= num;
    this->reduction();
    return *this;
}

ostream & operator << (ostream & os,Fraction & obj){
    if (obj.denominator == 1){
        os << obj.molecule;
    } else {
        os << obj.molecule << "/" << obj.denominator;
    }
    return os;
}

istream & operator >> (istream & is,Fraction & obj){
    int molecule = 0;
    int denominator = 1;
    scanf("%d/%d",&molecule,&denominator);
    obj.set_molecule(molecule);
    obj.set_denominator(denominator);
    return is;
}

int main(){
    Fraction num1;
    Fraction num2;
    cin >> num1 >> num2;
    Fraction sum = (num1 + num2);  
    cout << sum << endl;
    return 0;
}