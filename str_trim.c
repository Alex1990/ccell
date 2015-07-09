/**
 * Remove whitespace in a string
 *
 * Whitespace: "\t\n\v\f\r ", equivalent to isspace()
 * More:
 *  - https://en.wikipedia.org/wiki/Trimming_(computer_programming)#C.2FC.2B.2B
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define log printf

char *
str_ltrim(char *dest, const char *src)
{
  size_t n = 0;

  while (src[n] != '\0' && isspace((unsigned char)src[n])) {
    ++n;
  }

  while (src[n] != '\0') {
    *dest = src[n];
    ++dest;
    ++n;
  }
  *dest = '\0';

  return dest;
}

char *
str_rtrim(char *dest, const char *src)
{
  size_t i;
  size_t n = strlen(src);

  while (n > 0 && isspace((unsigned char)src[n - 1])) {
    n--;
  }

  for (i = 0; i < n; i++) {
    *dest = src[i];
    ++dest;
  }
  *dest = '\0';

  return dest;
}
  
char *
str_trim(char *dest, const char *src)
{
  if (src == NULL) return dest;

  size_t i;
  size_t start;
  size_t end;
  
  start = 0;
  while (src[start] != '\0' && isspace((unsigned char)src[start])) {
    ++start;
  }

  end = strlen(src);
  while (end > 0 && isspace((unsigned char)src[end - 1])) {
    --end;
  }

  for (i = start; i < end; i++) {
    *dest = src[i];
    ++dest;
  }
  *dest = '\0';

  return dest;
}

int
main()
{
  int type = 0; // 0: trim, 1: ltrim, 2: rtrim
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

  /* Print the values before trim */

  log("Before trim\n");
  log("===========\n");

  log("src1: %s\n", src1);
  log("src2: %s\n", src2);
  log("src3: %s\n", src3);

  /* Select trim type */

  log("Select trim type and press \"Enter\" to confirm:\n");
  log("=========\n");
  log("0 - trim\n");
  log("1 - ltrim\n");
  log("2 - rtrim\n");
  log("\n");

  scanf("%d", &type);

  /* Trim */

  switch (type) {
    case 1:
      str_ltrim(dest1, src1);
      str_ltrim(dest2, src2);
      str_ltrim(dest3, src3);
      break;
    case 2:
      str_rtrim(dest1, src1);
      str_rtrim(dest2, src2);
      str_rtrim(dest3, src3);
      break;
    default:
      str_trim(dest1, src1);
      str_trim(dest2, src2);
      str_trim(dest3, src3);
  }

  /* Print the values after trim */

  log("\nAfter trim\n");
  log("============\n");

  log("dest1: %s\n", dest1);
  log("dest2: %s\n", dest2);
  log("dest3: %s\n", dest3);

  return 0;
}
