#include <stdio.h>
#include <conio.h>
#include <math.h>
#define Max 4

int a = 0, b = 0, c = 0, a1 = 0, b1 = 0, com[Max];
int anum[Max] = { 0 }, anumcp[Max] = { 0 }, bnum[Max] = { 0 };
int acomp[Max] = { 0 }, bcomp[Max] = { 0 }, pro[Max] = { 0 }, res[Max] = { 0 };

void binary()
{
    a1 = fabs(a);
    b1 = fabs(b);
    int r, r2, i, temp;
    for (i = 0; i < Max; i++)
    {
        r = a1 % 2;
        a1 = a1 / 2;
        r2 = b1 % 2;
        b1 = b1 / 2;
        anum[i] = r;
        anumcp[i] = r;
        bnum[i] = r2;
        if (r2 == 0)
            bcomp[i] = 1;
        if (r == 0)
            acomp[i] = 1;
    }

    c = 0;
    for (i = 0; i < Max; i++)
    {
        res[i] = com[i] + bcomp[i] + c;
        if (res[i] >= 2)
            c = 1;
        else
            c = 0;
        res[i] = res[i] % 2;
    }
    for (i = Max - 1; i >= 0; i--)
        bcomp[i] = res[i];

    if (a < 0)
    {
        c = 0;
        for (i = Max - 1; i >= 0; i--)
            res[i] = 0;
        for (i = 0; i < Max; i++)
        {
            res[i] = com[i] + acomp[i] + c;
            if (res[i] >= 2)
                c = 1;
            else
                c = 0;
            res[i] = res[i] % 2;
        }
        for (i = Max - 1; i >= 0; i--)
        {
            anum[i] = res[i];
            anumcp[i] = res[i];
        }
    }
    if (b < 0)
    {
        for (i = 0; i < Max; i++)
        {
            temp = bnum[i];
            bnum[i] = bcomp[i];
            bcomp[i] = temp;
        }
    }
}
void add(int num[])
{
    int i;
    c = 0;
    for (i = 0; i < Max; i++)
    {
        res[i] = pro[i] + num[i] + c;
        if (res[i] >= 2)
            c = 1;
        else
            c = 0;
        res[i] = res[i] % 2;
    }
    for (i = Max - 1; i >= 0; i--)
    {
        pro[i] = res[i];
        printf("%d", pro[i]);
    }
    printf(" : ");
    for (i = Max - 1; i >= 0; i--)
        printf("%d", anumcp[i]);
    printf(" : ");
    for (i = Max - 1; i >= 0; i--)
        printf("%d", bnum[i]);
}
void arshift() 
{
    int temp = pro[Max - 1], temp2 = pro[0], i;
    for (i = 1; i < Max; i++)
        pro[i - 1] = pro[i];

    pro[Max - 1] = temp;
    for (i = 1; i < Max; i++)
        anumcp[i - 1] = anumcp[i];
    
    anumcp[Max - 1] = temp2;
    printf("\nAR-SHIFT  : ");
    for (i = Max - 1; i >= 0; i--)
        printf("%d", pro[i]);
    
    printf(" : ");
    for (i = Max - 1; i >= 0; i--)
        printf("%d", anumcp[i]);
    printf(" : ");
    for (i = Max - 1; i >= 0; i--)
        printf("%d", bnum[i]);
    printf("\n");
}

void main()
{
    int i, q = 0;
    com[0] = 1;
    for (int i = 1; i < Max; i++)
        com[i] = 0;
    printf("Nhap hai so de nhan");
    do 
    {
        printf("\nNhap Q: ");
        scanf("%d", &a);
        printf("Nhap M: ");
        scanf("%d", &b);
    } while (a >= pow(2, Max - 1) || b >= pow(2, Max - 1));

    printf("\n%13s%*s%*s","A", Max + 3,"Q", Max + 3,"M");

    binary();

    printf("\nINITIAL   : ");
    for (i = Max - 1; i >= 0; i--)
        printf("%d", pro[i]);
    printf(" : ");
    for (i = Max - 1; i >= 0; i--)
        printf("%d", anumcp[i]);
    printf(" : ");
    for (i = Max - 1; i >= 0; i--)
        printf("%d", bnum[i]);
    printf("\n");

    for (i = 0; i < Max; i++)
    {
        if (anum[i] == q) 
        {
            arshift();
            q = anum[i];
        }
        else if (anum[i] == 1 && q == 0)
        {
            printf("\nA = A - M : ");
            add(bcomp);
            arshift();
            q = anum[i];
        }
        else
        {
            printf("\nA = A + M : ");
            add(bnum);
            arshift();
            q = anum[i];
        }
    }

    printf("\nKet qua = ");
    for (i = Max - 1; i >= 0; i--)
        printf("%d", pro[i]);
    for (i = Max - 1; i >= 0; i--)
        printf("%d", anumcp[i]);
    getch();
}