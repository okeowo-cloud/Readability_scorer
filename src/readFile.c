#include <stdio.h>

/**
 * readTextFromFile - function read in a file.
 *
 * @filename: pointer to char array or string
 * which represent the path to a file
 *
 * @text: pointer to char array to hold value
 * of string in file.
 *
 * @maxTextSize: represent the maximum size of
 * file to be read.
 *
 * Return: 1 on success and 0 on failure
 */

int readTextFromFile(const char *filename, char *text, int maxTextSize) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open the file");
        return (0);  // Indicate failure
    }

    if (fgets(text, maxTextSize, file) == NULL) {
        perror("Failed to read from the file");
        fclose(file);
        return (0);  // Indicate failure
    }

    fclose(file);
    return (1);  // Indicate success
}
