#include <stdio.h>
int main(){
    int a;
    printf("Enter the value of a:\n");
    scanf("%d", &a);
    if (a + 2 == 49)
    {
        printf("The value of this case is %d", 49);
    }
    else if (a + 2 == 48)
    {
        printf("The value of this case is %d", 48);
    }
    else printf("I am the default case!");
    return 0;
}