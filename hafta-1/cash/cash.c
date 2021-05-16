#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_para (void);

int main (void)
{
    float para= get_para();
    int tane=0;
    int npara =round(para*100);
    for (int a=npara; a>=25; a=a-25)
    {
        tane++;
        npara=npara-25;
    }
    for (int b=npara; b>=10; b=b-10)
    {
        tane++;
        npara=npara-10;
    }
    for (int c=npara; c>=5; c=c-5)
    {
        tane++;
        npara=npara-5;
    }
    for (int d=npara; d>=1; d=d-1)
    {
        tane++;
        npara=npara-1;
    }
    printf ("%i\n",tane);
}

float get_para (void)
{
    float n;
    do
    {
        n= get_float ("Para Üstü: ");
    }
    while (n<0);
    return n;
}
