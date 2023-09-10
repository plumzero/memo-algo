
// 不稳定排序

// 希尔排序思想是容易理解，但代码写起来可能无从着手。事实上，在代码结构上，希尔排序和直接插入排序很像，
// 能写直接插入排序，也就会写希尔排序了

#include <stdio.h>

// 记住: 8 个 h
void shell_sort(int a[], int len)
{
  int h = 5;

  while (h >= 1) {
    for (int i = h; i < len; i++) {
      int elem = a[i];
      int j;
      for (j = i - h; j >= 0; j -= h) {
        if (a[j] > elem)
          a[j + h] = a[j];
        else
          break;
      }
      a[j + h] = elem;
    }
    h /= 2; // 缩减增量，直至为 1。(不一定除以 2，但必须要保证最终执行了一次增量 1)
  }
}

int main()
{
  int a[] = { 56, 22, 67, 32, 59, 12, 89, 26, 48, 37 };
  int len = sizeof(a) / sizeof(int);

  shell_sort(a, len);

  for (int i = 0; i < len; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}