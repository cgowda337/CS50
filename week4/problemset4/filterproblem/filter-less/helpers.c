#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // turn all colors to black and white, all values of rgb need to be equivalent to get grayscale
    float average = 0;
    // loop
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *pixel = &image[i][j];
            // calculate average pixel value
            average = (pixel->rgbtRed + pixel->rgbtGreen + pixel->rgbtBlue) / 3.0;
            // change all rgb values to average value
            pixel->rgbtRed = round(average);
            pixel->rgbtGreen = round(average);
            pixel->rgbtBlue = round(average);
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed = 0;
    float sepiaGreen = 0;
    float sepiaBlue = 0;

    // loop
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *pixel = &image[i][j];
            // calculate sepia values based on formulas
            sepiaRed = .393 * pixel->rgbtRed + .769 * pixel->rgbtGreen + .189 * pixel->rgbtBlue;
            sepiaGreen = .349 * pixel->rgbtRed + .686 * pixel->rgbtGreen + .168 * pixel->rgbtBlue;
            sepiaBlue = .272 * pixel->rgbtRed + .534 * pixel->rgbtGreen + .131 * pixel->rgbtBlue;

            /* tried a for loop with an array to sort and bound the values between 0 and 255 - didnt
               work use uint8_t because it stores values between 0 and 255 already use ternary
               operator to
            */
            pixel->rgbtRed = (uint8_t) (sepiaRed > 255 ? 255 : round(sepiaRed));
            pixel->rgbtGreen = (uint8_t) (sepiaGreen > 255 ? 255 : round(sepiaGreen));
            pixel->rgbtBlue = (uint8_t) (sepiaBlue > 255 ? 255 : round(sepiaBlue));
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // only iterate throught half of the array so you dont swap photo back
        for (int j = 0; j < (width / 2); j++)
        {
            // set up similar to swap.c from lecture
            // pixel/pixel1 cannot be ints, need to be rgbtriples like image is
            RGBTRIPLE *pixel = &image[i][j];
            RGBTRIPLE *pixel_swap = &image[i][width - j - 1];

            RGBTRIPLE tmp = *pixel;
            *pixel = *pixel_swap;
            *pixel_swap = tmp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];

    // cant use RGBTRIPLE for *pixel like prior functions, causes some issue

    // i < height, j < width keeps loop for running within the bounds
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // create variables to count for sums & totals
            float redSum = 0, greenSum = 0, blueSum = 0, total = 0;

            // set up loop again but starting with i - 1 & j - 1
            // int [variable] to -1 instead of 0, upper bound at 1
            // -1 -> 1 left, center, right or down, center, up
            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    // Check if the surrounding pixel is within the bounds
                    // loop only should start at 0 onwards, and stay within bounds, same for j
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {

                        // originally was using copy here and kept getting 0's returned lol
                        // sum up all the values for red/green/blue, count total
                        redSum += image[k][l].rgbtRed;
                        greenSum += image[k][l].rgbtGreen;
                        blueSum += image[k][l].rgbtBlue;
                        total++;
                    }
                }
            }

            // update image with new avg pixel/color blur (sum/total) for each RGB
            // update it into copy to avoid any overwriting issues
            /* feel like theres a way to write math lines like this without having to rewrite each
               line may not be worth the time/may also not change efficiency */
            copy[i][j].rgbtRed = round(redSum / total);
            copy[i][j].rgbtGreen = round(greenSum / total);
            copy[i][j].rgbtBlue = round(blueSum / total);
        }
    }
    // now can put into copy into image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
