
#include <stdio.h>

// 不考虑异常输入情况
// 成功返回索引，失败返回 -1
int binary_search(int a[], int len, int val)
{
  int low = 0, high = len - 1, mid;

  while (low <= high) {
    mid = low + (high - low) / 2;
    if (a[mid] == val)
      return mid;
    if (a[mid] > val)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return -1;
}

// 递归实现(升序查找)
int binary_search2(int a[], int low, int high, int val)
{
  if (low <= high) {
    int mid = low + (high - low) / 2;
    if (a[mid] == val)
      return mid;
    if (a[mid] > val)
      return binary_search2(a, low, mid - 1, val);
    return binary_search2(a, mid + 1, high, val);
  }

  return -1;
}

int main()
{
  {
    int a[] = { 12, 22, 26, 32, 37, 48, 56, 59, 67, 89 };
    int len = sizeof(a) / sizeof(int);

    printf("%d\n", binary_search(a, len, 32));
    printf("%d\n", binary_search2(a, 0, len - 1, 32));
  }

  {
    int a[] = { 12, 22, 26, 32, 37, 48, 56, 59, 67, 89 };
    int len = sizeof(a) / sizeof(int);

    printf("%d\n", binary_search(a, len, 55));
    printf("%d\n", binary_search2(a, 0, len - 1, 55));
  }

  return 0;
}