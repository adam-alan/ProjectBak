#include <iostream>
#include <cstring>
using namespace std;
class Person {
public:
    Person(const char* s) { 
        name = new char[strlen(s)+1]; 
        strcpy(name, s); 
        cout << "Person" << endl;
    }
    ~Person() { 
        delete [] name; 
        cout << "~Person" << endl;
    }
protected:
    char * name;
};

class Student : public Person{
public:
    Student(const char * s): Person(s){
        cout << "Student" << endl;
    }
    ~Student(){
        cout << "~Student" << endl;
    }
};



int main(){
    Student test("LiHua");
    return 0;
}