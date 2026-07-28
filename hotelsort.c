#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    char *location;
    int rating;
} Hotel;

int compare_by_rating(const void *a, const void *b)
{
    const Hotel *p1 = a;
    const Hotel *p2 = b;
    return p1->rating - p2->rating;
}

char *alloc_name(int i);
char *alloc_location(void);
int alloc_rating(void);

int main(void)
{

    int n;
    printf("How many hotel's do you want in your database: ");
    scanf("%d", &n);
    getchar();

    Hotel *list = malloc(n * sizeof(Hotel));
    if (!list)
        return 1;

    for (int i = 0; i < n; i++)
    {
        list[i].name = alloc_name(i);
        if (!list[i].name)
            return 1;
        list[i].location = alloc_location();
        if (!list[i].location)
            return 1;
        list[i].rating = alloc_rating();
    }

    // for(int j = 0; j<n; j++){
    //     printf("\n%s\n", list[j].name);
    //     printf("%s\n", list[j].location);
    //     printf("%d\n", list[j].rating);
    // }

    qsort(list, n, sizeof(Hotel), compare_by_rating);

    int j = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d.) Name: %s | Location: %s | Rating: %d\n", j, list[i].name, list[i].location, list[i].rating);
        j++;
    }

    for (int i = 0; i < n; i++)
    {
        free(list[i].name);
        free(list[i].location);
    }

    free(list);
    return 0;
}

char *alloc_name(int i)
{
    printf("\nHOTEL %d\n", i + 1);

    char *name = malloc(128);
    if (!name)
        return NULL;

    printf("Enter name of hotel: ");
    if (fgets(name, 128, stdin) != NULL)
    {
        name[strcspn(name, "\n")] = '\0';
    };

    return name;
}

char *alloc_location(void)
{
    char *name = malloc(128);
    if (!name)
        return NULL;

    printf("Enter the location of hotel: ");
    if (fgets(name, 128, stdin) != NULL)
    {
        name[strcspn(name, "\n")] = '\0'; // name[index of position of \n] is set to string end charachter '\0'
    };

    return name;
}

int alloc_rating(void)
{
    printf("Rating of your Hotel(0-100): ");
    int rating;
    if (scanf("%d", &rating) != 1)
    {
        printf("\nInvalid Input Please Re-enter");
        getchar();
        return alloc_rating();
    }

    if (rating < 0 || rating > 100)
    {
        printf("\nPlease enter a rating between 0 and 100.\n");
        return alloc_rating();
    }

    getchar();

    return rating;
}