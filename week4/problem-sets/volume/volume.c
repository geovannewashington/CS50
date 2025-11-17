// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// -- Macros

// Number of bytes in .wav header
#define HEADER_SIZE 44
#define SAMPLE_SIZE 2
int main(int argc, char **argv)
{
    // Check command-line arguments
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./volume input.wav output.wav factor\n");
        return EXIT_FAILURE;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (!input) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *output = fopen(argv[2], "w"); // if it doesn't exist, it will get created
    if (!output) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    float factor = atof(argv[3]); 
    size_t byte;

    // TODO: Copy header from input file to output file
    while (fread(&byte, sizeof(byte), HEADER_SIZE, input) != 0) {
        fwrite(&byte, sizeof(byte), HEADER_SIZE, output);
    }

    // TODO: Read samples from input file and write updated data to output file
    // read each sample (2-byte each), multiply it by the factor, and then write it to output wav
    while (fread(&byte, sizeof(byte), SAMPLE_SIZE, input) != 0) {
        fwrite(&byte, sizeof(byte), SAMPLE_SIZE, output);
    }
    
    // Close files
    fclose(input);
    fclose(output);
    return EXIT_SUCCESS;
}
