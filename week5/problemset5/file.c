#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    // an integer
    int number;

    // a pointer to another node
    struct node *next;
}
node;

// Defines the max number of nodes
int MAXNODES = 7;

int main(void)
{
    // create a new pointer that points to a node called "list", currently pointing to nothing
    node *list = NULL;

    // keep track of the number of nodes we have
    int totalNodes = 0;

    while (totalNodes < MAXNODES)
    {
        // ask the user for a number
        int x = get_int("Number: ");

        // if the number is longer than an integer, error out
        if (x == INT_MAX)
        {
            printf("\n");
            break;
        }

        // TODO: Allocate a new node.
        node *n = malloc(sizeof(node));
        // TODO: initialize (add values) to this new node
        n->number = x;
        n->next = NULL;

	// TODO: Add new node to head of linked list. Point new's next field to list
    n->next = list;
        // TODO: point "list" to the location of "new"
        list = n;
        // Update the total number of nodes
        totalNodes++;

    }


	// TODO: Print all nodes.
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    node *ptr = list;
	// TODO: Free all nodes.
    while (ptr != NULL)
    {
        node *tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }

}
