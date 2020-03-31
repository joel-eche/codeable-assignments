#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void apply_caesar(string text, int key);
float is_number(string text);

int main(int argc, string argv[])
{

    if (argc > 2 || argc == 1 || !is_number(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        apply_caesar(plaintext, atoi(argv[1]));
        printf("\n");
    }


}

void apply_caesar(string text, int key)
{

    for (int i = 0; i < strlen(text); i++)
    {

        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            int ascii_init = 0;
            int ascii_letter = (int)text[i];

            if (isupper(text[i]))
            {
                ascii_init = 65;
            }
            else
            {
                ascii_init = 97;
            }

            char letter_with_caesar = ascii_init + ((ascii_letter - ascii_init) + key) % 26;

            printf("%c", letter_with_caesar);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
}

float is_number(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            return false;
        }
    }
    return true;
}