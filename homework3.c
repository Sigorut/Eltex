//написать ФИ телефон 10 элементов (с меню) удалить(занулить структуру),
//добавить запись, поиск по любому полю, вывод всех записей
#define N 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct User
{
    char firstName[32];
    char lastName[32];
    char number[32];
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
void openRecords(struct User *book, short int exR[])
{
    short int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (exR[i] == 1)
        {
            printf("%hd)\t%s\t%s\t%s\n", count, book[i].number, book[i].firstName, book[i].lastName);
            count++;
        }
    }
}
void addRecords(struct User *book, short int *exRec)
{
    for (int i = 0; i < N; i++)
    {
        if (exRec[i] == 0)
        {
            printf("Input firsname,lastname, number\n >");
            scanf("%s", book[i].firstName);
            scanf("%s", book[i].lastName);
            scanf("%s", book[i].number);
            exRec[i] = 1;
            break;
        }
    }
}
void delRecords(struct User *book, short int *exRec, int hmRec)
{
    short int indexEntryForDel;
    openRecords(&book[0], exRec);
    printf("Which entry to delete?\n");
    scanf("%hd", &indexEntryForDel);
    while (getchar() != '\n')
        ;
    while (indexEntryForDel > hmRec - 1 || indexEntryForDel < 0)
    {
        system("clear");
        openRecords(&book[0], exRec);
        printf("Input correct data! \n>");
        printf("Which entry to delete?\n");
        scanf("%hd", &indexEntryForDel);
        while (getchar() != '\n')
            ;
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (count == indexEntryForDel)
        {
            memset(book[i].firstName, '\0', sizeof(book[i].firstName));
            memset(book[i].lastName, '\0', sizeof(book[i].lastName));
            memset(book[i].number, '\0', sizeof(book[i].number));
            exRec[i] = 0;
            break;
        }
        if (exRec[i] == 1)
        {
            count++;
        }
    }
}
void searchRecords(struct User *book, short int exRec[])
{
    char enty[32];
    short int count = 0;
    short int exLocRec[N];
    for (int i = 0; i < N; i++)
    {
        exLocRec[i] = exRec[i];
    }
    printf("Search record by number\n");
    scanf("%s", enty);
    while (getchar() != '\n')
        ;
    for (int i = 0; i < N; i++)
    {
        if (exLocRec[i] == 1)
        {
            count = 0;
            while (enty[count] != '\0')
            {
                if (book[i].number[count] != enty[count])
                {
                    exLocRec[i] = 0;
                    break;
                }
                count++;
            }
        }
    }
    system("clear");
    printf("Searching results\n");
    openRecords(&book[0], exLocRec);
}
int main()
{

    short int key;
    struct User book[N];
    short int exRecords[N] = {0};
    short int hmRecords = 0;
    enum
    {
        check,
        add,
        delete,
        search,
        exit
    };

    while (1)
    {
        menu();
        key = getKey();
        system("clear");
        switch (key)
        {
        case check:
            printf("open book\n");
            if (hmRecords == 0)
            {
                printf("Book is empty...(\n");
            }
            else
            {
                openRecords(&book[0], exRecords);
            }
            bToMenu();
            break;
        case add:
            printf("add book\n");
            if (hmRecords == N)
            {
                printf("Book is full...(\n");
            }
            else
            {
                addRecords(&book[0], &exRecords[0]);
                hmRecords++;
            }
            bToMenu();
            break;
        case delete:
            printf("delete book\n");
            if (hmRecords == 0)
            {
                printf("Book is empty...(\n");
            }
            else
            {
                delRecords(&book[0], &exRecords[0], hmRecords);
                hmRecords--;
            }
            bToMenu();
            break;
        case search:
            printf("search book\n");
            if (hmRecords == 0)
            {
                printf("Book is empty...(\n");
            }
            else
            {
                searchRecords(&book[0], exRecords);
            }
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
