#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <time.h>

void ListDetail(void)
{
    DIR* p = opendir(".");
    if(p == NULL) {
        perror("opendir");
        return;
    }
    struct dirent* q = NULL;
    while((q=readdir(p)) != NULL) {
        if(q->d_name[0] == '.') continue;
    }
}

int main(int argc, char * argv[])
{
    if(argc > 2) {
        printf("%s [目录路径]\n", argv[0]);
        return 0;
    }
    if(argc == 2) {
        if(chdir(argv[1]) < 0) {
            perror("错误");
            return -1;
        }
    }

    ListDetail();
}
