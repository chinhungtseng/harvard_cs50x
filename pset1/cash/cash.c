/* prompt user for an amount of change
       the amount must make sense
       what values are accepted?
       get_float
   alawys use the largest coin possible
   keep track of coins used 
   print the final number of coins
                                         */

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float money;      // initial float type variable
    int counter = 0;  // set a counter
    do 
    {
        money = get_float("Change owed: ");
    }
    while (money < 0);
    
    int cents = round(money * 100);
    
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
            counter++;
            continue;
        } 
        else if (cents >= 10)
        {
            cents -= 10;
            counter++;
            continue;
        } 
        else if (cents >= 5)
        {
            cents -= 5;
            counter++;
            continue;
        } 
        else 
        {
            cents -= 1;
            counter++;
        }
    }

    printf("%i\n", counter);    
}
