#include <stdio.h>
void convent(int x);
int main(){
    char *str = "hahaha";
    fwrite(str,sizeof(char),6,stdout); 
    printf("%s\n","HelloWorld!"); 
    //printf("%s\n","HelloWorld!"); 
    //fwrite("HelloWorld!",sizeof(char),12,stdout); 
    //printf("");
    //convent(123);
    //putchar('\n');
    return 0;
}

void convent(int x){
    if ((x/8) != 0){
        convent(x/8);
        printf("%d",x%8);
    } else {
        printf("%d",x);
    }
}
