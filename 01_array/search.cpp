
// 704 二分查找

// 问题
// 在一个有序无重复元素的数组 nums 中，寻找一个元素 target，如果找到了就返回对应的下标，如果没找到就返回 -1 。

#include <vector>
#include <stdio.h>

int search(std::vector<int>& nums, int val)
{
  size_t low = 0, high = nums.size() - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] == val)
      return mid;
    if (nums[mid] > val)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return -1;
}

int main()
{
  {
    std::vector<int> vec{1, 2, 3, 4, 7, 9, 10};
    printf("%d\n", search(vec, 2));
  }

  {
    std::vector<int> vec{1, 2, 3, 4, 7, 9, 10};
    printf("%d\n", search(vec, 8));
  }
  
  return 0;
}