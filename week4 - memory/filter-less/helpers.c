#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define RED 0
#define GREEN 1
#define BLUE 2

int get(int l, int c, int height, int width, RGBTRIPLE reference[height][width], int color);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float media = (float)(image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed) / 3;
            image[h][w].rgbtBlue = round(media);
            image[h][w].rgbtGreen = round(media);
            image[h][w].rgbtRed = round(media);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            
            int sepiaRed = round(.393 * image[h][w].rgbtRed + .769 * image[h][w].rgbtGreen + .189 * image[h][w].rgbtBlue);
            int sepiaGreen = round(.349 * image[h][w].rgbtRed + .686 * image[h][w].rgbtGreen + .168 * image[h][w].rgbtBlue);
            int sepiaBlue = round(.272 * image[h][w].rgbtRed + .534 * image[h][w].rgbtGreen + .131 * image[h][w].rgbtBlue);

            image[h][w].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
            image[h][w].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[h][w].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int middle = width / 2;
    int widarr = width - 1;
    for (int h = 0; h < height; h++)
    {

        for (int w = 0; w < middle; w++)
        {

            int init = w;
            int end = widarr - w;

            int redtmp = image[h][w].rgbtRed;
            int greentmp = image[h][w].rgbtGreen;
            int bluetmp = image[h][w].rgbtBlue;

            // values of first middle
            image[h][w].rgbtGreen = image[h][end].rgbtGreen;
            image[h][w].rgbtRed = image[h][end].rgbtRed;
            image[h][w].rgbtBlue = image[h][end].rgbtBlue;

            // values of second middle
            image[h][end].rgbtGreen = greentmp;
            image[h][end].rgbtRed = redtmp;
            image[h][end].rgbtBlue = bluetmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copia[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copia[h][w] = image[h][w];
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtRed = get(h, w, height, width, copia, 0);
            image[h][w].rgbtGreen = get(h, w, height, width, copia, 1);
            image[h][w].rgbtBlue = get(h, w, height, width, copia, 2);
        }
    }
    return;
}

int get(int l, int c, int height, int width, RGBTRIPLE reference[height][width], int color)
{
    float cont = 0;
    int media = 0;

    // percorre grid
    // uma linha antes ate uma linha depois
    for (int linha = l - 1; linha <= l + 1; linha++)
    {
        // uma coluna antes ate uma coluna depois
        for (int coluna = c - 1; coluna <= c + 1; coluna++)
        {
            // se a posição atual passar das bordas, definidas pela referencia da imagem
            if (linha < 0 || linha >= height || coluna < 0 || coluna >= width)
            {
                // se estrapolar desconsidera
                continue;
            }

            if (color == RED)
            {
                media += reference[linha][coluna].rgbtRed;
            }

            else if (color == GREEN)
            {
                media += reference[linha][coluna].rgbtGreen;
            }

            else if (color == BLUE)
            {
                media += reference[linha][coluna].rgbtBlue;
            }

            // A quantidade de pixeis trabalhados
            cont++;
        }
    }
    return round(media / cont);
}
