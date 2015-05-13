#include <stdio.h>

int main(int argc, char *argv[])
{
    int arr[5] = {};  // shorthand to initialize all to 0
    int *ptr = arr;
    int *nested_l1_ptr = ptr;
    int ***nested_l2_ptr = ptr;

    int i;
    for (i = 0; i < 5; i ++){
        printf("%d\n", arr[i]);
    }
    printf("---\n");
    for (i = 0; i < 5; i ++){
        printf("%d\n", ptr[i]);
    }
    printf("---\n");
    for (i = 0; i < 5; i ++){
        printf("%d\n", nested_l1_ptr[i]);
    }
    printf("---\n");
    for (i = 0; i < 5; i ++){
        printf("%d\n", nested_l2_ptr[i]);
    }
}
