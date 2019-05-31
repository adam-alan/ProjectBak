#include <iostream>
#include <string>
using namespace std;


int main(){
    
    string s;
    getline(cin,s);
    

    int n = 0;
    cin >> n;

    while (n--){
        char c = *s.begin();
        s.insert(s.end(),1,c);
        s.erase(0,1);
    }
    cout << s << endl;
}