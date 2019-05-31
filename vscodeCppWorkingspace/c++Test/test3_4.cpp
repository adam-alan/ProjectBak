#include <iostream>

using namespace std;

class Score{
private:
    float computer;
    float english;
    float mathematics;
public:
    Score(){
        this->computer = 0;
        this->english = 0;
        this->mathematics = 0;
    }
    Score(float _computer,float _english,float _mathematics){
        this->computer = _computer;
        this->english = _english;
        this->mathematics = _mathematics;
    }    
    void print(){
    cout << "Computer score:    "   << this->computer    << endl
         << "english socre:     "    << this->english     << endl
         << "mathematics socre: " << this->mathematics << endl << endl;
    }
    void modify(float _computer,float _english,float _mathematics){
        this->computer = _computer;
        this->english = _english;
        this->mathematics = _mathematics;
    }    
    static void foo(){
        
    }
};


int main(){
    Score score1;
    cout << "socre1:" << endl;
    score1.print();
    score1.modify(100,100,100);
    cout << "modify socre1:" << endl;
    score1.print();
    
    Score score2(60,60,60);
    cout << "socre2:" << endl;
    score2.print();
    score2.modify(50,50,50);
    cout << "modify socre2:" << endl;
    score2.print();
    return 0;
}