/**
 * Return the maximum or minimum between two intergers
 */

#include <stdio.h>

#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

int
(max)(int a, int b)
{
  return a > b ? a : b;
}

int
(min)(int a, int b)
{
  return a < b ? a : b;
}

int
main()
{
  printf("Macro max and min:\n");
  printf("==================\n");

  printf("max(1, 2): %d\n", max(1, 2));
  printf("max(-1, 1): %d\n", max(-1, 1));
  printf("max(10, 0): %d\n", max(10, 0));

  printf("min(1, 2): %d\n", min(1, 2));
  printf("min(-1, 1): %d\n", min(-1, 1));
  printf("min(10, 0): %d\n", min(10, 0));

  printf("\nFunction max and min:\n");
  printf("=====================\n");

  #undef max
  #undef min

  printf("max(1, 2): %d\n", max(1, 2));
  printf("max(-1, 1): %d\n", max(-1, 1));
  printf("max(10, 0): %d\n", max(10, 0));

  printf("min(1, 2): %d\n", min(1, 2));
  printf("min(-1, 1): %d\n", min(-1, 1));
  printf("min(10, 0): %d\n", min(10, 0));

  return 0;
}
