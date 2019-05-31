#include <iostream>
#include <string>
using namespace std;
class Student{
private:
    std::string name;
    std::size_t score;
    std::size_t number;
    static std::size_t counter;
public:
    friend std::ostream &operator<<(std::ostream &out, Student & stu);
    friend std::istream &operator>>(std::istream &is, Student & stu);
};


std::ostream & operator << (std::ostream & out,Student & stu){
    std::string level = ((stu.score > 60) ? "PASS" : "FAIL");
    out << stu.number << ". " <<stu.name << " " << level;
    return out;
}

std::istream & operator >> (std::istream & is, Student & stu){
    Student::counter += 1;
    is >> stu.name >> stu.score;
    stu.number = Student::counter;
    return is;
}

std::size_t Student::counter = 0;
int main(){
    int i, repeat;
    Student st;
    cin>>repeat;
    for(i=0;i<repeat;i++){
        cin>>st;
        cout<<st<<endl;
    }
    return 0;
}