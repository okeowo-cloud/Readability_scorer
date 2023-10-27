#include "word_attributes.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int getNoOfWords(const char *s);
int getNoOfSentence(const char *s);
int getNoOfCharacter(const char *s);

/**
 * getNoOfWords - function calculate the number of words in a text
 *
 * @s: pointer to char array or string to be counted
 *
 * Return: int value representing count of words.
 */

int getNoOfWords(const char *s) {
    int count = 0;
    int isWord = 0;  // Flag to track if we are inside a word

    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i]) || s[i] == '\'' ) {
            if (!isWord) {
                isWord = 1;
                count++;
            }
        } else {
            isWord = 0;
        }
    }

    return count;
}

/**
 * getNoOfSentence - function count the number of sentences in a text
 *
 * @s: pointer to char array or string to be counted
 *
 * Return: int value representing the count of sentences.
 */

int getNoOfSentence(const char *s) {
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?') {
            count++;
        }
    }

    return count;
}

/**
 * getNoOfCharacter - function counts the number of characters in a text
 *
 * @s: pointer to char array or string to be counted
 *
 * Return: int value representing the count of characters.
 */
int getNoOfCharacter(const char *s) {
    int count = 0;

    // Loop through each character in the string
    for (int i = 0; s[i] != '\0'; i++) {
        // Check if the character is not a whitespace character
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\r') {
            count++;
        }
    }

    return count;
}

/**
 * displayWordAttributes - function display the attributes of a text
 *
 * @s: pointer to char array or string of text to display
 *
 * Return: void
 */

void displayWordAttributes(const char *s) {
    printf("The text is:\n%s\n\n", s);
    printf("Words: %d\n", getNoOfWords(s));
    printf("Sentences: %d\n", getNoOfSentence(s));
    printf("Characters: %d\n", getNoOfCharacter(s));
}
