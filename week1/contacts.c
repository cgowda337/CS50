/*  contacts.c
    Write a program, contacts.c, that asks the user for a name, an age, and a phone number
    (as well as one other value of the student’s choice). contacts.c should print the values
    back to the user as confirmation.
    CS50

    Usage:
    $ ./contacts
    Name: Harry
    Age: 11
    Phone Number: 1-800-MAGIC
    Location: Number 4, Privet Drive

    New contact: Harry, 11, lives at Number 4, Privet Drive and can be reached at 1-800-MAGIC.
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO - get the name, age, phone number, and address of one person
    string name = get_string("What is your name? ");
    int age = get_int("What is your age? ");
    string address = get_string("What is your address? ");
    string phone = get_string("What is your phone number? ");
    // Print the result
    printf("\nNew Contact: %s, %i, lives at %s and can be reached at %s.\n", name, age, address, phone);
}
