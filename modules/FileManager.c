#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "FileManager.h"
#include "Constants.h"

void appendToFile(int numbersAmount) {
    FILE *fileToAppend = fopen("numbers.txt", "a");
    
    char data[4] = { 0 }; // Max = 100 + ;
    
    int randomNumber = rand() % 100;

    snprintf(data, sizeof data, "%d;", randomNumber);

    fputs(data, fileToAppend);

    fclose(fileToAppend);

    if (numbersAmount > 1)
        appendToFile(numbersAmount - 1);
}

void appendBinaryToFile(int numbersAmount) {
    FILE *fileToAppend = fopen("numbers.txt", "a");
    
    char data[4] = { 0 }; // Max = 100 + ;
    
    int randomNumber = rand() % 2;

    snprintf(data, sizeof data, "%d;", randomNumber);

    fputs(data, fileToAppend);

    fclose(fileToAppend);

    if (numbersAmount > 1)
        appendBinaryToFile(numbersAmount - 1);
}

void generateFile(int numbersAmount) {
    if (numbersAmount < 100){
        printf("No minimo 100 numeros\n");
        return;
    }

    FILE *fp = fopen("numbers.txt", "w");
    fclose(fp);

    //Start the random number generator
	srand(time(0));
    
    appendToFile(numbersAmount);
};

void generateBinaryFile(int numbersAmount) {
    if (numbersAmount < 100){
        printf("No minimo 100 numeros\n");
        return;
    }

    FILE *fp = fopen("numbers.txt", "w");
    fclose(fp);

    //Start the random number generator
	srand(time(0));
    
    appendBinaryToFile(numbersAmount);
};

void readFile(int *ret) {
    FILE *fp = fopen("numbers.txt", "r");
    
    char tempString[500];

    fgets(tempString, sizeof(tempString), fp);

    char tempNumber[4] = {0};
    int tempAdded = 0;

    int retAdded = 0;


    for (int i = 0; i < strlen(tempString); i++) {
        if (tempString[i] == ';') {
            if (!strlen(tempNumber))
                break;

            sscanf(tempNumber, "%d", &ret[retAdded]);
            retAdded++;

            tempNumber[0] = 0;
            tempNumber[1] = 0;
            tempNumber[2] = 0;
            tempNumber[3] = 0;
            tempAdded = 0;
            continue;
        }

        tempNumber[tempAdded] = tempString[i];
        tempAdded++;
    }

    ret[retAdded] = NUMBERS_LOADED_END;
}

void replaceFileWithString(char *string) {
    FILE *fp = fopen("numbers.txt", "w");
    fputs(string, fp);
    fclose(fp);
}