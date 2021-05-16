#include <stdio.h>
#include <cs50.h>
#include <math.h>

int sorgula (void);
int get_luhn (long a, int b);
int get_numbasamak (long kartnum);
long get_kartnum (void);

long cardNum;
int numOrder;

int main (void)
{
    
    cardNum = get_kartnum();
    numOrder = get_numbasamak (cardNum);
    if (numOrder>=13 && numOrder<=16)
    {
        sorgula();
    }
    else
    {
        printf ("INVALID\n");
    }
}   

long get_kartnum (void)
{
    long n;
    do
    {
        n = get_long ("Enter Card Number: ");
        
    }
    while (n < 1);
    return n;
}

int get_numbasamak (long kartnum)
{
    int basamak = 1;
    while ((kartnum /= 10) > 0) basamak++;
    return basamak;
}

int get_luhn (long a, int b)
{
    int tektopla = 0;
    int cifttopla = 0;
    
    for (int c = 0; c < b; c ++)
    {
        if(c %2 == 0)
        {
            long tt = a / pow(10,c);
            tt %= 10;
            tektopla += tt;
        }
        else
        {
            long cc = a /pow(10,c);
            cc %= 10;
            cc *= 2;
            if (cc>=10)
            {
                int cd = cc/10 + cc%10;
                cifttopla += cd;
                continue;
            }
            cifttopla += cc;
        }
        
    }
    int luhn = tektopla + cifttopla;
    bool luhnsec = !(luhn%10); 
    return luhnsec;
}

int sorgula (void)
{
    bool Security = get_luhn (cardNum, numOrder);
    long powNum = pow (10, (numOrder - 2));
    int drakam = cardNum / powNum;
    int srakam = cardNum /(powNum*10);
    
    if (Security && (numOrder == 15) && ((drakam == 34) || (drakam == 37)))
    {
        printf("AMEX\n");
    }
    else if (Security && (numOrder == 16) && ((50 < drakam) && (drakam < 56)))
    {
        printf("MASTERCARD\n");
    }
    else if (Security && ((numOrder == 13) || (numOrder == 16)) && (srakam == 4))
    {
        printf("VISA\n");
    }else
    {
        printf("INVALID\n");
    }
    return 0;
}