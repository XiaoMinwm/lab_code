#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    DIR* p = opendir(".");  //打开当前目录
    //if(p == NULL) {...}
    struct dirent* q;
    while((q = readdir(p)) != NULL) {
        if(q->d_name[0] == '.' ) continue;
        printf("%s\t", q->d_name);
    }
    printf("\n");
    closedir(p);
}
