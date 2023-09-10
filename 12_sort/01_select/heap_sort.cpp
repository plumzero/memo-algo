
// 堆排序

#include <stdio.h>

// 堆排序是对完全二叉树的操作

// 索引从 0 开始
// 先要明白(记住)几个下标(索引)
//  下标为 i 的节点的父节点下标: (i - 1) / 2
//  下标为 i 的节点的左孩子下标: i * 2 + 1
//  下标为 i 的节点的右孩子下标: i * 2 + 2

void adjust_heap(int a[], int i, int n);

// 建堆
void create_heap(int a[], int n)
{
  for (int s = (n - 1) / 2; s >= 0; s--) {
    adjust_heap(a, s, n);
  }
}

// 调整堆
void adjust_heap(int a[], int s, int n) // s 为父母节点索引
{
  int elem = a[s];
  for (int i = 2 * s + 1; i <= n; i = 2 * i + 1) {
    if (i < n && a[i] < a[i + 1])
      i++;
    if (elem > a[i])
      break;
    a[s] = a[i];
    s = i;
  }
  a[s] = elem;
}

void heap_sort(int a[], int len)
{
  create_heap(a, len - 1);

  for (int i = len - 1; i > 0; i--) {     // 将堆顶元素与最后一个元素交换，重新调整堆
    int elem = a[0];
    a[0] = a[i];
    a[i] = elem;
    adjust_heap(a, 0, i - 1);
  }
}

int main()
{
  int a[] = { 56, 22, 67, 32, 59, 12, 89, 26, 48, 37 };
  int len = sizeof(a) / sizeof(int);

  heap_sort(a, len);

  for (int i = 0; i < len; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}