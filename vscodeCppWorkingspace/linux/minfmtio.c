#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void minprintf(char * fmt,...){
    va_list ap;
    va_start(ap, fmt);

    int ival;
    double dval;
    char *sval;
    for (char *p = fmt; *p; p++)
    {
        if (*p != '%'){
            putchar(p);
            continue;
        }
        switch (*(++p)){
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap,double);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval;sval++){
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        }
    }
}

void minscanf(char * fmt,...){
    va_list ap;
    va_start(ap, fmt);

    int *ival;
    double *dval;
    unsigned *uval;
    char *sval;

    char * tmpformat = (char *)malloc(strlen(fmt));
    int cur = 0;
    for (char *p = fmt; *p; p++){
        if (*p != '%'){
            tmpformat[cur++] = *p;
            continue;
        }
        //保存格式
        while (*(p+1) && !isalpha(*(p+1))){
            tmpformat[cur++] = *(++p);
        }
        tmpformat[cur++] = *(++p);
        tmpformat[cur] = '\0';
        
        switch (*p){
            case 'd':
            case 'i':
                ival = va_arg(ap, int*);
                scanf(tmpformat, ival);
                break;
            case 'x':
            case 'X':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                uval = va_arg(ap, unsigned *);
                scanf(tmpformat, uval);
                break;
            case 'f':
                dval = va_arg(ap, double*); 
                scanf(tmpformat, ival);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf(tmpformat,sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
}


int main(){
    return 0;
}








