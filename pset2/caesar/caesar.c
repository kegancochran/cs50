#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>

int errorCheck(int, string[]);
string scramble(string, int);

int main (int argc, string argv[])
{
    // Error check
    if (errorCheck(argc, argv) == 0)
    {
        // Ask for plaintext
        string plaintext = get_string("Plaintext: \n");

        // Print plaintext
        printf("Plaintext: %s\n", plaintext);

        // Convert argv[1] from string to integer
        int key = atoi(argv[1]);

        // Print key
        printf("Key: %i\n", key);
        
        // Add key to each letter in plaintext
        scramble(plaintext, key);  
        return 0;
    }
    else {return 1;}
}

int errorCheck(int count, string arg[])
{
        // If there's one argument...
        if (count > 1 && count < 3) 
        {
            // Check each char in arg string...
            int length = strlen(arg[1]);
            for(int i = 0; i < length; i++)
            {
                // Check if digit
                if (isdigit(arg[1][i]) < 1)
                {
                    printf("Usage: ./caesar key\n");
                    return 1;   
                }
            }
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        return 0;
}
string scramble(string input, int key)
{
    // For each character...
    int length = strlen(input); 
    for (int i = 0; i < length; i++)
    {
        // Check if letter (as opposed to puntucation or spaces)
        if (isalpha(input[i]) > 0)
        {
            // Shift input[i] "key" times. If no longer a letter, subtract 26, then assign it to input[i]
            for (int k = 0; k < key; k++)
            {
                input[i]++;
                if (isalpha(input[i]) < 1)
                {
                    input[i] -= 26; 
                }
            }
        }   
    }
    printf("Ciphertext: %s\n", input);
    return input;
}
