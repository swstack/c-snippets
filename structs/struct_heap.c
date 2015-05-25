// Exercise for playing with structs and the heap using malloc/free

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


// Person struct definition
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight) {
    // Factory function for creating a Person struct in memory and
    // returning a pointer to it

    // malloc takes a single argument which is the size being requested
    struct Person *who = malloc(sizeof(struct Person));

    // The return value of malloc will either be a pointer to that memory address
    // or the `NULL` value (0) if it failed
    assert(who != NULL);

    // Use strdup to deep-copy the name
    // TODO: how might memcpy or malloc be used for this purpose?
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void Person_destroy(struct Person *who) {
    // Destruction function to free a Persons memory back to the heap
    assert(who != NULL);

    // It is important to explicitly free the persons name because we used
    // strdup in it's creation
    free(who->name);
    free(who);
}

void Person_print(struct Person *who) {
    // Print function where a Person struct is passed by reference using the heap

    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[]) {

    // make two people structures
    struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
