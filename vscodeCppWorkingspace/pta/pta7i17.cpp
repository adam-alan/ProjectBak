#include <iostream>
using namespace std;
int main(){
    int n = 0;
    int down = 0;
    int up = 0;
    cin >> n >> up >> down;
    int height = 0;
    int time = 0;
    for (time = 1;height < n;time++){
        if (time % 2 == 0){
            height -= down;
        } else {
            height += up;
        }

        if (height == n){
            break;
        }
    }
    cout << time << endl;
    return 0;
}