/**
 * Reverse a string
 *
 * More:
 *  http://codereview.stackexchange.com/questions/58959/is-this-a-fast-implementation-of-reversing-a-string
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void
reverse_char_array(char *str);

char *
reverse_string(char *dest, const char *src);

int main()
{
  char *s1 = "hello, world!";
  char s2[] = "foo bar";
  char *s3, *s4;
  char s5[] = "hello, world!";
  char s6[] = "";

  s3 = malloc(strlen(s1) * sizeof(char) + 1);
  s4 = malloc(strlen(s2) * sizeof(char) + 1);

  assert(s3);
  assert(s4);

  printf("Before reversing:\n");
  printf("=================\n");
  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);
  printf("s5: %s\n", s5);
  printf("s6: %s\n", s6);

  reverse_string(s3, s1);
  reverse_string(s4, s2);

  reverse_char_array(s5);
  reverse_char_array(s6);

  printf("\nAfter reversing:\n");
  printf("=================\n");
  printf("s3: %s\n", s3);
  printf("s4: %s\n", s4);
  printf("s5: %s\n", s5);
  printf("s6: %s\n", s6);

  return 0;
}

void
reverse_char_array(char *str)
{
  if (str == NULL) return;
  if (*str == '\0') return;

  char *start = str;
  char *end = start + strlen(str) - 1;
  char temp;

  while (end > start) {
    temp = *start;
    *start = *end;
    *end = temp;

    ++start;
    --end;
  }
}

char *
reverse_string(char *dest, const char *src)
{
  int i;
  size_t len = strlen(src);

  for (i = len; i > 0; i--) {
    *dest++ = src[i-1];
  }
  *dest = '\0';
  dest -= len;

  return dest;
}
