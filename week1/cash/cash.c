#include <cs50.h>
#include <stdio.h>

int cents = 0;
int main(void)
{
    // Prompt the user for change owed, in cents
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Create amount of coins variable
    int coins = 0;

    // Calculate how many quarters you need, and remainder of cents left
    coins += cents / 25;
    cents %= 25;

    // Calculate how many dimes you need, and remainder of cents left
    coins += cents / 10;
    cents %= 10;

    // Calculate how many nickels you need, and remainder of cents left
    coins += cents / 5;
    cents %= 5;

    // Rest of coins would be divided by one so can just count them
    coins += cents;

    // Output amount of total coins needed
    printf("%d\n", coins);

    return 0;
}
