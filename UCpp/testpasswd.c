#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
int main(int argc, char* argv[])
{
    if(argc != 2) {
        printf("a.out path");
        return 0;
    }
    struct stat s;
    if(lstat(argv[1], &s) != 0) {
        puts("不存在");
        return 1;
    }
    printf("硬连接%lu, 用户名%s， 字节数%lu\n",
            s.st_nlink,
            getpwuid(s.st_uid) -> pw_name,
            s.st_size);
}
