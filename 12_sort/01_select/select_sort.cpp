
// 稳定排序

// 以升序排序为例，在简单选择排序中，每次循环时要选择一个剩余值中最小的元素放在已排序元素的后面。
// 例如待排序列 3 1 2 4 , 第一次循环结果将 1 放在索引 0 上，第二次循环结果将 2 放在索引 1 上，第
// 三次循环结果将 3 放在索引 2 上，而最后一个元素 4 肯定是最大值，将其直接放在最后的索引 3 上，不必
// 再循环。所以整个循环次数应该是 len - 1, 其中 len 为待排元素个数

// 内层比较循环没有什么好说的

#include <stdio.h>

void select_sort(int a[], int len)
{
  for (int i = 0; i < len - 1; i++) {  // 因为最后一个元素没有了比较对象，所以只需要遍历 len - 1 次
    int j = i; // j 记录 [i, len - 1] 范围内最小值的索引
    for (int k = i + 1; k < len; k++) {
      if (a[j] > a[k])  // 降序排改为 a[j] < a[k]
        j = k;
    }
    if (i != j) {
      int t = a[i];
      a[i] = a[j];
      a[j] = t;
    }
  }

  for (int i = 0; i < len; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main()
{
  int a[] = { 56, 22, 67, 32, 59, 12, 89, 26, 48, 37 };

  select_sort(a, sizeof(a)/sizeof(int));

  return 0;
}