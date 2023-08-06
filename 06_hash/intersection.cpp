
// 349 两个数组的交集

// 问题
// 计算两个数组的交集，交集里的元素都是唯一的

// 分析
// 本问题中，并没有说明数组是否有序，所以是不适合进行数组的同时遍历的。
// 因为数组是无序的，可以考虑使用哈希。对第一个数组中的元素进行哈希化，然后遍历第二个数组中的元素，确认每个元素在
// 哈希中是否存在。

// 这里可以借助 unordered_map 或 unordered_set 进行处理，因为不涉及到统计，所以这里选择使用 unordered_set

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <iostream>

std::vector<int> intersection(std::vector<int>& a1, std::vector<int>& a2)
{
  std::unordered_set<int> hash(a1.begin(), a1.end());

  std::unordered_set<int> result;
  for (size_t i = 0; i < a2.size(); i++) {
    if (hash.find(a2[i]) != hash.end()) {
      result.insert(a2[i]);
    }
  }

  return std::vector<int>(result.begin(), result.end());
}

int main()
{
  {
    std::vector<int> nums1 = { 1, 2, 3, 4, 3, 6, 2, 1 };
    std::vector<int> nums2 = { 3, 3, 1 };

    std::vector<int> result = intersection(nums1, nums2);
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
  }

  return 0;
}