#include <iostream>
#include <string>
using namespace  std;

int main(){
    string temp;
    string in_str;
    string str1,str2;
    while(getline(cin,temp)){
        if (temp == "end"){
            cin >> str1;
            cin >> str2;
            break;
        } else {
            in_str += temp;
        }
    }

    int index = 0;
    while ((index = in_str.find(str1))!= -1){
        in_str.replace(index,str1.length(),str2);
    }
    for (int i = 0;in_str[i];i++){
        if (in_str[i] == '.'){
            cout << '.' << endl;
        }else {
            cout << in_str[i];
        }
    }
    return 0;
}
