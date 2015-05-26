#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message) {
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}

// Define a "fake" type by using `typedef`.  This fake type defines
// a callback-type with a particular signature that should be used...
// in this case the signature are two integer parameters
typedef int (*compare_cb)(int a, int b);

/**
 *
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp) {
    // Bubble sort implementation that uses the compare_cb to do the sorting
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if (!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    for (i = 0; i < count; i++) {
        for (j = 0; j < count - 1; j++) {
            if (cmp(target[j], target[j + 1]) > 0) {
                temp = target[j + 1];
                target[j + 1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;
}

int sorted_order(int a, int b) {
    return a - b;
}

int reverse_order(int a, int b) {
    return b - a;
}

int strange_order(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

void test_sorting(int *numbers, int count, compare_cb cmp) {
    // This function tests that we are sorting things correctly by
    // doing the sort and printing it to stdout

    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp);

    if (!sorted) die("Failed to sort as requested.");

    for (i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted);
}


int main(int argc, char *argv[]) {

    int unsorted[] = {4, 8, 3, 1, 5, 6, 2, 9, 7};
    int count = 9;

    test_sorting(unsorted, count, sorted_order);
    test_sorting(unsorted, count, reverse_order);
    test_sorting(unsorted, count, strange_order);

    return 0;
}