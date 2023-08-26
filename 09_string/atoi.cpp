
#include <ctype.h>
#include <stdio.h>

int atoi(const char* str)
{
  while (isspace(*str)) str++;

  int neg = 0;
  switch (*str) {
    case '-': neg = 1;
    case '+': str++;
  }

  int n = 0;
  while (isdigit(*str)) {
    n = n * 10 - (*str - '0');
    str++;
  }

  return neg == 1 ? -n : n;
}

int main()
{
  {
    const char* ptr = "1234";
    printf("string %s to integer %d\n", ptr, atoi(ptr));
  }

  {
    const char* ptr = "-567";
    printf("string %s to integer %d\n", ptr, atoi(ptr));
  }

  {
    const char* ptr = " 1234";
    printf("string %s to integer %d\n", ptr, atoi(ptr));
  }

  {
    const char* ptr = " -567";
    printf("string %s to integer %d\n", ptr, atoi(ptr));
  }

  return 0;
}