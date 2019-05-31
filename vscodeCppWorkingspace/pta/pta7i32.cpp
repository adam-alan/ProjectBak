#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
    vector<string> sentence;
    string s;
    string str;
    int counter = 0;

    while (!feof(stdin)){
        getline(cin,str);
        for (int i = 0;str[i];i++){
            if (str[i] == ' '){
                counter += 1;
            }
        }
        s += str;
    }

    if (counter == s.length()){ 
        exit(0);    
    }
    
    //重定向输入字符串
    istringstream isstream(s);

    while (isstream >> str){
        sentence.push_back(str);
    }
   
    for (vector <string>::iterator the_iterator = sentence.end()-1;the_iterator >= sentence.begin();the_iterator--){
        if (the_iterator == sentence.begin()){
            printf("%s",the_iterator->c_str());
        } else {
            printf("%s ",the_iterator->c_str());
        }
    }
    printf("\n");
    return 0;
}