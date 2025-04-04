#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void print_grade(int index);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    // index = 0.0588 * L - 0.296 * S - 15.8
    float L = letters * (100 / (float) words);
    float S = ((float) sentences / (float) words) * 100;
    
    int index = round((0.0588 * L - 0.296 * S - 15.8));
    // Print the grade level
    print_grade(index);
}

int count_letters(string text)
{
    // Return the number of letters in text
    int counter = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
        if (isalpha(text[i]))
            counter++;
    return counter;
}

int count_words(string text)
{
    // Return the number of words in text
    // any sequence of characters separated by a space to be a word
    int counter = 0;

    for (int i = 0, length = strlen(text); i < length + 1; i++) 
        if (text[i] == ' ' || text[i] == '\0')
            counter++;
    
    return counter;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    // You can consider any sequence of characters that ends with a . or a ! or a ? to be a sentence.
    char punctuation[3] = {'.', '!', '?'};

    int counter = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
        for (int j = 0; j < 3; j++)
            if (text[i] == punctuation[j])
                counter++;
    
    return counter;
}

void print_grade(int index) 
{
    if (index >= 16) 
        puts("Grade 16+");
    else if (index < 1) 
        puts("Before Grade 1");
    else 
        printf("Grade %i\n", index);
}
