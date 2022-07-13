#define ROW 5
#define COL 5
#define NUM 10
#include <stdio.h>
void coutMass(int *mass, int, int);
void fillMass(int *mass, int, int);
void invMass(int *mass, int);
void filltrMass(int *mass, int, int);
void fillsnMass(int *mass, int, int);
int main()
{
    int twMass[ROW][COL];
    int onMass[NUM];
    //#1
    printf("#1 Filling massive: \n");
    fillMass(&twMass[0][0], ROW, COL);
    coutMass(&twMass[0][0], ROW, COL);
    printf("\n\n");
    //#2
    for (int i = 1; i <= NUM; i++)
    {
        onMass[i - 1] = i;
    }
    printf("#2 Invert massive: \n");
    coutMass(&onMass[0], 1, NUM);
    invMass(&onMass[0], NUM);
    coutMass(&onMass[0], 1, NUM);
    printf("\n\n");
    //#3
    printf("#3 Filling triangle massive: \n");
    filltrMass(&twMass[0][0], ROW, COL);
    coutMass(&twMass[0][0], ROW, COL);
    printf("\n\n");
    //#4
    printf("#3 Filling snail massive: \n");
    fillsnMass(&twMass[0][0], ROW, COL);
    coutMass(&twMass[0][0], ROW, COL);
    return 0;
}

void coutMass(int *mass, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", mass[i * c + j]);
        }
        printf("\n\n");
    }
}
void fillMass(int *mass, int r, int c)
{
    int count = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mass[i * c + j] = count;
            count++;
        }
    }
}
void invMass(int *mass, int num)
{
    int swap;
    for (int i = 0; i < num / 2; i++)
    {
        swap = mass[i];
        mass[i] = mass[num - 1 - i];
        mass[num - 1 - i] = swap;
    }
}
void filltrMass(int *mass, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mass[i * c + j] = (j < (c - i - 1)) ? 0 : 1;
        }
    }
}
void fillsnMass(int *mass, int r, int c)
{
    int count = 1;
    int genItter = r;
    int itter = 0;
    int itterInv = r - 1;
    for (int i = 0; i < r; i++)
    {
        if (i % 2 == 0)
        {
            for (int k = 0; k < genItter; count++, k++)
            {
                mass[itter * c + k + itter] = count;
            }
            for (int j = 1; j < genItter; count++, j++)
            {
                mass[(j + itter) * c + c - 1 - itter] = count;
            }
            itter++;
            genItter--;
        }
        else
        {
            for (int k = genItter - 1; k >= 0; count++, k--)
            {
                mass[itterInv * c + k + itter - 1] = count;
            }
            for (int j = genItter - 1; j >= 1; count++, j--)
            {
                mass[(j + itter - 1) * c + itter - 1] = count;
            }
            itterInv--;
            genItter--;
        }
    }
}