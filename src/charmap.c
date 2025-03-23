#include "../include/charmap.h"

int *create_charmap() {
    int* charmap = malloc(sizeof(int) * CHARMAP_SIZE);
    for (int index = 0; index < CHARMAP_SIZE; index++) {
        charmap[index] = 0;
    }

    return charmap;
}

int *get_charmap(char* string) {
    int *charmap = create_charmap();

    for (int index = 0; string[index] != '\0'; index++) {
        char c = string[index];
        if (c >= 'a') { c -= 'a' - 'A'; }

        int index = c - 'A';
        if (index >= CHARMAP_SIZE) {
            continue;
        }

        charmap[index] += 1; 
    }

    return charmap;
}

bool charmap_eq(int *first_charmap, int *second_charmap) {
    for (int index = 0; index < CHARMAP_SIZE; index++) {
        if (first_charmap[index] != second_charmap[index]) {
            return false;
        }
    }

    return true;
}
