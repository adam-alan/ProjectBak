#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    string input_str;
    cin >> input_str;
    map<char, unsigned int> dict;

    for (int i = 0; input_str[i];i++){
        ++dict[input_str[i]];
    }
    map<char, unsigned int>::iterator iter;
    for (iter = dict.begin(); iter != dict.end();iter++){
        cout << iter->first << " " << iter->second << endl;
    }

    return 0;
}