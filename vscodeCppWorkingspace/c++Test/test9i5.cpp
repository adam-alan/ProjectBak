#include <string>
#include <iostream>
#include <cstring>

int main(){
    std::string str;
    std::string tmp;
    while (getline(std::cin,tmp)){
        str += tmp + "\n";
    }
    std::cout << str << std::endl;
    unsigned long long pos = 0;
    
    
    while ( (pos = str.find("Today",pos)) != std::string::npos ){
        str.replace(pos, strlen("Today"), "Tomorrow");
    }
    std::cout << str << std::endl;
    
    return 0;
}
