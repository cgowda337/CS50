#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt how tall - set limits for between 1 and 8 as input
    int n;
    do
    {
        n = get_int("Height? ");
    }
    while (n < 1 || n > 8);
    // build loop //build subloops for hashes and spaces
    for (int i = 1; i <= n; i++)
    {
        // output progressing spaces
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        // output j hashes
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
