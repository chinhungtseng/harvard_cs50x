#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check that program was run with one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    // Iterate over the provided argument to make sure all characters are digits
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert that commnad-line argument from a `string` to an `int`
    int k = atoi(argv[1]);
    
    // Prompt user for plaintext
    string s = get_string("plaintext:  ");
    
    string result[strlen(s)];
    // iterate over each character of the plaintext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // If it is a lowercase letter
        if (islower(s[i]))
        {            
            printf("%c", ((s[i] - 'a' + k) % 26) + 'a');
        }
        // If it is an uppercase letter
        else if (isupper(s[i]))
        {
            printf("%c", ((s[i] - 'A' + k) % 26) + 'A');
        }
        // f it is neither
        else
        {
            printf("%c", s[i]);
        }
    }
    
    // Print a newline
    printf("\n");

    return 0;
}
