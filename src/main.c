#include <main.h>
#include <word_attributes.h>
#include <word_attributes2.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * menu - function help user to navigate through
 * different route of the application.
 *
 * @text: pointer to char array or string of text
 *
 * Return: void
 */

void menu(char *text)
{
    const char* options[] = {"CL", "AR","FK","SM", "!!"};
    char input[3];
    input[1] = 'a';
    input[2] = 'b';
    input[3] = '\0';
    while (strcmp(input, "!!") != 0)
    {
	printf("Please enter the score you want to calculate (CL, AR, FK, SM !!->exit from program): ");
	int ch;
	/*while (i < 2 && (ch = getchar()) != '\n') {
		input[i] = ch;
		i++;
	}*/
	int i = 0;
	while (i < 2) {
            ch = getchar();
	    if (ch == '\n') break;
            input[i] = ch;
            i++;
	}
	input[2] = '\0'; 
	while (getchar() != '\n'){} // do nothing
	
	//input[i] = '\0'; // Null-terminate the string
	int choice;
	for (choice = 0; choice < sizeof(options) / sizeof(options[0]); choice++) {
        if (strcmp(input, options[choice]) == 0) break;
	}
        switch (choice) {
		case 0:
			double cl_score = getColemanScore(text);
			printf("The score of this text based on Coleman-Liau is: %lf\n", cl_score);
			break;
		case 1:
			double ar_score = getARScore(text);
               		printf("The score of this text based on Automated Readability is: %lf\n", ar_score);
			break;
		case 2:
   			double fk_score = getFleschScore(text);
                 	printf("The score of this text based on Flesch-Kincaid is: %lf\n", fk_score);
   			break;
  		case 3:
   			double sm_score = getSmogScore(text);
                	printf("The score of this text based on SMOG Readability is: %lf\n", sm_score);
   			break;

		case 4:
			printf("Okay Bye!\n");
			break;
		default:
			printf("Invalid option\n");
	}
    }
}


/**
 * This is the main program for Readability score
 *
 * @argc: stores number of arguments from stdin
 *
 * @argv: pointer to char array of all arguments
 *
 * Return: 0 on success and 1 on failure
 */

int main(int argc, char *argv[])
{
	printf("Welcome to Readability Scorer\n");

	if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return (1);  // Exit with an error code
    	}

	char text[10000];  // Adjust the buffer size as needed
	
	if (readTextFromFile(argv[1], text, sizeof(text))) {
		displayWordAttributes(text);
	} else {
		return (1);  // Exit with an error code
	}
	menu(text);
	return (0);
}
