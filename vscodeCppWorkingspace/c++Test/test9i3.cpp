#include <string>
#include <map>
#include <iostream>


int main(){
    std::map<std::string, std::string> phone_dict;
    std::string name, phone_number;
    while (std::cin >> name >> phone_number){
        phone_dict.insert(std::pair<std::string, std::string>(name, phone_number));
    }

    for (auto iter = phone_dict.begin(); iter != phone_dict.end();iter++){
        std::cout << iter->first << "\t" << iter->second << std::endl;
    }
    return 0;
}
