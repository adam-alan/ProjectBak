#include <stdio.h>

void Print_Factorial ( const int N );


int main(){
    int N;
	
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

unsigned long factorial(int n){
    if (n < 0){
        return 0;
    }
    if (n == 0 || n == 1){
        return 1;
    }
    return n*factorial(n-1);
}

void Print_Factorial (const int N){
    if ( N >= 0){
        printf("%lu\n",factorial(N));
    } else {
        printf("Invalid input\n");
    }
}