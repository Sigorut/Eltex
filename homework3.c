//написать ФИ телефон 10 элементов (с меню) удалить(занулить структуру),
//добавить запись, поиск по любому полю, вывод всех записей
#define N 10
#include <stdio.h>
#include <stdlib.h>
struct user
{
    char *firstName;
    char *lastName;
    char *number;
};
void menu()
{
    printf("0 - Check book\n");
    printf("1 - Add\n");
    printf("2 - Delete\n");
    printf("3 - Search\n");
    printf("4 - Exit\n");
}
short int getKey()
{
    char key;
    printf(">");
    scanf("%c", &key);
    while (getchar() != '\n')
        ;
    while (key < 48 || key > 52)
    {
        system("clear");
        menu();
        printf("Input correct data! \n>");
        scanf("%c", &key);
        while (getchar() != '\n')
            ;
    }
    return key - 48;
}
void bToMenu()
{
    char key;
    printf("\n(Input any key to exit the menu)\n>");
    scanf("%c", &key);
    while (getchar() != '\n')
        ;
    system("clear");
}
int main()
{
    short int key;
    enum
    {
        check,
        add,
        delete,
        search,
        exit
    };
    struct user book[N];
    while (1)
    {
        menu();
        key = getKey();
        system("clear");
        switch (key)
        {
        case check:
            printf("open book\n");

            bToMenu();
            break;
        case add:
            printf("add book\n");

            bToMenu();
            break;
        case delete:
            printf("delete book\n");

            bToMenu();
            break;
        case search:
            printf("search book\n");

            bToMenu();
            break;
        case exit:
            return 0;
            break;
        default:
            break;
        }
        key = -1;
    }
}
