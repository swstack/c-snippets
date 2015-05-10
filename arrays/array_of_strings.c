#include <stdio.h>

int main(int argc, char *argv[])
{
    // array of strings
    char *states[] = {
            "California", "Oregon",
            "Washington", "Texas"
    };

    char *c_style_string = "c style string";  // automatically null terminates

    char array_of_bytes[] = {'1', '2', '3', '4', '\0'};  // manual null term

    printf("%s\n", array_of_bytes);
    printf("%s\n", c_style_string);

    // This doesn't print correctly because there is no such thing as an
    // "array of strings" it's just a 2 dimensional array of characters
    printf("%s\n", states);
}
