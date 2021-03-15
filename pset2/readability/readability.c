#include <math.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

float letterCount = 0.0;
float wordCount = 1.0;
float sentenceCount = 0.0;
float countLetters(string);
float countWords(string);
float countSentences(string);
double calculate(float, float, float);
float index;

int main(void)
{
    // TODO: Ask for string of text.
    string input = get_string("Text: \n");

    // Count letters, words, and sentences
    letterCount = countLetters(input);
    wordCount = countWords(input);
    sentenceCount = countSentences(input);    
    
    // Calculate
    calculate(letterCount, wordCount, sentenceCount);

    // TODO: Print grade level. Use "Below Grade 1" and "Grade 16+"/ 
    float grade = round(index); 
    printf("%f\n", index);
    if (index < 1)
    {
        printf("Below Grade 1\n");
    }
    else
    {
        if (index >= 16)
        {
            printf("Grade 16+\n");
        }
        printf("Grade %f\n", grade);
    }
}

float countLetters(string input)
{
    int length = strlen(input);
    for (int i = 0; i <= length; i++)
        {
            int ii = input[i];
            if ((ii > 64 && ii < 91) || (ii > 96 && ii < 122))
            {
                letterCount += 1;
            }
        }
    return letterCount;
}

float countWords(string input)
{
    wordCount = 1;
    int length = strlen(input);
    for (int i = 0; i <= length; i++)
        {
            int ii = input[i];
            if (ii == 32)
            {
                wordCount += 1;
            }
        }
    return wordCount;
}

float countSentences(string input)
{
    sentenceCount = 0;
    int length = strlen(input);
    for (int i = 0; i <= length; i++)
        {
            int ii = input[i];
            if (ii == 33 || ii == 46 || ii == 63 )
            {
                sentenceCount += 1;
            }
        }
    return sentenceCount;
}

double calculate(a, b, c)
{
    // Coleman-Liau Index:
    // index = 0.0588 * L - 0.296 * S - 15.8        // L = letters per 100 words, S = sentences per 100 words
    float L = (float)a / b * 100.0;
    float S = (float)c / b * 100.0;
    printf("L = %f\n", L);
    printf("S = %f\n", S);

    index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}

