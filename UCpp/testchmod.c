#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    rename(argv[0], "furong");
    symlink("furong", "lfr");
    chmod("furong", 0555);
    if(access("furong", F_OK) == 0) puts("furong存在");
    if(access("furong", R_OK) == 0) puts("可读");
    if(access("furong", W_OK) == 0) puts("可写");
    if(access("furong", X_OK) == 0) puts("可执行");

}
