#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// declare variables - fixes undeclared function error
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

// main
int main(void)
{
    // prompt for text/sentences
    string text = get_string("Text: ");

    // do the counts : formula needs letters/sentences & sentences/word, need 3 variables
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // use formula
    // multiply by 100 not divide so because 'per 100 words'
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // print grade level: before grade 1, grade 16+, grade n
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }
}

// count the letters
int count_letters(string text)
{
    int letters = 0;

    // count letters in text, add to letter for each alphanumeric character
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // check if i is alphanumeric character
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

// count the words
int count_words(string text)
{
    // initialize words, start at one since words wont have space
    int words = 1;

    // count words in text, add to variable after each space
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

// count number of sentences
int count_sentences(string text)
{
    int sentences = 0;

    // count sentences in text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // count ends of sentences where period/exclamation/question mark
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
