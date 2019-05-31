#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <string.h>

int main(int argc,char * argv[]){
    int which;
    id_t who;
    if (argc != 4 || strchr("pgu",argv[1][0]) == NULL){
        usageErr("%s {p|g|u} who priority\n"
                    "   set priority of:p = process;g = process group;"
                    "u = processes for user\n",argv[0]);
                    
    }
    return 0;
}