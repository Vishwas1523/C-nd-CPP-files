#include <stdio.h>
struct train_reservation
{
    char name[20];
    int price, code;
};
int main()
{
    struct train_reservation arr[10];
    printf("Enter the details:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Name: ");
        scanf("%s", arr[i].name);
        printf("Code: ");
        scanf("%d", &arr[i].code);
        printf("Price (in rupees): ");
        scanf("%d", &arr[i].price);
    }
    printf("\n\n_________________________________________________________________________\n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("| Name:     %s\n", arr[i].name);
        printf("| Code:     %d\n", arr[i].code);
        printf("| Price:    %d\n", arr[i].price);
        if (i + 1 < 6)
        {
            printf("| Status:    Confirm\n");
        }
        else if (i + 1 > 9)
        {
            printf("| Status:    Regret\n");
        }
        else
            printf("| Status:   Waiting\n");
        printf("\n\n_________________________________________________________________________\n\n");
    }

    return 0;
}