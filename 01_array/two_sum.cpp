
// 在一个数组中，找到两个元素(这两个元素就是一个二元组)，使其相加等于 target
// 这个数组中可以找到多少组这样的元素(二元组不可重复)

// 示例
// 输入 nums=[-1,3,4,-3,0,-1,3,-3], target=0
// 输出 [ [-3,-3,3,3], [-3,-1,0,4] ]

#include <vector>
#include <algorithm>
#include <iostream>

std::vector<std::vector<int>> two_sum(std::vector<int>& a, int target)
{
  std::sort(a.begin(), a.end());

  int low = 0;
  int high = (int)a.size() - 1;

  std::vector<std::vector<int>> sums;

  while (low < high) {
    int sum = a[low] + a[high];
    if (sum == target) {
      sums.push_back({a[low], a[high]});
      high--;
      low++;
      // 去重
      while (a[high] == a[high + 1])
        high--;
      while (a[low] == a[low + 1])
        low++;
    } else if (sum > target) {
      high--;
    } else {
      low++;
    }
  }

  return sums;
}

int main()
{
  {
    std::vector<int> nums = { -1, 3, 4, -3, 0, -1, 3, -3, -4 };
    int target = 0;
    std::vector<std::vector<int>> sums = two_sum(nums, target);
    
    std::cout << sums.size() << std::endl;
    for (size_t i = 0; i < sums.size(); i++) {
      for (size_t j = 0; j < sums[i].size(); j++) {
        std::cout << sums[i][j] << ",";
      }
      std::cout << std::endl;
    }
  }

  {
    std::vector<int> nums = { -1, 3, 4, -3, 0, -1, 3, -3, -4 };
    int target = 1;
    std::vector<std::vector<int>> sums = two_sum(nums, target);
    
    std::cout << sums.size() << std::endl;
    for (size_t i = 0; i < sums.size(); i++) {
      for (size_t j = 0; j < sums[i].size(); j++) {
        std::cout << sums[i][j] << ",";
      }
      std::cout << std::endl;
    }
  }

  return 0;
}