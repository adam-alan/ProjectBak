#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
	
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}
#include <math.h>

int Count_Digit (const int N,const int D){
    int number[10]={0};
    int num = abs(N);
    while (num != 0){
        number[num%10]++;
        num /= 10;
    }
    if (N == 0){
        return 1;
    }
    return number[D];
}