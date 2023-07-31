
// 5 合并两个有序数组，使合并后的数组依然有序

// 问题
// 略

#include <stdio.h>

#define CAPACITY 100

// 从后向前
void merge_sort_array(int a1[], int a1len, int a2[], int a2len)
{
  if (a1len + a2len > CAPACITY)
    return ;
  
  int pos1 = a1len - 1;
  int pos2 = a2len - 1;
  int pos = a1len + a2len - 1;
  while (pos1 >= 0 && pos2 >= 0) {
    if (a1[pos1] > a2[pos2]) {
      a1[pos--] = a1[pos1--];
    } else {
      a1[pos--] = a2[pos2--];
    }
  }

  while (pos1 >= 0) {
    a1[pos--] = a1[pos1--];
  }

  while (pos2 >= 0) {
    a1[pos--] = a2[pos2--];
  }
}

int main()
{
  int a1[CAPACITY] = { 1, 3, 5, 7, 8, 10, 12 };   // len 7
  int a2[] = { 4, 6, 8, 11 };     // len 4

  merge_sort_array(a1, 7, a2, 4);
  
  for (int i = 0; i < 11; i++) {
    printf("a1[%d]=%d\n", i, a1[i]);
  }

  printf("len(a1)=%ld", sizeof(a1) / sizeof(int));

  return 0;
}
