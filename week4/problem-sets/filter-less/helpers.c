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
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
