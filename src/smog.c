#include <word_attributes.h>
#include <word_attributes2.h>
#include <math.h>
#include "smog.h"

int getNoOfSentence(const char *s);
int getPolysyllables(const char *s);

/**
 * getSmogScore - function calculate the readability of a text
 * based on Simple Measure of Gobbledygook (SMOG) index.
 *
 * @s: pointer to char array or string of text to be scored
 *
 * Return: float value which represent the score of the text.
 */

double getSmogScore(const char *s) {
    double noOfSentences = (double) getNoOfSentence(s);
    double noOfPolysyllables = (double) getPolysyllables(s);
    return (1.0430 * sqrt(noOfPolysyllables * (30 / noOfSentences)) + 3.1291);
}
