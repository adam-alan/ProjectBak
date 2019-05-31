#include <iostream>

using namespace std;

class Date{
private:
    int _days;
    int _mouth;
    int _year;
public:
    int day()const{
        return this->_days;
    }
    int mouth()const{
        return this->_mouth;
    }
    int year()const;
};

int Date::year()const{
    return this->_year;
}