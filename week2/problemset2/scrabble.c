#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// letters to numbers assignment array
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// scoring calc function
int score_calc(string word);

int main(void)
{
    // make inputs
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // compute score of each word
    int score1 = score_calc(word1);
    int score2 = score_calc(word2);

    // output player with larger score
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        // print p1 win if score 1 > score 2 else print p2 win
        printf("%s\n", score1 > score2 ? "Player 1 wins!" : "Player 2 wins!");
    }
}

int score_calc(string word)
{
    // setup score variable
    int score = 0;

    // calculate score
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // adjust for upper/lower case
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    // return word - > number value
    return score;
}
