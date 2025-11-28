// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
#define HEADER_SIZE 44
#define SAMPLE_SIZE 2 // each sample == 2 bytes each

typedef uint8_t BYTE;

int main(int argc, char **argv)
{
    // Check command-line arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: ./volume input.wav output.wav factor\n");
        return EXIT_FAILURE;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "rb"); // read
    if (input == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *output = fopen(argv[2], "wb"); // write, if it doesn't exist, it will get created
    if (output == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    float factor = atof(argv[3]); 
    
    // Copy header to 'output.wav', that is, the first 44 bytes of 'input.wav'
    BYTE buffer[HEADER_SIZE];  
    
    fread(buffer, sizeof(BYTE), HEADER_SIZE, input);
    fwrite(buffer, sizeof(BYTE), HEADER_SIZE, output);

    // For each sample, multiply by 'factor' and copy to 'output'
    int16_t sample_buff;

    while (fread(&sample_buff, sizeof(BYTE), SAMPLE_SIZE, input) != 0) {
        sample_buff = sample_buff * factor;
        fwrite(&sample_buff, sizeof(BYTE), SAMPLE_SIZE, output);
    }
    
    // Close files
    fclose(input);
    fclose(output);
    return EXIT_SUCCESS;
}
