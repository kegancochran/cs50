#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

string scramble(string);
int main (int argc, string argv[])
{
    // Error check
    // If there's one argument...
    if (argc > 1 && argc < 3) 
    {
        // Check each char in arg string...
        int length = strlen(argv[1]);
        for(int i = 0; i < length; i++)
        {
            // Check if digit
            int arg = isdigit(argv[1][i]);
            if (arg < 1)
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

    // Ask for plaintext
    string plaintext = get_string("Plaintext: \n");

    // Convert argv[1] from string to integer
    
    // Add key to each letter in plaintext
    scramble(plaintext);            // Add "key" argument to function
}

string scramble(string input)
{
    int length = strlen(input); 
    for (int i = 0; i < length; i++)
    {
        // Replace me
        printf("%c\n", input[i]);
    }
    return input;
}
