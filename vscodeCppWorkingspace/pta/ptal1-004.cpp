#include <iostream>
using namespace std;

int main(){
    int C = 0, F = 0;
    cin >> F;
    C = 5 * (F - 32) / 9;
    cout << "Celsius = " << C << endl;
    return 0;
}