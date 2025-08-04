#include <stdio.h>
struct hotel{
    char name[20], address[30];
    int number_of_rooms, rating;
};
int main(){
    struct hotel arr[3], temp;
    printf("Enter the details of the hotels:\n");
    for (int i = 0; i < 3; i++){
        printf("Enter the name of hotel %d: ", i + 1);
        scanf(" %[^\n]%*c", arr[i].name);
        printf("Enter the address of hotel %d: ", i + 1);
        scanf(" %[^\n]%*c", arr[i].address);
        printf("Enter the rating of hotel %d (out of 5): ", i + 1);
        scanf("%d", &arr[i].rating);
        printf("Enter the number of rooms in hotel %d: ", i + 1);
        scanf("%d", &arr[i].number_of_rooms);
    }
    for (int i = 0; i < 2; i++){
        for (int j = i + 1; j < 3; j++){
            if (arr[i].rating < arr[j].rating){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\nThe list of hotels according to their rating is:\n");
    for (int i = 0; i < 3; i++){
        printf("%s\n", arr[i].name);
    }
    return 0;
}
