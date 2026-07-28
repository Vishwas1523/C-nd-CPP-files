#include <stdio.h>
int main()
{
    int a = 0x3c;
    printf("%x\n", a);
    a <<= 1;
    printf("%x\n", a);
    a |= (1 << 0);
    printf("%x\n", a);
    return 0;
}