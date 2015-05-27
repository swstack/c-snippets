//
// Exercise:
//
// Create a function called <register_callback> that takes a function pointer as
// an argument which adds that pointer to a collection.  Create a second function
// called <run_callbacks> that will execute/call each of the functions in the collection.
//

#include<stdio.h>

// Define a type for the callbacks to be registered.  The callback
// should take no parameters and return nothing.
typedef void (*callback)();

// Global variable counting the callbacks added
#define MAX_CALLBACKS 10
int callbacks_added = 0;
int registered_callbacks[MAX_CALLBACKS];

void register_callback(callback cb) {
    registered_callbacks[callbacks_added] = cb;
    callbacks_added++;
}

void run_callbacks() {
    int i;
    for (i = 0; i < callbacks_added; i++) {
        callback cb = registered_callbacks[i];
        cb();
    }
}

void callback1() {
    printf("Echo callback1!\n");
}

void callback2() {
    printf("Echo callback2!\n");
}


int main(void) {
    register_callback(callback1);
    register_callback(callback2);
    run_callbacks();
}
