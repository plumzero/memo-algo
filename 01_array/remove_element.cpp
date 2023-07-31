
// 27 移除元素

// 问题
// 原地移除数组中所有等于 val 的元素，要求不能使用额外的辅助空间，即空间复杂度为 O(1)
// 返回移除元素后新数组的 size

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

void swap(std::vector<int>& nums, int i, int j)
{
  int t = nums[i];
  nums[i] = nums[j];
  nums[j] = t;
}

// 双指针法
// 参考 23_other/partition_3.cp 代码
int remove_element(std::vector<int>& nums, int val)
{
  int i, j;
  i = j = 0;
  for (i = 0; i < (int)nums.size(); i++) {
    if (nums[i] != val) {
      if (i != j)
        swap(nums, i, j);
      j++;
    }
  }

  return j;
}

int main()
{
  {
    std::vector<int> vec{4, 5, 6, 4, 4, 4};
    int size = remove_element(vec, 4);
    std::cout << "size=" << size << std::endl;

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
  }

  return 0;
}