#include <stdio.h>

void add() {
    printf("Add selected\n");
}

void delete() {
    printf("Delete selected\n");
}

void exit_program() {
    printf("Exit selected\n");
}

typedef struct {
    char *name;
    void (*action)();
} MenuItem;

MenuItem menu[] = {
    {"Add", add},
    {"Delete", delete}, 
    {"Exit", exit_program}
};

int main() {
    int choice;

    int menu_size = sizeof(menu) / sizeof(menu[0]);

    for(int i = 0; i < menu_size; i++) {
        printf("%d. %s\n", i + 1, menu[i].name);
    }

    printf("Select option: ");
    scanf("%d", &choice);

    if(choice >= 1 && choice <= menu_size) {
        menu[choice - 1].action();
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}

