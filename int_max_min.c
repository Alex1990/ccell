/**
 * Return the maximum or minimum between two intergers or other objects
 *
 * Macro notes:
 *  - Side-effect
 *  - operator precedence
 *
 * More:
 * - https://gcc.gnu.org/onlinedocs/gcc-3.4.6/gcc/Min-and-Max.html
 * - http://stackoverflow.com/questions/3437404/min-and-max-in-c
 */

#include <stdio.h>

#define max(a,b) \
  ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
   _a > _b ? _a : _b; })

#define min(a,b) \
  ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
   _a < _b ? _a : _b; })

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
  printf("max('a', 'A'): %c\n", max('a', 'A'));
  printf("max(1.2345, 1.234): %f\n", max(1.2345, 1.234));
  printf("max(42L, 49L): %lu\n", max(42L, 49L));

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
