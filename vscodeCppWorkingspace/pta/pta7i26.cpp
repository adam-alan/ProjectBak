#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    string str;
    vector<string> sentence;

    getline(cin, str);
    int counter = 0;
    for (int i = 0; str[i]; i++){
        if (str[i] == ' '){
            counter++;
        }
    }

    if (counter == str.length()){
        return 0;
    }

    istringstream ss(str);
    string s;
    while (ss >> s){
        sentence.push_back(s);
    }
    string * the_end = &(*(sentence.end() - 1));
    the_end->erase(the_end->size() - 1, 1);
   // cout << the_end->size() << " " << the_end;
    for (auto iter:sentence){
      
        if (iter == *(sentence.end() - 1)){
            break;
        }
        cout << iter.size() << " ";
    }
    cout << the_end->size();
    //cout << endl;
    return 0;
}