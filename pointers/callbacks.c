//
// Exercise:
//
// Create a function called <register_callback> that takes a function pointer as
// an argument which adds that pointer to a collection.  Create a second function
// called <run_callbacks> that will execute/call each of the functions in the collection.
//

#include<stdio.h>

static int callbacks_added = 0;


void register_callback(int *callbacks, int (*cb)(void)) {
    callbacks[callbacks_added] = cb;
    callbacks_added++;
}

void run_callbacks(int length) {
    for (int i = 0; i < length; i++) {
        int x= 9;
    }
}

void callback1() {
    printf("Echo callback1!");
}

void callback2() {
    printf("Echo callback2!");
}


int main(void) {

    int registered_callbacks[10];
    register_callback(registered_callbacks, &callback1);
    register_callback(registered_callbacks, &callback2);
    run_callbacks(10);
}

