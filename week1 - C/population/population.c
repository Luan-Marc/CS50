#include <cs50.h>
#include <stdio.h>

int Start_population(void);
int End_population(int minimum);
int Number_years(int initial, int end);

int main(void)
{
    // TODO: Prompt for start size
    int start = Start_population();
    // TODO: Prompt for end size
    int final = End_population(start);
    // TODO: Calculate number of years until we reach threshold
    int years = Number_years(start, final);    
    // TODO: Print number of years
    printf("Years: %i \n", years);
}

int Start_population(void)
{
    int s = 0;
    do
    {
        s = get_int("Start size:");
    }
    while (s < 9);
    return s;
}

int End_population(int minimum)
{
    int e = 0;
    do
    {
        e = get_int("End size:");
    }
    while (e < minimum);
    return e;
}

int Number_years(int initial, int limit)
{
    int llamas = initial;
    int years = 0;

    while (llamas < limit)
    {
        int borning = (int)llamas / 3;
        int dying = (int)llamas / 4;
        llamas = llamas + borning - dying;
        years++;
    }
    return years;
}
