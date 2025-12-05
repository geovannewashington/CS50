#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale

// Reminder: RGBTRIPLE is structure defined at the bmp.h file. 
// Each image pixel color (RGB) can be accessed with image[height][width].rgbtColor

// BMP stores the triples backwards (i.e., as BGR instead of RGB)
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // for each pixel        
            // convert new_rgbt to it's nearest integer
            int new_rgbt = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + 
                        image[i][j].rgbtBlue) / 3);
            
            image[i][j].rgbtRed = new_rgbt;
            image[i][j].rgbtGreen = new_rgbt;
            image[i][j].rgbtBlue = new_rgbt;
        }
    }
    return;
}

// Convert image to sepia
typedef struct {
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
} Sepia_colors;

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // instance of Sepia_colors
    Sepia_colors new_colors = {};

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // for each pixel        
            
            // calculate each sepia color            
            new_colors.sepiaRed = round(
                    0.393 * image[i][j].rgbtRed
                 +  0.769 * image[i][j].rgbtGreen
                 +  0.189 * image[i][j].rgbtBlue
            );

            new_colors.sepiaGreen = round(
                    0.349 * image[i][j].rgbtRed
                 +  0.686 * image[i][j].rgbtGreen
                 +  0.168 * image[i][j].rgbtBlue
            );
            
            new_colors.sepiaBlue = round(
                    0.272 * image[i][j].rgbtRed
                 +  0.534 * image[i][j].rgbtGreen
                 +  0.131 * image[i][j].rgbtBlue
            );
            
            if (new_colors.sepiaRed > 255) new_colors.sepiaRed = 255;
            if (new_colors.sepiaGreen > 255) new_colors.sepiaGreen = 255;
            if (new_colors.sepiaBlue > 255) new_colors.sepiaBlue = 255;

            image[i][j].rgbtRed = new_colors.sepiaRed;
            image[i][j].rgbtGreen = new_colors.sepiaGreen;
            image[i][j].rgbtBlue = new_colors.sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        // each line...
        for (int j = 0; j < width / 2; j++) {
            // swap elements
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][(width - 1) - j];
            image[i][(width - 1) - j] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
