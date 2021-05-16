#include <stdio.h>
#include <cs50.h>

int get_pozitif (void);

int main (void)
{
    int i = get_pozitif ();
    for (int h=0; h<i; h++)
    {
        for(int a=i-1; a>h; a=a-1)
        {
            printf (" ");
        }
        for (int b=0; b<=h; b++)
        {
            printf ("#");
        }
        printf ("  ");
        for (int c=0; c<=h; c++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_pozitif (void)
{
    int n;
    do
    {
        n=get_int ("Yükseklik (1 ile 8 arasında): ");
    }
    while (n<1 || n>8);
    return n;
}
