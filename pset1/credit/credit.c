/* Credit
 * -----------------|-----------|------------|
 * Card type        | digits    | start with |
 * -----------------|-----------|------------|
 * American Express | 15        | 34, 37     |
 * MaterCard        | 16        | 51 - 55    |
 * visa             | 13 or 16  | 4          |
 * -----------------|-----------|------------|
 * 
 * 
 * */

#include <cs50.h>
#include <stdio.h>

int length(long num);
int valid_check(long card_number);
string get_card_type(long card_number);

int main(void) 
{
    long credit_card;

    do
    {
        credit_card = get_long("Number: ");
    }
    while (credit_card < 0);
    
    int check = valid_check(credit_card); // validation
    
    if (check == 0) 
    {
        string card_type = get_card_type(credit_card);
        printf("%s\n", card_type);
    }
    else 
    {
        printf("VALID\n");
    }
}

int valid_check(long card_number)
{
    int card_len = length(card_number);
    int sum_odd;
    int sum_even;
    int total;
    int div = 10;
    
    if (card_len != 13 || card_len != 15 || card_len != 16)
    {
        return 0;
    }

    for (int i = 1; i <= card_len; i++)
    {
        if (i % 2 != 0)
        {
            sum_even += (card_number % (div ^ i) / (div ^ (i - 1)));
        }
        else 
        {
            sum_odd += (card_number % (div ^ i) / (div ^ (i - 1)));
        }
    }
    
    total = sum_odd * 2 + sum_even;
    
    if (total % 10 == 0 || total % 100 == 0)
    {
        return 0;        
    }
    else
    {
        return 1;
    } 
}

string get_card_type(long card_number)
{
    int card_len = length(card_number);
    int s_num;
    
    if (card_len == 15)
    {
        s_num = card_number / 10000000000000;
        if (s_num == 34 || s_num == 37)
        {
            return "AMEX";
        }
        else 
        {
            return "INVALID";
        }   
    } 
    else if (card_len == 16)
    {
        s_num = card_number / 100000000000000;
        if (s_num == 51 || s_num == 52 || s_num == 53 || s_num == 54 || s_num == 55)
        {
            return "MASTERCARD";
        } 
        else if (s_num / 10 == 4)
        {
            return "VISA";  
        }
        else 
        {
            return "INVALID";
        }
    } 
    else if (card_len == 13)
    {
        s_num = card_number / 1000000000000;
        if (s_num == 4)
        {
            return "VISA";
        }
        else
        {
            return "INVALID";
        }
    } 
    else
    {
        return "INVALID";
    }
}

int length(long num)
{
    int count = 0;
    
    while (num != 0)
    {
        count++;
        num /= 10;
    }
    
    return count;
}
