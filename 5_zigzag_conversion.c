#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1 || numRows >= len) {
        char* result = malloc(len + 1);
        strcpy(result, s);
        return result;
    }

    char* result = malloc(len + 1);
    int index = 0;

    int cycle = 2 * numRows - 2;

    for (int row = 0; row < numRows; row++) {
        for (int j = 0; j + row < len; j += cycle) {
            result[index++] = s[j + row];

            int diagonal = j + cycle - row;

            if (row != 0 && row != numRows - 1 &&
                diagonal < len) {
                result[index++] = s[diagonal];
            }
        }
    }

    result[index] = '\0';

    return result;
}
