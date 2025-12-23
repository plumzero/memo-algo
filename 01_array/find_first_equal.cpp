
// 查找第一个等于目标值的位置

// 问题
// 在一个有序无重复元素的数组 nums 中，寻找第一个与 target 相等的元素，如果找到了就返回对应的下标，如果没找到就返回 -1 。

#include <vector>
#include <stdio.h>

int binsearchfirst(std::vector<int>& nums, int target)
{
  size_t low = 0, high = nums.size() - 1;
  int result = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] >= target) {
      if (nums[mid] == target) result = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return result;
}

int main()
{
  {
    std::vector<int> vec{1, 2, 3, 4, 7, 9, 10};
    printf("%d\n", binsearchfirst(vec, 2));
  }

  {
    std::vector<int> vec{1, 2, 3, 2, 7, 9, 10};
    printf("%d\n", binsearchfirst(vec, 2));
  }

  {
    std::vector<int> vec{1, 2, 3, 4, 7, 9, 10};
    printf("%d\n", binsearchfirst(vec, 8));
  }
  
  return 0;
}