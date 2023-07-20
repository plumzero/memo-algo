
/**
 * 将一个数组 A 分拆成两个部分，使 A 中大于等于某个值的元素放在左边，小于该值的元素放在右边。
 * 要求不占用额外的存储空间。
 */

#include <stdio.h>

void partition_array(int a[], int len, int comp)
{
  int front = 0;
  int last = len - 1;

  while (front < last) {
    while (a[front] >= comp)
      front++;
    while (a[last] < comp)
      last--;
    if (front < last) {
      int tmp = a[front];
      a[front] = a[last];
      a[last] = tmp;
    }
  }

}

int main()
{
  int a[] = { -7, 0, 5, -8, 9, -4, 3, -2 };
  int len = sizeof(a) / sizeof(int);
  partition_array(a, len, 3);
  for (int i = 0; i < len; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  
  return 0;
}