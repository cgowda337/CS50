#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// create constant for the header size max
const int HEADERSIZE = 512;

// create fwrite function standard
void fwrite_func(uint8_t *buffer, int size, int headersize, FILE *img);

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    // if card null return false
    if (card == NULL)
    {
        printf("Usage: ./no detected FILE\n");
        return 1;
    }
    // Create a buffer for a block of data
    uint8_t buffer[HEADERSIZE];

    // add count for files
    int count = 0;

    char filename[8];
    FILE *img = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, HEADERSIZE, card) == HEADERSIZE)
    {
        // check for header of jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }
            // load new file
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            // if file null return false
            if (img == NULL)
            {
                printf("Usage: ./no detected FILE\n");
                fclose(card);
                return 1;
            }

            // write to new jpeg file
            fwrite_func(buffer, 1, HEADERSIZE, img);
            count++;
        }
        else if (img != NULL)
        {
            // write to jpeg file
            fwrite_func(buffer, 1, HEADERSIZE, img);
        }
    }

    // close out any left open files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);

    return 0;
}

// define function to avoid fwrite duplication
void fwrite_func(uint8_t *buffer, int size, int headersize, FILE *img)
{
    fwrite(buffer, size, headersize, img);
}
