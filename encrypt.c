#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function prototype
void encrypt(string plaintext, int key);

int main(int argc, string argv[])
{
    // Check if the command-line argument count is correct
    if (argc != 2)
    {
        printf("Usage: ./encrypt key\n");
        return 1;
    }

    // Check if the key is a positive digit
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./encrypt key (key is positive digit)\n");
            return 1;
        }
    }

    // Convert key from string to integer
    int key = atoi(argv[1]);

    // Get plaintext input from the user
    string plaintext = get_string("Plaintext:  ");

    // Encrypt the plaintext
    printf("Ciphertext: ");
    encrypt(plaintext, key);
    printf("\n");

    return 0;
}

void encrypt(string plaintext, int key)
{
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i];

        // Check if the character is uppercase
        if (isupper(c))
        {
            printf("%c", ((c - 'A' + key) % 26) + 'A');
        }
        // Check if the character is lowercase
        else if (islower(c))
        {
            printf("%c", ((c - 'a' + key) % 26) + 'a');
        }
        // If it's not an alphabetic character, print it as it is
        else
        {
            printf("%c", c);
        }
    }
}
