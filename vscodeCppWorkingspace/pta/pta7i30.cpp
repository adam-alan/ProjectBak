#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n = 0;
    int k = 0;
    vector<string> array;
    string str;
    cin >> n >> k;
    for (int i = 0;i < n;i++){
        cin >> str;
        array.push_back(str);
    }
    int conuter = 0;
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n - i -1;j++){
            if (array[j] > array[j+1]){
                swap(array[j],array[j+1]);
            }
        }
        conuter += 1;
        if (conuter == k){
            break;
        }             
    }
   
    for (int i = 0;i < n;i++){
        if ( i == n - 1 ) {   
            printf("%s\n",array[i].c_str());
        } else {
            printf("%s\n",array[i].c_str());
        }
    }
    return 0;
}