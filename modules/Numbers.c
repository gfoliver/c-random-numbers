#include "Numbers.h"
#include "Constants.h"

void reverse(int *numbers)
{
    int reversed[500] = {0};
 
    for (int i = 0; i < 500; i++) {
        reversed[500 - i] = numbers[i];
        if (numbers[i] == NUMBERS_LOADED_END)
            break;
    }
 
    int foundStart = 0;

    for (int i = 0; i < 500; i++) {
        if (foundStart == 1)
            numbers[i] = reversed[i];

        if (reversed[i] == NUMBERS_LOADED_END)
            foundStart = 1;
    }
}