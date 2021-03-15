#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>

int countLetters(string);
int countWords(string);
int countSentences(string);
float calculate(int, int, int);

int main(void)
{
    // Get text from user
    string text = get_string("Text: ");

    // Count letters, words, and sentences.
    int letters = countLetters(text);
    int words = countWords(text);
    int sentences = countSentences(text);

    // Print counts
    printf("Letters: %i\n", letters);
    printf("Words: %i\n", words);
    printf("Sentences: %i\n", sentences);

    // Calculate according to the Coleman-Liau Index.
    float index = calculate(letters, words, sentences);
    printf("Index:  %f\n", index);

    // Print grade level.
    int grade = round(index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        if (index >= 16)
        {
            printf("Grade 16+\n");
        }
        else printf("Grade %i\n", grade);
    }
}

int countLetters(string text)
{
    int length = strlen(text);
    int letterCount  = 0;
    for(int i = 0; i < length; i++)
    {
        char letter = text[i];
        if (isalpha(letter))
        {
           letterCount++; 
        }
    }
    return letterCount;
}

int countWords(string text)
{
    int length = strlen(text);
    int wordCount = 1;
    for(int i = 0; i < length; i++)
    {
        char letter = text[i];
        if (isspace(letter))
        {
           wordCount++; 
        }
    }    
    return wordCount;
}

int countSentences(string text)
{
    int length = strlen(text);
    int sentenceCount = 0;
    for(int i = 0; i < length; i++)
    {
        char letter = text[i];
        if (letter == 33 || letter == 46 || letter == 63)
        {
           sentenceCount++; 
        }
    }    
    return sentenceCount;
}

float calculate(a, b, c)
{
    float L = (float) a / b * 100;
    float S = (float) c / b * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}

