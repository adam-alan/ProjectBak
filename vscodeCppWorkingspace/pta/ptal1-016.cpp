#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    vector<string> record;
    map<char, unsigned short> dict1;
    
    //字典1初始化
    int value = 0;
    for (auto i = '0'; i <= '9'; i++){
        dict1.insert(pair<char, unsigned short>(i, value));
        value += 1;
    }
    //初始化字典2
    map<unsigned short,char> dict2;
    
    {
        dict2.insert(pair<unsigned short, char>(0, '1'));
        dict2.insert(pair<unsigned short, char>(1, '0'));
        dict2.insert(pair<unsigned short, char>(2, 'X'));
        dict2.insert(pair<unsigned short, char>(3, '9'));
        dict2.insert(pair<unsigned short, char>(4, '8'));
        dict2.insert(pair<unsigned short, char>(5, '7'));
        dict2.insert(pair<unsigned short, char>(6, '6'));
        dict2.insert(pair<unsigned short, char>(7, '5'));
        dict2.insert(pair<unsigned short, char>(8, '4'));
        dict2.insert(pair<unsigned short, char>(9, '3'));
        dict2.insert(pair<unsigned short, char>(10, '2'));
    }

    //获取输入
    int n = 0;
    cin >> n;
    string tmp;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        record.push_back(tmp);
    }
    unsigned short len = record.size();

    for (auto iter = record.begin(); iter != record.end(); iter++){
        
        unsigned long pos = iter->find('X');
        if ( pos >= 0 && pos <= 16 ){
            record.erase(iter);
        }
    }

    
    const unsigned short weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    auto iter = record.begin();

    unsigned short weight_aver = 0;
    queue<string> the_queue;

    for (int i = 0; iter != record.end(); i++, iter++) {
        for (int j = 0; j < 17;j++){
            weight_aver += weight[j] * dict1[record[i][j]];
            //cout << dict1[record[i][j]];
            printf("%u", dict1[record[i][j]]);
        }
        cout << endl;
        //cout << weight_aver % 11 << " " << dict2[weight_aver % 11] << endl;
        printf("%u %c", weight_aver % 11, dict2[weight_aver % 11]);
        cout << endl;
        if (record[i][17] == dict2[weight_aver % 11])
        {
            the_queue.push(record[i]);
        }
    }

    if (the_queue.size() == len){
        cout << "All passed" << endl;
    } else {
        while (!the_queue.empty()){
            cout << the_queue.front() << endl;
            the_queue.pop();
        }
    }

    return 0;
}