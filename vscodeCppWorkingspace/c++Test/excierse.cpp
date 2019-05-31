#include <iostream>
#include <string>
using namespace std;
class Student{
public:
    int number;
    string name;
    float score;
    static float count;
    static float sum;
public:
    void print(){
        cout << "number: " << this->number << " "
             << "name: " << this->name << " "
             << "score: " << this->score << endl;
    }
    static void average(){
        cout << "sum is " << sum <<endl;
        cout << "count is " << count << endl;
        cout << "average is " << sum/count << endl;
    }
    static void init(){
       // Student::count = 0;
       // Student::sum = 0;
    }
    Student(int number1, string name1, float score1){
        //Student::count += 1;
        this->number = number1;
        this->name = name1;
        this->score = score1;
        //Student::sum += this->score;
    }


};
int main( )
{ 
//	Student::init( );
	Student stu1(1,"Bill",87); 
	stu1.print( );

	Student stu2(2,"Adam",91);
	stu2.print( );

	Student stu3(3,"David",96);
	stu3.print( );

	Student::average( ); //静态成员函数的调用	
	
	return 0;
}
