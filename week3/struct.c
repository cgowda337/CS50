#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    int courage;
    int fightingSkill;
    int health;
    int strength;
    string name;

} hero;


int main(void)
{

    //int attempts = 0;
    hero player;
    player.health = 10;
    player.strength = 1;
    player.courage = 1;

    player.name = get_string("What is your hero's name? ");
    printf("\nThe player's name is %s, with health %i and strength %i.\n", player.name, player.health, player.strength);

}
