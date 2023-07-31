
// 求 x 的 n 次方

#include <stdio.h>

// O(n)
int x_power(int x, int n)
{
  if (n == 0)
    return 1;

  if (n % 2 == 1) {
    return x_power(x, n / 2) * x_power(x, n / 2) * x;
  }

  return x_power(x, n / 2) * x_power(x, n / 2);
}

// O(logn)
int x_power2(int x, int n)
{
  if (n == 0)
    return 1;

  int t = x_power2(x, n / 2);
  if (n % 2 == 1) {
    return t * t * x;
  }
  
  return t * t;
}

int main()
{
  {
    int x = 2, n = 3;
    printf("%d^%d=%d\n", x, n, x_power(x, n));
    printf("%d^%d=%d\n", x, n, x_power2(x, n));
  }

  {
    int x = 3, n = 4;
    printf("%d^%d=%d\n", x, n, x_power(x, n));
    printf("%d^%d=%d\n", x, n, x_power2(x, n));
  }

  return 0;
}