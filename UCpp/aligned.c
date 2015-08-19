#include <stdio.h>

typedef struct A{
    char a;
    double b;
    char c;
}A;

typedef struct B{
    char a;
    double b;
    char c;
}__attribute__((packed)) B;
int main()
{
    printf("sizeof A=%d\n", sizeof(A));

    printf("sizeof B=%d\n", sizeof(B));
}
