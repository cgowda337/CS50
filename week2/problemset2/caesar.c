#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string encrypt_ciphertext(string plaintext, int key);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        // print correct usage template if user inputs incompatible key
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // check for digits - reprint instructions if incompatible key input
        for (int i = 0, len = strlen(argv[1]); i < len; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("Plaintext: ");

    // output cipher text
    printf("Ciphertext: %s\n", encrypt_ciphertext(plaintext, key));
}

string encrypt_ciphertext(string plaintext, int key)
{
    // setup cipher variable
    string cipher = plaintext;

    int alpha = 26;
    // convert plaintext via cipher
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // adjust for upper/lower case
        if (isupper(plaintext[i]))
        {
            cipher[i] = (plaintext[i] - 'A' + key) % alpha + 'A';
        }
        else if (islower(plaintext[i]))
        {
            cipher[i] = (plaintext[i] - 'a' + key) % alpha + 'a';
        }
    }
    // return cipher translation
    return cipher;
}
