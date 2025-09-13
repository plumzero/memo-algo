
// 最大公约数

#include <stdio.h>

int gcd(int a, int b)
{
  if (a < b) {
    int tmp = a;
    a = b;
    b = tmp;
  }

	while (b != 0) {
		int r = b;
		b = a % b;
		a = r;
	}

    return a;
}

int main()
{
  printf("%d\n", gcd(285,220));

  return 0;
}