#include <stdio.h>
int main(){
    FILE* ptr = NULL;
    ptr = fopen("wow.txt", "w+");
    fprintf(ptr, "\nWowwowowowowwowow");
    fclose(ptr);
    return 0;
}