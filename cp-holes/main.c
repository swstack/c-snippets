#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>

static const char INPUT_FILE[] = "in_holey_file.txt";
static const char OUTPUT_FILE[] = "out_holey_file.txt";
static const int BUF_SIZE = 1;


bool has_holes(FILE *file_pointer) {
    /*
    * Return True if the file (*file_pointer) contains holes
    *
    * Files with "holes"  are fragmented files on the file system,
    * which means the file contents do not form a contiguous block
    * of memory.
    *
    * Note: To avoid the default buffering behavior of fread() the
    * BUF_SIZE needs to be 1 which is extremely inefficient but w/e
    * for this exercise.
    *
    */

    // get file size
    long file_size;
    fseek(file_pointer, 0L, SEEK_END);
    file_size = ftell(file_pointer);
    fseek(file_pointer, 0L, SEEK_SET);

    char buf[BUF_SIZE];
    ssize_t bytes_read;
    int total_bytes_read = 0;
    int i = 0;
    while ((bytes_read = fread(buf, 1, 1, file_pointer)) > 0) {
        total_bytes_read += bytes_read;
    }
    total_bytes_read += 1;
    return total_bytes_read > file_size;
}


main() {
    printf("Starting to copy contents of %s...\n", INPUT_FILE);

    FILE *input_fp = fopen(INPUT_FILE, "r");  // read mode
    FILE *output_fp = fopen(OUTPUT_FILE, "w");  // write mode

    if (input_fp == NULL) {
        printf("Error while opening %s.\n", INPUT_FILE);
        fclose(input_fp);
        fclose(output_fp);
        exit(EXIT_FAILURE);  // Exit with return code 1
    }

    if (output_fp == NULL) {
        printf("Error while opening %s.\n", OUTPUT_FILE);
        fclose(input_fp);
        fclose(output_fp);
        exit(EXIT_FAILURE);  // Exit with return code 1
    }

    if (has_holes(input_fp) != true) {
        printf("The input file (%s) has no holes!", INPUT_FILE);
        fclose(input_fp);
        fclose(output_fp);
        exit(EXIT_FAILURE);
    } else {
        printf("The input file has holes...continuing...\n");
    }

    fclose(input_fp);
    fclose(output_fp);

    printf("Copied to %s...\n", OUTPUT_FILE);
    printf("Complete.");
    exit(EXIT_SUCCESS);
}
