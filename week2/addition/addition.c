/*  addition.c
Write a program addition.c that adds two numbers provided as command-line arguments.

The program should accept two integers as command-line arguments.
The program should output both original numbers, and their sum. If the program is run as ./addition 2 8, for example, the output should be 2 + 8 = 10.
If the incorrect number of command-line arguments is provided, the program should display an error and return with exit code 1.
*/


#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./addition x y\n");
        return 1;
    }

    // TO DO

    // Get the integer for X from argv
    int x = atoi(argv[1]);
    // Get the integer for Y from argv
    int y = atoi(argv[2]);
    // do the math to get the result
    int sum = x + y;
    // print the result
    printf("%i + %i = %i\n", x, y, sum);
}
