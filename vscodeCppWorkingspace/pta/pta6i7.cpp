#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
	
    //scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=1000; i<=9999; i++ ) {
        if ( IsTheNumber(i) ){
            cnt++;
        }
            
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

int IsTheNumber (const int N){

    int num = sqrt(N);
    int flag1 = 0,flag2 = 0;
    int number[10]={0};

    if (num *num == N){
        flag1 = 1;
    }
    num = N;
    while (num != 0){
        number[num%10]++;
        num /= 10;
    }
    for (int i = 0;i < 10;i++){
        if (number[i] >= 2){
            flag2 = 1;
        }
    }

    if (flag1 == 1 && flag2 == 1){
        return 1;
    } else {
        return 0;
    }
}