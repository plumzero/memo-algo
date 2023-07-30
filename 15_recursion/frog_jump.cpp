
/**
 * 青蛙跳台阶，一次只能跳一阶或两阶。
 * 问: 对于 n 阶台阶，一共有多少种跳法(n > 0)
*/

#include <stdio.h>

int jump(int n)
{
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;
  
  return jump(n - 2) + jump(n - 1);
}

int jump2(int n)
{
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;
  
  int a1 = 1;
  int a2 = 2;
  int a;
  for (int i = 2; i < n; i++) {
    // 可以想像成三个盒子，依次改变三个盒子中的数字
    a = a1 + a2;
    a1 = a2;
    a2 = a;
  }

  return a;
}

int main()
{
  {
    int n = 5;
    printf("%d 阶跳法: %d\n", n, jump(n));
    printf("%d 阶跳法: %d\n", n, jump2(n));
  }

  {
    int n = 10;
    printf("%d 阶跳法: %d\n", n, jump(n));
    printf("%d 阶跳法: %d\n", n, jump2(n));
  }

  return 0;
}