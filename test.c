#include <stdio.h>
int main(){
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    int i = 0;
    while(i <= 10){
        printf(" %d ", arr[i]);
        i++;
    }
    return 0;
}