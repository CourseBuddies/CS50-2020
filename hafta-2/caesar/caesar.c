#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int caesar ();
int control ();
bool security;

int main ( int argc , string argv[] )
{
    if (argc != 2)
    {
        printf ("Usage: ./caesar1 key\n");
        return 1;
    }
    else
    {
        if (control (argc , argv))
        {
            caesar(argc , argv);
        }
    }
}

int control ( int argcControl , string argvControl[])
{
    int sayib = atoi (argvControl[1]);
    int allb = strlen (argvControl[1]);
    if ( (sayib ==0) || (sayib < allb) )
    {
        printf ("Usage: ./caesar2 key\n");
        return 1;
    }
    security = true;
    return security;
}

int caesar ( int argcControl , string argvControl[])
{
    string ptext = get_string ("plaintext: ");
    int key = atoi (argvControl[1]);
    if ( key >= 26)
    {
        key %= 26;
    }
    printf ("ciphertext: ");
    for (int i = 0 , n = strlen(ptext); i < n; i++ )
    {
        if (ptext[i] >= 'a' && ptext[i] <= 'z')
        {
            int kharfc = 'z' - ptext[i];
            if ( key > kharfc)
            {
                int kharf = (key - kharfc) - 1;
                ptext[i] = 'a';
                printf ("%c" , ptext[i] + kharf);
                continue;
            }
            printf ("%c" , ptext[i] + key);
        }
        else if (ptext[i] >= 'A' && ptext[i] <= 'Z')
        {
            int bharfc = 'Z' - ptext[i];
            if (key > bharfc)
            {
                int bharf = (key - bharfc) - 1;
                ptext[i] = 'A';
                printf ("%c" , ptext[i] + bharf);
                continue;
            }
            printf ("%c" , ptext[i] + key);
        }
        else
        {
            printf ("%c" , ptext[i]);
        }
    }
    printf ("\n");
    return 1;
}
