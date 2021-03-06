#include <stdio.h>

// This program prints the same two arrays in 4 different ways using pointer magic,
// some of them being more practical than others.


int main(int argc, char *argv[]) {

    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
            "Alan",
            "Frank",
            "Mary",
            "John",
            "Lisa"
    };

    // Getting the length (number of elements) of an array safely, takes some arithmetic.
    // Using sizeof(array) will return the total size of bytes of all the elements
    // in the arrays.  This is not quite what we want.  So we must know the size of
    // each element in the array and divide by that to get the "length" of the array.
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // Method #1
    for (i = 0; i < count; i++) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    printf("---\n");

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    // Method #2 - using pointers
    for (i = 0; i < count; i++) {
        printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    }

    printf("---\n");

    // Method #3 - pointers are just arrays
    for (i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // Method #4 - pointers in a stupid complex way
    for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }

    return 0;
}
