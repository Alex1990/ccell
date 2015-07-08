/**
 * XOR swap algorithm
 *
 * More:
 *  - https://en.wikipedia.org/wiki/XOR_swap_algorithm
 *  - http://stackoverflow.com/questions/249423/how-does-xor-variable-swapping-work
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void
xor_swap(char *a, char *b);

void
swap_int(int *a, int *b);

void
reverse_string(char *str);

int
main()
{
  int *num1;
  int *num2;
  char str1[] = "";
  char str2[] = "foo bar";

  num1 = malloc(sizeof(int));
  num2 = malloc(sizeof(int));

  assert(num1);
  assert(num2);

  *num1 = 1;
  *num2 = 2;

  printf("Before swap:\n");
  printf("============\n");
  printf("*num1: %d\n", *num1);
  printf("*num2: %d\n", *num2);
  printf("str1: %s\n", str1);
  printf("str2: %s\n", str2);

  // Swap two integers
  swap_int(num1, num2);
  
  // Reverse string
  reverse_string(str1);
  reverse_string(str2);

  printf("\nAfter swap:\n");
  printf("============\n");
  printf("*num1: %d\n", *num1);
  printf("*num2: %d\n", *num2);
  printf("str1: %s\n", str1);
  printf("str2: %s\n", str2);

  return 0;
}

void
xor_swap(char *a, char *b)
{
  if (a != b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
  }
}

void
swap_int(int *a, int *b)
{
  if (a != b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
  }
}

void
reverse_string(char *str)
{
  if (str) {
    char *start = str;
    char *end = start + strlen(str) - 1;

    while (start < end) {
      xor_swap(start, end);
      start++;
      end--;
    }
  }
}
