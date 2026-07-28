#include <stdio.h>
int main() { 
    int a = 1111;
    int* ptr = &a;
    char* ctr = (char*)&a;
    ctr++;
    printf("%p", ctr);
    return 0;
}