#include <word_attributes.h>
#include "auto_readability.h"
#include <stdio.h>

int getNoOfWords(const char *s);
int getNoOfSentence(const char *s);
int getNoOfCharacter(const char *s);

/**
 * getARScore - function calculate the score of a test based
 * on automated readability index score
 *
 * @s - represent a string or pointer to char array of text to score
 *
 * Return: a double value which represent the score of the text
 */

double getARScore(const char *s) {
    double noOfChars = (double) getNoOfCharacter(s);
    double noOfWords = (double) getNoOfWords(s);
    double noOfSentences = (double) getNoOfSentence(s);
    return (((noOfChars / noOfWords) * 4.71) + ((0.5 * (noOfWords / noOfSentences)) - 21.43));
}
