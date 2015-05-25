// In this exercise I will work with structs without using pointers to them.
// This will be done by allocating memory required for the struct on the stack
// instead of the heap.

#include <stdio.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};


void Person_print(struct Person who) {
    // Print function where a Person struct is passed by value which means
    // the person object is copied onto the stack in the scope for this function.
    // The downside to this over pass-by-reference is using more memory
    // on the stack.  Embedded systems often have very limited stack-sizes.

    printf("Name: %s\n", who.name);
    printf("\tAge: %d\n", who.age);
    printf("\tHeight: %d\n", who.height);
    printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[]) {
    struct Person bob;
    bob.name = "bob";
    bob.age = 20;
    bob.height = 500;
    bob.weight = 160;
    Person_print(bob);

    return 0;
}
