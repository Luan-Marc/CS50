#include <cs50.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letter(int size, string text);
int count_word(int size, string text);
int count_sentences(int size, string text);
void print_grade(int word, int sentences, int letter);

int main(void) 
{
    string Text = get_string("Text: ");
    int size = strlen(Text);
    int n_letter = count_letter(size, Text);
    int n_word = count_word(size, Text);
    int n_sentences = count_sentences(size, Text);
    print_grade(n_word, n_sentences, n_letter);
    

}

int count_word(int size, string text)
{
    int word = 1;
    for (int c = 0; c < size; c++)
    {
        if (text[c] == ' ')
        {
            word++;
        }
    } 
    return word;
}

int count_sentences(int size, string text)
{
    int sentences = 0;
    for (int c = 0; c < size; c++)
    {
        if (text[c] == '.' || text[c] == '!' || text[c] == '?') 
        {
            sentences++;
        }
    }
    return sentences;
}

int count_letter(int size, string text)
{
    int letter = 0;
    for (int c = 0; c < size; c++)
    {
        if (isalpha(text[c])) 
        {
            letter++;
        }
    }
    return letter;
}

void print_grade(int word, int sentences, int letter)
{
    float L = ((float)letter / (float)word) * 100;
    float S = ((float)sentences / (float)word) * 100;
    float index =  0.0588 * L - 0.296 * S - 15.8;
    
    if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else if (index < 1) 
    {
        printf("Before Grade 1\n");
    }

    else 
    {
        printf("Grade %i\n", (int) round(index));
    }

}
