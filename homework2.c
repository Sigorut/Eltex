#include <stdio.h>
//Вывести число по байтам и заменить 3 байт
void uItoBin(int);
void swap(int *, int *);
int main()
{
    int number = 500;
    uItoBin(number);
    char *pointer;
    pointer = (char *)&number;
    printf("Pointer*  = %d - 4byte\n", *pointer);
    *pointer = 2; // замена 4го байта числа на 0000 0010
    pointer += (char)1;
    printf("Pointer*  = %d - 3byte\n", *pointer);
    uItoBin(number);
}
void swap(int *a, int *b)
{
    int *temp;
    temp = a;
    a = b;
    b = temp;
}
void uItoBin(int num)
{
    if (num < 0)
    {
        printf("\n(uItoBin)Only positive numbers!\n");
        return;
    }
    int binNum[32] = {0}, count = 0;
    while (num != 0)
    {
        binNum[count] = (num % 2 == 0) ? 0 : 1;
        num = num >> 1;
        count++;
    }
    for (int i = 0; i < count / 2; i++)
    {
        swap(&binNum[i], &binNum[32 - i]);
    }
    for (int i = 31; i >= 0; i--)
    {
        if ((i + 1) % 8 == 0 && i != 0 && i + 1 != 32)
        {
            printf(" ");
        }
        printf("%d", binNum[i]);
    }
    printf("\n");
}