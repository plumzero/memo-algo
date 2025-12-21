
// 不稳定排序

// 第一种方法

#include <stdio.h>

// 降序排列的话，只需要改为 pivot <= a[low] 和 pivot >= a[high] 即可

// 返回分区后枢轴索引
int partition(int a[], int low, int high)
{
  int pivot = a[high];
  while (low < high) {
    while (low < high && pivot >= a[low])      // 将最后一个元素作为枢轴元素，则必须先从前面往后比较；将第一个元素作为枢轴元素，则必须先从后面往前比较
      low++;
    a[high] = a[low];
    while (low < high && pivot <= a[high])
      high--;
    a[low] = a[high];
  }
  a[high] = pivot;

  return high;
}

void quick_sort(int a[], int low, int high)
{
  if (low < high) {
    int index = partition(a, low, high);
    quick_sort(a, low, index - 1);
    quick_sort(a, index + 1, high);
  }
}

// 不考虑异常传值
int main()
{
  int a[] = { 3, 2, 4, 6, 2, 8, 3, 7, 1 };

  int len = sizeof(a) / sizeof(int);
  quick_sort(a, 0, len - 1);

  for (int i = 0; i < len; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}