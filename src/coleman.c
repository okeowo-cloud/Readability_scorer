#include <word_attributes.h>
#include "colemanLiau.h"

int getNoOfWords(const char *s);
int getNoOfSentence(const char *s);
int getNoOfCharacter(const char *s);

/**
 * getColemanScore - function calculate the readability of a text
 * based on Coleman Liau index
 *
 * @s: A string or pointer to char array of text to be scored
 *
 * Return: A double value which represent the score of the text
 */

double getColemanScore(const char *s) 
{
    double avgCharacter = ((double)getNoOfCharacter(s) / (double)getNoOfWords(s)) * 100;
    double avgSentence = ((double)getNoOfSentence(s) / (double)getNoOfWords(s)) * 100;
    return (0.0588 * avgCharacter - 0.296 * avgSentence - 15.8);
}
