#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1,s2;
    while ( cin >> s1 >> s2){
        int max = 0;
        for (int i = 0;s1[i] && s2[i];i++){
            //cout << s1.substr(0,i) << "   " << s2.substr(0,i) <<endl;
            if (s1.substr(0,i) == s2.substr(0,i)){
                max = i;
            }
        }
        if (max){
            cout << "The common prefix is ";
            cout << s1.substr(0,max) << endl;
        } else {
            cout << "No common prefix" << endl;
        }
    }
    return 0;
}   