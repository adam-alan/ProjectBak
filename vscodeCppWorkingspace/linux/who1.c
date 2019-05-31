#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define SHOWHOST

void show_info(struct utmp * utbufp);
void showtime(long timeval);

int main(int argc,char *argv[]){
    struct utmp current_record;
    int utmpfd = 0;
    int reclen = sizeof(struct utmp);
    

    if ( (utmpfd = open(UTMP_FILE,O_RDONLY)) == -1){
        perror(UTMP_FILE);
        exit(1);
    }

    while ( read(utmpfd,&current_record,reclen) == reclen){
        show_info(&current_record);
    }

    return 0;
}


void show_info(struct utmp * utbufp) {
    if ( utbufp->ut_type != USER_PROCESS) {
        return;
    }

    printf("%-12s",utbufp->ut_name);
    printf(" ");
    printf("%-12s",utbufp->ut_line);
    printf(" ");
    showtime(utbufp->ut_time);
    #ifdef SHOWHOST
    if ( utbufp->ut_host[0] != '\0') {
        printf("(%s)",utbufp->ut_host);
    }
    #endif    
    printf("\n");
}


void showtime(long timeval){
    char * cp;
    cp = ctime(&timeval);
    printf("%-12.12s",cp+4);
}