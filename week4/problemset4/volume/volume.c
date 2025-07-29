// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*Number of bytes in .wav header contains information about the file itself,
including the size of the file, the number of samples per second, and the size of each sample*/
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{

    // set header variable at size of header size constant
    uint8_t header[HEADER_SIZE];

    // Create buffer variable
    int16_t buffer;
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor based on user input
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // the value user puts for volume is stored as a float - allows for more customization of volume
    // scale
    float factor = atof(argv[3]);

    // read header from input file , 44 bytes per element, reading 1 element, and writing 1 element
    // of 44 bytes to the output file
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // Read single sample from input into buffer while there are samples left to read, 1 element of
    // 16 bytes per loop
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // add check that scaled values remain min/max values of int16_t?
        // Update volume of sample
        if (buffer < 32767)
        {
            buffer *= factor;
        }
        else if (buffer > -32768)
        {
            buffer *= factor;
        }

        // Write updated sample to new file
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close opened files
    fclose(input);
    fclose(output);
}
