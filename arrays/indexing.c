#include <stdio.h>

int main(int argc, char *argv[])
{
    char foo[] = {'a', 'b', 'c', 'd', '\0'};

    printf("%s\n", foo);              // prints 'abcd'
    printf("%s\n", &foo);             // same thing
    printf("%c\n", foo[0]);           // prints 'a'
    printf("%c\n", foo[1]);           // prints 'b'
    printf("%c\n", (foo + 0)[0]);     // same as foo[0]
    printf("%c\n", (foo + 1)[0]);     // same as foo[1]
    printf("%c\n", *(foo + 0));     // same as foo[0]
    printf("%c\n", *(foo + 1));     // same as foo[1]

    // Q: How does the C compiler know that foo + 1 is actually foo + (sizeof(int)*1)?
    //    meaning... you would think that if foo is the beginning of an int array
    //    then to get the integer at index 1 you would need to offset by the length
    //    of one integer.
}
