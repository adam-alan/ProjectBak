#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);
    
    long pos = 0;

    while ((pos = s1.find(s2,0)) != string::npos){
        s1.erase(pos,s2.size());
    }
    cout << s1 << endl;
    return 0;
}