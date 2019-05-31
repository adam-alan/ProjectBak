#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#define oops(m, x)  \
{                   \
        perror(m);  \
        exit(x);    \
}

void be_dc(int in[2], int out[2]);
void be_bc(int to_dc[2], int from_dc[2]);

int main(){
    pid_t pid;
    int to_dc[2], from_dc[2];
    if (pipe(to_dc) == -1 || pipe(from_dc) == -1){
        oops("pipe failed", 1);
    }


    if ((pid = fork()) == -1){
        oops("can not fork", 2);
    } else if (pid == 0){
        be_dc(to_dc, from_dc);
    } else {
        be_bc(to_dc, from_dc);
    }
    return 0;
}

void be_dc(int in[2], int out[2]){
    if (dup2(in[0],0) == -1){
        oops("dc:can not redirect stdin", 3);
    }
    close(in[0]);
    close(in[1]);
    if (dup2(out[1],1) == -1){
        oops("dc:can not redirect stdout", 4);
    }
    close(out[1]);
    close(out[0]);
    execlp("dc", "dc", "-", NULL);
    oops("Can not run dc", 5);
}
