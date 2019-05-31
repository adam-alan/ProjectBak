#include <string>
#include <iostream>
using namespace std;


int main(){
    string str;
    while (cin >> str){
        char c = '\0';
        for (int i = 0;str[i];i++){
            c = str[i];
            if (str.find_first_of(&c,0,i+1) == i){
                cout << str[i];
            }
            
        }  
        cout << endl; 
    }
    return 0;
}
