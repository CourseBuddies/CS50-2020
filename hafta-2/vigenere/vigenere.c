#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int control();
bool security;
int doVigenere ();

int main (int argc , string argv [] )
{
    if (argc != 2)
    {
        printf ("Usage --> ./vigenere keyword\n");
        return 1;
    }
    
    if (control(argc, argv))
    {
        int a = strlen( argv[1]);
        int b = 0;
        for ( int g = 0 , h = strlen(argv[1]); g < h; g++)
        {
            if ((argv[1][g] >= 'a' && argv[1][g] <= 'z') || (argv[1][g] >= 'A' && argv[1][g] <= 'Z'))
            {
                b++;
            }
        }
        if ( b < a)
        {
            printf ("Usage --> ./vigenere keyword\n");
            return 1;
        }
        else
        {
            doVigenere (argv);
        }
    }
}

int control ( int argcControl , string argvControl[])
{
    if ( argcControl != 2 )
    {
        printf ("Usage --> ./vigenere keyword\n");
    }
    else
    {
        security = true;
    }
    return security;
}

int doVigenere( string argvControl[])
{
    string ptext = get_string ("plaintext: ");
    printf ("ciphertext: ");
    for ( int j = 0, k = strlen (argvControl[1]); j < k; j++)
    {
        if (argvControl[1][j] >= 'A' && argvControl[1][j] <= 'Z')
        {
            argvControl [1][j] += ('a' - 'A');
        }
    }
    int mod;
    int baska = 0;
    string key = argvControl[1];
    for ( int i = 0, n = strlen(ptext); i < n; i++)
    {
        mod = baska % strlen (key);
        if (ptext[i] >= 'a' && ptext[i] <= 'z')
        {
            int kcontrol = 'z' - ptext[i];
            if ((key[mod] - 'a') > kcontrol)
            {
                int kcc = ( (key[mod] - 'a') - kcontrol ) - 1;
                ptext[i] = 'a';
                printf ("%c" , ptext[i] + kcc);
                baska++;
                continue;
            }
            printf ("%c", ptext[i] + (key[mod] - 'a'));
            baska ++;
            continue;
        }
        if (ptext[i] >= 'A' && ptext[i] <= 'Z')
        {
            int bcontrol = 'Z' - ptext[i];
            if ((key[mod] - 'a') > bcontrol)
            {
                int bcc = ( (key[mod] - 'a') - bcontrol ) - 1;
                ptext[i] = 'A';
                printf ("%c" , ptext[i] + bcc);
                baska++;
                continue;
            }
            printf ("%c", ptext[i] + (key[mod] - 'a'));
            baska ++;
            continue;
        }
        else
        {
            printf ("%c" , ptext[i]);
            continue;
        }
    }
    printf ("\n");
    return 0;
}
