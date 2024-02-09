#include <stdio.h>
#include <cs50.h>
#include <stdint.h>
int main(int argc, char *argv[])
{
    
    if (argc != 2)
    {
        printf("Improper usage.\n");
        return 1;
    }

    //Open file
    string filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("No such file found");
        return 2;
    }

    uint8_t buffer[4];
    uint8_t signature[] = {37,80,68,70};
    fclose(file);

    //Pass to buffer 4 bytes of file
    fread(buffer, 1, 4, file);
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("Not a pdf");
            return 0;
        }
        
    }

    printf("Is a pdf\n");
    return 0;
}
