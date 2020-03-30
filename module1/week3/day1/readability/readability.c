#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int calculate_readability(string text);

int main(int argc, string argv[])
{

    string text = get_string("Text: ");
    int readability = calculate_readability(text);

    if (readability < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (readability >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", readability);
    }


}

int calculate_readability(string text)
{
    int count_letters = 0;
    int count_words = 0;
    int count_sentences = 0;
    int readability = 0;
    float L = 0;
    float S = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            count_letters++;

            if (text[i - 1] == ' ' || text[i - 1] == '\0' || text[i - 1] == '"')
            {
                count_words++;
            }
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count_sentences++;
        }
    }

    L = count_letters / (float)count_words * 100;
    S = count_sentences / (float)count_words * 100;

    readability = (int)round((0.0588 * L) - (0.296 * S) - 15.8);

    return readability;
};