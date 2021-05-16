#include <stdio.h>
#include <cs50.h>

int get_yukseklik (void);

int main (void)
{
    int i = get_yukseklik();
    for (int a=0; a<i; a++)
    {
        for (int b=i-1; b>a; b=b-1)
        {
            printf (" ");
        }
        for (int c=0; c<=a; c++)
        {
            printf ("#");
        }
        printf("\n");
    }
}

int get_yukseklik (void)
{
    int n;
    do
    {
        n=get_int("Yükseklik (1 ile 8 arasında): ");
    }
    while (n<1 || n>8);
    return n;
}
