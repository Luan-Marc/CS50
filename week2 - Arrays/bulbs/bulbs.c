#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void convert_binary(string text);

int main(void)
{
    
    string message = get_string("Message:");
    convert_binary(message);
}

void convert_binary(string text)
{
    int binaries[BITS_IN_BYTE];
    for (int n = 0, tam = strlen(text); n < tam; n++) 
    {   
        char letter = text[n];
        for (int i = 0; i < BITS_IN_BYTE; i++) 
        {
            if (letter != 0) 
            {
                binaries[i] = letter % 2;
                letter = letter / 2;
            }

            else 
            {
                binaries[i] = 0;
            }

        }
        
        for (int pos = BITS_IN_BYTE - 1 ; pos >= 0 ; pos--) 
        {
            print_bulb(binaries[pos]);
        }
        printf("\n");
    }
    
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
