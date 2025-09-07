#include <stdio.h>
int main()
{
    int a = 10;
    int c = a++ + ++a;
    printf("%d", c);
    return 0;
}