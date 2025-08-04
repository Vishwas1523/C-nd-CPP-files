#include <stdio.h>

int main(){
    FILE *ptr = fopen("wow.txt", "r");
    char str[50];

    if (ptr == NULL)
    {
        printf("File could not be opened!\n");
        return 1;
    }

    while (fgets(str, sizeof(str), ptr) != NULL)
    {
        printf("%s", str);
    }
    fclose(ptr);
    return 0;
}
