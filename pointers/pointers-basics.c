#include <stdio.h>


int main(int argc, char *argv[]) {
  int x = 5;
  printf("---START---\n");
  printf("%d\n", x);
  printf("%d\n", &x);
  int *xp = &x;
  printf("%d\n", xp);
  printf("%c\n", *xp);
}
