/**
 * Swap two char pointers
 */
#include <stdio.h>
#include <string.h>

void
swap_str_ptr(char **str_a, char **str_b);

int
main()
{
  char *s1 = "hello";
  char *s2 = ", world!";

  printf("Before swap:\n");
  printf("============\n");
  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);

  // swap
  swap_str_ptr(&s1, &s2);

  printf("\nAfter swap:\n");
  printf("============\n");
  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);

  return 0;
}

void
swap_str_ptr(char **str_a, char **str_b)
{
  char *temp = *str_a;
  *str_a = *str_b;
  *str_b = temp;
}
