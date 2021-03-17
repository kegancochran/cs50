# Caesar Implementation
---
    1. Accept a single *command-line argument*, a non-negative integer. (k)
    2. Print error message if no argument is given or a negative integer is given.
    3. Do not assume that the argument will be between 0-26.
    4. Program must output:
        "plaintext: " and prompt for user input
        "ciphertext: " and output encrypted text
    5. Preserve case.
    6. After outputting ciphertext:
        print a newline and return 0 from main

# Pseudocode
---

```
int main (argument)
{
    do
    {
        printf("Usage: ./caesar key");
    }  
    while (no argument || negative int)
    int key = argument;
    string plaintext = get_string("plaintext: ");
    
    // I would like to pass the argument to an "encrypt" function but
        I don't feel like looking that up just yet.

    // ci = (pi + k) % 26

    // Add "key" to each character in "plaintext", preserving case.
        // For each character in "plaintext":
            // Assign variable to character
            // If lowercase:
            // else:   

    // What's killing me is this whole "rolling over" thing
            // if you have a large enough key, when you divide by 26,
            // the char won't be a letter.
            

            // for loop? some kind of loop?
                // for(char <= z)
                //      ci++

    // I think I'm going to have to create an array for the ciphertexts.
            
    for(i = 0, length = strlen(plaintext); i < length; i++)
    {
        int ci = plaintext[i];

    }
}


```
