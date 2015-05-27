// The following "if not defined" C Pre-processor (CPP) declaration checks
// to see if the CPP variable `_object_h` already exists, if it does, it skips
// the following code, if it doesn't exist, it #define's the variable as the
// following code.
//
// The usage of #ifndef in this way is a common way to prevent multiple
// declarations of the same code if it is #includ'ed more than once!

#ifndef _object_h
#define _object_h

// Define a new type `Direction` which is an enum of the cardinal directions
typedef enum {
    NORTH,
    SOUTH,
    EAST,
    WEST
} Direction;

// Define a new type `Object` which is a struct (compound data type)
typedef struct {

    // Each object has a pointer to a string for its description
    char *description;

    // Each object contains a function-pointer to an "init" function
    int (*init)(void *self);

    // Each object contains a function-pointer to a "describe" function
    void (*describe)(void *self);

    // Each object contains a function-pointer to a "destroy" function
    void (*destroy)(void *self);

    // Each object contains a function-pointer to a "move" function
    void *(*move)(void *self, Direction direction);

    // Each object contains a function-pointer to a "attack" function
    int (*attack)(void *self, int damage);

} Object;


// The following define prototypes for functions provided by the object.c file
int Object_init(void *self);

void Object_destroy(void *self);

void Object_describe(void *self);

void *Object_move(void *self, Direction direction);

int Object_attack(void *self, int damage);

void *Object_new(size_t size, Object proto, char *description);


// Macros
#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)
#define _(N) proto.N

#endif
