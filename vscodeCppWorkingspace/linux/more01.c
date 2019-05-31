#include <stdio.h>
#include <stdlib.h>


#define PAGELEN 32
#define LINELEN 512

void do_more(FILE * fp);
int see_more(void);

int main(int argc,char * argv[]){
    FILE * fp = NULL;
    if (argc == 1){
        do_more(stdin);
    } else {
        while(--argc){
            if ((fp = fopen(*(++argv),"r")) != NULL){
                do_more(fp);
                fclose(fp);
            } else {
                exit(0);
            }
        }
    }
    putchar('\n');
    return 0;
}


void do_more(FILE * fp){
    char line[LINELEN];
    int num_of_lines = 0;
    int reply = 0;
    while (fgets(line,LINELEN,fp)) {
        if (num_of_lines == PAGELEN){
            reply = see_more();
            if (reply == 0) {
                break;
            } 
            num_of_lines -= reply;
        }

        if ( fputs(line,stdout) == EOF ) {
            exit(1);
        }
        num_of_lines++;
    }
}

int see_more() {
    char c = '\0';
    printf("\033[7m more? \033[m");
    
    while ( (c = getchar()) != EOF ) {
        if ( c == 'q' ) {
            return 0;
        } else if ( c == '\32') {
            return PAGELEN;
        } else if ( c == '\n' ) {
            return 1;
        }
    }
    return 0;
}
