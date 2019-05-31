#include <iostream>
#include <string>
using namespace std;

int main(){
    string dict[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string s;
    cin >> s;
    bool flag = false;
    if (s[0] == '-'){
        cout << "fu" << " ";
        flag = true;
    }
    for (int i = 0;s[i];i++){
        if (i == 0 && flag == true){
            continue;
        }
        if (s[i+1] == '\0'){
            cout << dict[s[i]-48];    
        } else {
            cout << dict[s[i]-48] << " ";    
        }
       
    }
    cout << endl;
    return 0;
}