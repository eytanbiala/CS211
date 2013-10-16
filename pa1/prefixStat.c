#include <stdio.h>
#include <string.h>
#include "prefixStat.h"
#define FILENAME "test.dat"

int main(int argc, char *argv[]) {

	int i;
	if (argc == 1) {
		printHelp();
		return 0;
	}
	/* Check for a switch (leading "-"). */
	if (argv[1][0] == '-') {

	    /* Use the next character to decide what to do. */
		switch (argv[1][1]) {

			case 'h':	
			printHelp();
			break;

			case 'w':
			words();
			break;

			case 'l':
			lines();
			break;

			case 'p':
			if (argv[1][2]) {
				printf("Error: -p requires <input word> as an argument.\n");
				break;
			}
			else {
				prefix(argv[2]);
			}
			break;

			default:
			printf("\nError - argument not found.\n\n");
			printHelp();
			return 0;

		}
	}
	return 0;
}

void printHorizontalLine() {
	printf("--------------------\n");
	return;
}

void printHelp() {
	printf("\nHelp\n");
	printHorizontalLine();
	printf("Arguments:\n");
	printf("-h: access this help menu for information on running the program.\n");
	printf("-w: Output the words and word count.\n");
	printf("-l: Output the lines and line count.\n");
	printf("-p <input word>: Output the words in which the given input word apepars as a prefix.\n\n");
	return;
}

void words () {

	FILE * inFile;
	inFile = fopen(FILENAME, "r");
	if (inFile == NULL) {
		printf("\nError! Data file cannot be located. The file \"test.dat\" must be in the same directory.\n\n");		return;
	}
	printf("\nWords In The File: \n");
	printHorizontalLine();
	char temp[1000];
	unsigned int numWords = 0;
	while(fscanf(inFile, "%s", temp) != EOF) {
		printf("%s ", temp);
		numWords++;
	}
	printf("\n\n");
	printHorizontalLine();
	printf("\nNumber of words in the file: %i\n\n", numWords);
	return;
}

void lines() {
	FILE *inFile;
	inFile = fopen(FILENAME, "r");
	if (inFile == NULL) {
		printf("\nError! Data file cannot be located. The file \"test.dat\" must be in the same directory.\n\n");
		return;
	}
	unsigned int numLines=0;
	printf("\nLines In The File: \n");
	printHorizontalLine();
	char buf[1000];

	while ((fgets(buf, 1000, inFile)) != NULL) {
		printf("%s", buf);
		numLines++;
	} 

	printf("\n\n");
	printHorizontalLine();
	printf("\nNumber of lines in the file: %i\n\n", numLines);
	return;
}

void prefix(char inputWord[]) {

	FILE * inFile;
	inFile = fopen(FILENAME, "r");
	if (inFile == NULL) {
		printf("\nError! Data file cannot be located. The file \"test.dat\" must be in the same directory.\n\n");		return;
	}
	printf("\nWords with the prefix \"%s\":\n", inputWord);
	printHorizontalLine();
	char temp[1000];
	unsigned int numWords = 0;
	int inputLength = strlen(inputWord);

	while(fscanf(inFile, "%s", temp) != EOF) {
		int i = 0;
		while (temp[i] == inputWord[i] || temp[i] - 32 == inputWord[i] || temp[i] + 32 == inputWord[i]) {
			i++;
			if (i == inputLength) {
				printf("%s\n", temp);
				numWords++;
			}
		}
	}
	printf("\n\n");
	printHorizontalLine();
	printf("\nNumber of matching words: %i\n\n", numWords);
	return;
}