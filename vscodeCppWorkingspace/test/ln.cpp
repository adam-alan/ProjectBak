#include <iostream>
#include <cmath>
#include <list>
using namespace std;
double ln(double x);
 

int main()
{
    
    auto fxy = [](int x, int y) -> int {
        int ans = 1;
        while (y != 0)
        {
            ans = ((y & 1) == 1) ? ans * x : ans;
            y >>= 1;
            x *= x;
        }
        return ans;
    };

    cout << fxy(2, 8) << endl;
    cout << ln(4) << endl;
    cout << log(4) << endl;
    return 0;
}

double ln(double x){
    double u = (x - 1) / (x + 1);
    double odd_number = 1;
    double temp = 1;
    double sum = 1;
   
    while (temp > 1e-06)
    {
        odd_number += 2;
        u *= u;
        temp = u / odd_number;
        sum += temp;
    }
    return 2 * ((x - 1) / (x + 1))* sum;
}
