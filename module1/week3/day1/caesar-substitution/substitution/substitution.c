#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void apply_substitution(string text, string key);
bool has_repeated_letters(string text);
bool has_only_letters(string text);

int main(int argc, string argv[])
{

    if (argc > 2 || argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (has_repeated_letters(argv[1]))
    {
        printf("Key must not contain repeated characters..\n");
        return 1;
    }
    else if (!has_only_letters(argv[1]))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    else
    {
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        apply_substitution(plaintext, argv[1]);
        printf("\n");
    }


}

void apply_substitution(string text, string key)
{

    for (int i = 0; i < strlen(text); i++)
    {

        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            int ascii_init = 0;
            int ascii_letter = (int)text[i];
            char letter_with_substitution = ' ';

            if (isupper(text[i]))
            {
                ascii_init = 65;
                letter_with_substitution = toupper(key[ascii_letter - ascii_init]);
            }
            else
            {
                ascii_init = 97;
                letter_with_substitution = tolower(key[ascii_letter - ascii_init]);
            }


            printf("%c", letter_with_substitution);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
}

bool has_repeated_letters(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        for (int j = 0; j < strlen(text); j++)
        {

            if (i != j && tolower(text[i]) == tolower(text[j]))
            {
                return true;
            }
        }
    }
    return false;
}

bool has_only_letters(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {

        if ((text[i] < 'a' || text[i] > 'z') && (text[i] < 'A' || text[i] > 'Z'))
        {
            return false;
        }
    }
    return true;
}