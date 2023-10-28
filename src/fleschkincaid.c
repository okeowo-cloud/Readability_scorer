#include <word_attributes.h>
#include "fleschkincaid.h"
#include <word_attributes2.h>

int getNoOfWords(const char *s);
int getNoOfSentence(const char *s);
int getNoOfSyllables(const char *s);

/**
 * getFleschScore - function calculate the readability of a text
 * based on Flesch Kincaid index
 *
 * @s: is a string or pointer to char array of text to be scored
 *
 * Return: a double float which represents the score of the text
 */

double getFleschScore(const char *s) {
    double noOfWords = (double) getNoOfWords(s);
    double noOfSentences = (double) getNoOfSentence(s);
    double noOfSyllables = (double) getNoOfSyllables(s);
    return (0.39 * (noOfWords / noOfSentences) + 11.8 * (noOfSyllables / noOfWords) - 15.59);
}
