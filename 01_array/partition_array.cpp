
/**
 * 将一个数组 A 分拆成两个部分，使 A 中大于等于某个值的元素放在左边，小于该值的元素放在右边。
 * 要求不占用额外的存储空间。
 */

#include <stdio.h>

void swap(int a[], int i, int j)
{
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

int partition_array(int a[], int len, int val)
{
  int i, j;
  i = j = 0;
  for (i = 0; i < len; i++) {
    if (a[i] >= val) {
      if (i != j) {
        swap(a, i, j);
      }
      j++;
    }
  }

  return j;
}

int main()
{
  int a[] = { -7, 0, 5, -8, 9, -4, 3, -2 };
  int len = sizeof(a) / sizeof(int);
  int pos = partition_array(a, len, 3);
  for (int i = 0; i < len; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  printf("pos=%d\n", pos);
  
  return 0;
}