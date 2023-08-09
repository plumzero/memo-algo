
// 问题
// 找到无序数组中前 n 个最小的元素

// 分析
// 选定一个值作为枢轴值，将小于等于该枢轴值的放在左边，大于等于该枢轴值的放在右边。
// 计算此时这个枢轴值的索引:
//  如果 index == n - 1, 则 [0, index] 就是前 n 个最小的元素
//  如果 index > n - 1, 则前 n 个最小的元素在左边
//  如果 index < n - 1, 则前 n 个最小的元素在右边  

// 分析二
// 首先利用无序数组的前 n 个元素建立一个大顶堆，然后将数组其余的元素依次与堆顶元素比较。
// 如果堆顶元素大于等于比较元素，则用此元素替换堆顶元素并调整堆，直到完成所有元素的比较。

#include <stdio.h>

int partition(int a[], int low, int high)
{
  int pivot = a[high];
  while (low < high) {
    while (low < high && pivot >= a[low])
      low++;
    a[high] = a[low];
    while (low < high && pivot <= a[high])
      high--;
    a[low] = a[high];
  }
  a[high] = pivot;

  return high;
}

int first_n_elements(int a[], int len, int n)
{
  if (len < n)
    return -1;

  int low = 0, high = len - 1;
  int index;
  do {
    index = partition(a, low, high);
    if (index > n - 1)
      high = index - 1;
    else if (index < n - 1)
      low = index + 1;
  } while (index != n - 1);

  return index;
}

// 分析二
void adjust_heap(int a[], int s, int n)
{
  int elem = a[s];
  for (int i = 2 * s + 1; i <= n; i = i * 2 + 1) {
    if (i < n && a[i] < a[i + 1])
      i++;
    if (elem > a[i])
      break;
    a[s] = a[i];
    s = i;
  }
  a[s] = elem;
}

int first_n_elements_2(int a[], int len, int n)
{
  if (len < n + 1)
    return -1;

  // 前 n 个元素建立一个大顶堆
  for (int s = (n - 1) / 2; s >= 0; s--) {
    adjust_heap(a, s, n);
  }

  for (int i = n + 1; i < len; i++) {
    if (a[0] >= a[i]) { // 注意，相等时也算
      int t = a[0];
      a[0] = a[i];
      a[i] = t;
      adjust_heap(a, 0, n);
    }
  }

  for (int i = 0; i < len; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}

int main()
{
  {
    int a[] = { 2, 5, 8, 9, 4, 3, 1, 6, 7 };
    int len = sizeof(a) / sizeof(int);

    int n = 3;
    int index = first_n_elements(a, len, n);

    for (int i = 0; i < n; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }

  {
    int a[] = { 2, 5, 8, 9, 4, 3, 1, 5, 6, 6, 7 };
    int len = sizeof(a) / sizeof(int);

    int n = 7;
    int index = first_n_elements(a, len, n);

    for (int i = 0; i < n; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }

  {
    int a[] = { 2, 5, 8, 9, 4, 3, 1, 5, 6, 6, 7 };
    int len = sizeof(a) / sizeof(int);

    int n = 7;
    first_n_elements_2(a, len, n - 1);
  }

  return 0;
}