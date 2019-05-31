#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct student_infor{
    
    unsigned int seat_number;
    string ticket_number;
    
    student_infor(string _ticket_number,unsigned int _seat_number){
        this->ticket_number = _ticket_number;
        this->seat_number = _seat_number;
    }
};

int main(){
    map<unsigned int,student_infor> dict;
    unsigned int exam_seat_number;
    string input_ticket_number;
    unsigned test_seat_number;
    
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input_ticket_number >> test_seat_number >> exam_seat_number;
        dict.insert(pair<unsigned int,student_infor>(test_seat_number,student_infor(input_ticket_number, exam_seat_number)));
    }

    int m = 0;
    cin >> m;
    vector<unsigned int> input;
    for (int i = 0; i < m; i++){
        int number = 0;
        cin >> number;
        input.push_back(number);
    }

    vector<unsigned int>::iterator iter;
    for (iter = input.begin(); iter != input.end();iter++){
        //cout << *iter << endl;
        auto result = dict.find(*iter);
        cout << result->second.ticket_number << " " << result->second.seat_number << endl;
    }

    return 0;
}