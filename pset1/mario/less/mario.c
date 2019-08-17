#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    // prompting for input
    do
    {
        n = get_int("Height: ");
    } 
    while (n < 1 || n > 8);
    // if height is less than 1 or greater than 8 
    // (or not an integer at all), go back one step
    
    // iterate from 1 through height
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
