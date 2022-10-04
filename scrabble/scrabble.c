#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins! \n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 Wins! \n");
    }
    else if (score1 == score2)
    {
        printf("Tie! \n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    int lower;
    char play[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        for (int k = 0; k < 26; k++)
        {
            //make upper case into lower case
            word[i] = tolower(word[i]);
            //scoring
            if (word[i] == play[k])
            {
                score = score + POINTS[k];
            }
            else if (word[i] != play[k])
            {
                score = score + 0;
            }
        }
    }
    return score;
}
