#include <iostream>
#include <algorithm>
using namespace std;

unsigned long factorial(int n,unsigned long result){
    if ( n == 1 || n == 0){
        return result;
    }
    return factorial(n - 1, n*result);
}

int main(){
    unsigned long result = 1;
    
    //cout << result << endl;

    unsigned short n;
    cin >> n;
    unsigned long sum = 0;
    for (int i = 1; i <= n;i++){
        sum += factorial(i, result);
    }
    cout << sum << endl;
    return 0;
}