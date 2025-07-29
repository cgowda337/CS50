#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Input: ");

    // TODO get the length of the string
    int length = strlen(text);
    // TODO print out each character by character
    for(int i = 0; i < length; i++){
        printf("%c\n", text[i]);
    }


}
