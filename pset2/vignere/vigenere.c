#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
    
int shift(char letter);

int main(int argc, string argv[])
{
    // Check that program was run with one command-line argument
    if (argc != 2) 
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    
    string key = argv[1];
    // Iterate over the provided argument to make sure all characters are characters
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }
    
    // Prompt user for plaintext
    string messages = get_string("plaintext:  ");

    // Print the output messages
    printf("ciphertext: ");
    
    // Iterate over each character of the plaintext
    for (int i = 0, j = 0, n = strlen(messages); i < n; i++)
    {
        // If it's not alpha
        if (!isalpha(messages[i]))
        {
            printf("%c", messages[i]);
        } 
        else
        {
            j = j % strlen(key);
            if (isupper(messages[i]))
            {
                printf("%c", ((shift(messages[i]) + shift(key[j])) % 26) + 65);
            }
            else if (islower(messages[i]))
            {
                printf("%c", ((shift(messages[i]) + shift(key[j])) % 26) + 97);
            }
            j++;
        }
    }
    
    // new line
    printf("\n");
    
    return 0;
}

// shift the key
int shift(char letter)
{
    int offset = 0;
    if (isupper(letter))
    {
        offset = 65;
    }
    else if (islower(letter))
    {
        offset = 97;
    }
    
    return letter - offset;
}
