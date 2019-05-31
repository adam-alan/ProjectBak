#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;
int main(){
    int i = 0;
    for (i = 0;i < 2;i++){
        //fflush(stdout);
        fork();
        cout << "-";        
    }
    wait(NULL);
    wait(NULL);
    return 0;
}