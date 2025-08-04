#include <stdio.h>
int main(){
    int a = 5678, first_digit, last_digit, sum;
    first_digit = a/1000;
    last_digit = a - ((a/10)* 10);
    sum = first_digit + last_digit;
    printf("%d", sum);
    return 0;
}