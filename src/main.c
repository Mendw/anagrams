#include "../include/main.h"

int main() {
    char *first_string = get_user_input();
    int *first_charmap = get_charmap(first_string);

    char *second_string = get_user_input();
    int *second_charmap = get_charmap(second_string);

    bool is_anagram = charmap_eq(first_charmap, second_charmap);
    if (is_anagram) {
        printf("%s and %s are anagrams\n", first_string, second_string);
    } else {
        printf("%s and %s are NOT anagrams\n", first_string, second_string);
    }

    return 0;
}