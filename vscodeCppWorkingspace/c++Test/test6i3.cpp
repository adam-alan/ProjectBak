#include <cstring>
#include <iostream>

class String
{
public:
    // constructor
    String(const char *str = nullptr){
        alloc_and_create(str);
    }
    // copy constructor
    String(const String & other){
        alloc_and_create(other.m_data);
    }
    // destructor
    ~ String(void){
        clear_space();
    }
    
    //重载=运算符
    String & operator =(const char *str){
        clear_space();
        alloc_and_create(str);
        return *this;
    }
    //重载=运算符
    String & operator =(const String & other){
        clear_space();
        alloc_and_create(other.m_data);
        return *this;
    }
    //重载==运算符
    int operator==(const String & other){
        return strncmp(this->m_data, other.m_data, (this->_length > other._length) ? this->_length : other._length);
    }
    //重载==运算符
    int operator==(const char *str){
        return strncmp(this->m_data,str, (this->_length > strlen(str)) ? this->_length : strlen(str));
    }

    const char * c_str(){
        return this->m_data;
    }
    unsigned long length(){
        return this->_length;
    }
    friend std::ostream &operator << (std::ostream &out, const String & str);

    friend std::istream &operator >> (std::istream &in, String & str);

private:
    // used for storing the string
    char * m_data;
    unsigned long _length;

    void alloc_and_create(const char * str){
        
        if (str != nullptr){
            this->_length = strlen(str);
            this->m_data = new char[this->_length + 1]();
            strncpy(this->m_data, str, this->_length);
        } else {
            this->_length = 0;
            this->m_data = nullptr;
        }
    }

    bool is_alloced(){
        return (this->m_data != nullptr);
    }

    void clear_space(){
        if (is_alloced()){
            delete this->m_data;
        }
    }
};

std::ostream & operator << (std::ostream & out,const String & str){
    printf("%s", str.m_data);
    return out;
}
std::istream & operator >> (std::istream & in, String & str){
    scanf("%s", str.m_data);
    return in;
}

int main(){
    String s1(nullptr);
    String s2(nullptr);
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    return 0;
}
