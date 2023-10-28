#include "word_attributes2.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <regex.h>
#include <stdlib.h>

int getNoOfSyllables(const char *s);
int getPolysyllables(const char *s);


/**
 * getNoOfSyllables - function counts the number of syllables in a text
 *
 * @s: pointer to char array or string of text to be counted
 *
 * Return: int value representing the count of syllables in a text
 */

int getNoOfSyllables(const char *s) {
    if (strcmp(s, "") == 0) {
     return (0);
    }


    // Convert the text to lowercase
    char *lowerText = strdup(s);
    for (int i = 0; lowerText[i]; i++) {
        lowerText[i] = tolower(lowerText[i]);
    }

    // Define regular expressions
    char *regexPatterns[] = {
        "e\\b",                 // Match 'e' at word boundaries
        "le",                   // Match 'le'
        "[aeiouy]{2,}",         // Match two or more consecutive vowels
        "[0-9]+"                // Match one or more digits
    };

    int numPatterns = sizeof(regexPatterns) / sizeof(regexPatterns[0]);
    int mem = 0;
    regex_t regex;
    regmatch_t pmatch;

    for (int i = 0; i < numPatterns; i++) {
        if (regcomp(&regex, regexPatterns[i], REG_EXTENDED | REG_ICASE) != 0) {
            fprintf(stderr, "Regex compilation failed for pattern: %s\n", regexPatterns[i]);
            continue;
        }

        int offset = 0;
        while (regexec(&regex, lowerText + offset, 1, &pmatch, 0) == 0) {
            offset += pmatch.rm_eo;
        }

        regfree(&regex);
    }

    char *token = strtok(lowerText, " ");
    int numTokens = 0;
    int counter = 0;

    while (token != NULL) {
        int tokenLen = strlen(token);

        if (counter == 0) {
            mem += 1;
        }
        mem += counter;
        counter = 0;

        for (int j = 0; j < tokenLen; j++) {
            if (strchr("aeiouy", token[j]) != NULL) {
                counter += 1;
            }
        }

        numTokens++;
        token = strtok(NULL, " ");
    }

    free(lowerText);
    return mem;
}

/**
 * getPolysyllables - function count the number of words with syllables above 2
 *
 * @s: pointer to char array or string of text to be counted
 *
 * Return: int value representing count of polysyllables
 */

int getPolysyllables(const char *s)
{
    if (strcmp(s, "") == 0) {
            return (0);
    }

    // Convert the text to lowercase
    char *lowerText = strdup(s);
    for (int i = 0; lowerText[i]; i++) {
        lowerText[i] = tolower(lowerText[i]);
    }

    // Define regular expressions
    char *regexPatterns[] = {
        "e\\b",                 // Match 'e' at word boundaries
        "le",                   // Match 'le'
        "[aeiouy]{2,}",         // Match two or more consecutive vowels
        "[0-9]+"                // Match one or more digits
    };

    int numPatterns = sizeof(regexPatterns) / sizeof(regexPatterns[0]);
    int mem = 0;
    regex_t regex;
    regmatch_t pmatch;

    for (int i = 0; i < numPatterns; i++) {
        if (regcomp(&regex, regexPatterns[i], REG_EXTENDED | REG_ICASE) != 0) {
            fprintf(stderr, "Regex compilation failed for pattern: %s\n", regexPatterns[i]);
            continue;
        }

        int offset = 0;
        while (regexec(&regex, lowerText + offset, 1, &pmatch, 0) == 0) {
            offset += pmatch.rm_eo;
        }

        regfree(&regex);
    }

    char *token = strtok(lowerText, " ");
    int numTokens = 0;
    int counter = 0;

    while (token != NULL) {
        int tokenLen = strlen(token);

        if (counter > 2) {
            mem += 1;
        }
        //mem += counter;
        counter = 0;

        for (int j = 0; j < tokenLen; j++) {
            if (strchr("aeiouy", token[j]) != NULL) {
                counter += 1;
            }
        }

        numTokens++;
        token = strtok(NULL, " ");
    }
    free(lowerText);
    return mem;
}

/**
 * displayWordAttributes2 - function display attributes of a text
 *
 * @s: pointer to char array or string of text to display
 *
 * Return: void
 */

void displayWordAttributes2(const char *s) {
    printf("Syllables: %d\n", getNoOfSyllables(s));
    printf("Polysyllables: %d\n", getPolysyllables(s));
}

