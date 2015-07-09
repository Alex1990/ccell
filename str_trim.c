/**
 * Remove whitespace in a string
 *
 * Whitespace: "\t\n\v\f\r ", equivalent to isspace()
 */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define log printf

char *
str_trim(char *dest, const char *src)
{
  if (src == NULL) return dest;

  char ch;
  bool is_left_space = true;
  size_t len;
  size_t space_count = 0;
  
  while ((ch = *src) != '\0') {
    if (is_left_space) {
      if (!isspace(ch)) {
        is_left_space = false;
        *dest = ch;
        ++dest;
      } else {
        ++space_count;
      }
    } else {
      *dest = ch;
      ++dest;
    }
    ++src;
  }

  len = strlen(src) - space_count;

  while (len--) {
    if (!isspace(dest[len])) {
      dest[len + 1] = '\0';
      break;
    }
  }

  return dest;
}

int
main()
{
  char *src1 = "\t\n\f\v\r hello world\t\n\f\v\r ";
  char src2[] = "\t\n\f\v\r hello world\t\n\f\v\r ";
  char *src3 = "";
  char *dest1;
  char *dest2;
  char *dest3;

  dest1 = malloc(strlen(src1) * sizeof(char) + 1);
  dest2 = malloc(strlen(src2) * sizeof(char) + 1);
  dest3 = malloc(strlen(src3) * sizeof(char) + 1);

  assert(dest1 != NULL);
  assert(dest2 != NULL);
  assert(dest3 != NULL);

  log("Before trim\n");
  log("===========\n");

  log("src1: %s\n", src1);
  log("src2: %s\n", src2);
  log("src3: %s\n", src3);

  str_trim(dest1, src1);
  str_trim(dest2, src2);
  str_trim(dest3, src3);

  log("\nAfter trim\n");
  log("============\n");

  log("dest1: %s\n", dest1);
  log("dest2: %s\n", dest2);
  log("dest3: %s\n", dest3);

  return 0;
}
