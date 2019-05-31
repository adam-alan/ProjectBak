#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 0;
    int k = 0;
    vector<int> array;
    int num = 0;
    cin >> n >> k;
    for (int i = 0;i < n;i++){
        cin >> num;
        array.push_back(num);
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
            printf("%d",array[i]);
        } else {
            printf("%d ",array[i]);
        }
    }
    cout << endl;
    return 0;
}