#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int add(int a, int b);
int readTextFromFile(const char *filename, char *text, int maxTextSize);
double getColemanScore(const char *s);
double getARScore(const char *s);
double getSmogScore(const char *s);
double getFleschScore(const char *s);
#endif /* __MAIN_H__ */
