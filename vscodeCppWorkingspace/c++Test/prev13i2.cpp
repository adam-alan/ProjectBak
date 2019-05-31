#include <iostream>
#include <string>
#include <list>
using namespace std;

class Student {
   string name;
   char sex;
   int score;
   string grade;

public:
   Student(string name, char sex, int score, string grade);
   friend ostream &operator<< (ostream& os, Student st) ;
   friend bool operator<(Student &st1, Student &st2);	
};

Student::Student(string name, char sex, int score, string grade) {
   this->name = name;
   this->sex = sex;
   this->score = score;
   this->grade = grade;
}
ostream &operator<< (ostream& os, Student st){
    os << st.name << " " << st.sex << " " << st.score << " " << st.grade << endl;
    return os;
}

bool operator<(Student &st1, Student &st2){
    return st1.score < st2.score;
}

int main() {
   list<Student> st;
   string name, grade;
   char sex;      int score;
	
   for(int i = 0; i < 5; i++) {
      cin>>name;      cin>>sex;
      cin>>score;       cin>>grade;
      st.push_back(Student(name, sex, score, grade));
   }

   st.sort();

   list<Student>::iterator p = st.begin();
   while(p != st.end()) {
      cout<<*p;
      p++;
   }
   return 0;
}