#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

    int numberjpg = 0;
    uint8_t buffer[512];
    FILE *imagem = NULL;

    if (argc != 2)
    {
        printf("Improper usage.\n");
        return 1;
    }

    string filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("No such file found");
        return 2;
    }

    while (fread(buffer, 1, 512, file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if (imagem != NULL)
            {
                fclose(imagem);
            }
            sprintf(filename, "%03i.jpg", numberjpg++);
            imagem = fopen(filename, "w");
        }

        if (imagem != NULL)
        {
            fwrite(buffer, 1, 512, imagem);
        }
    }

    if (imagem != NULL)
    {
        fclose(imagem);
    }

    fclose(file);
}

