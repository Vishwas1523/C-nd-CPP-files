#include <stdio.h>
int main()
{
    int a = 123;
    char b = 'a';
    printf("%x\n", &a);
    printf("%x\n", &b);
    char *ptr = &b;
    printf("%d\n", *(ptr + 1));
    return 0;
}