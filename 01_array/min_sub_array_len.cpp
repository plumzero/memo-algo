
// 209 长度最小的子数组

// 问题
// 在一个正整数数组 nums 中找到最小长度的连续子数组，使子数组元素之和大于或等于 s 。

#include <vector>
#include <iostream>
#include <limits.h>


// 滑动窗口
int min_sub_array_len(std::vector<int>& nums, int s)
{
  int i, j;
  i = j = 0;

  int sum = 0;
  int len = INT_MAX;
  for (i = 0; i < (int)nums.size(); i++) {
    sum += nums[i];
    while (sum >= s) {    // if 要变成 while
      int slen = (i - j + 1);
      len = (slen < len) ? slen : len;
      sum -= nums[j];
      j++;    // 向后移动窗口的起始位置 
    }
  }

  return len == INT_MAX ? 0 : len;
}

int main()
{
  {
    std::vector<int> vec{4, 6, 2, 4, 9, 8, 7};
    int len = min_sub_array_len(vec, 12);
    std::cout << "len = " << len << std::endl;
  }

  return 0;
}
