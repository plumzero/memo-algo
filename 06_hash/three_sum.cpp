
// 15 三数之和

// 在一个数组中，找到三个元素(这三个元素就是一个三元组)，使其相加等于 0
// 这个数组中可以找到多少组这样的元素(三元组不可重复)

// 示例
// 输入: nums=[-1,3,4,-3,0,-1,3,-3]
// 输出: [[-3,-1,4],[-3,0,3]]
// 注意 [0,0,0,0] 这组数据

// 分析
// 先将数组排序，定义两个指针分别指向排序后数组的头部和尾部。计算两个指针指向元素之和，然后利用二分查找确定剩下的一个元素

#include <vector>
#include <iostream>
#include <algorithm>

int bin_search(std::vector<int>& a, int low, int high, int val)
{
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (a[mid] > val)
      high = mid - 1;
    else if (a[mid] < val)
      low = mid + 1;
    else
      return mid;
  }

  return -1;
}

std::vector<std::vector<int>> three_sum(std::vector<int>& a)
{
  std::vector<std::vector<int>> alls;

  std::sort(a.begin(), a.end());

  int low = 0, high = (int)a.size() - 1;
  while (low < high) {
    int pos, val;
    val = 0 - (a[low] + a[high]);
    pos = bin_search(a, low, high, val);
    if (pos != -1) {
      alls.push_back({a[low], a[pos], a[high]});
    }
    int old_low = low;
    int old_high = high;
    while (low < high && a[old_low] == a[low])
      low++;
    while (low < high && a[old_high] == a[high])
      high--;
    if (low == old_high) {  // 当数组元素全为 0 时的情况
      return alls;
    }
    val = 0 - (a[low] + a[old_high]);
    pos = bin_search(a, low, old_high, val);
    if (pos != -1) {
      alls.push_back({a[low], a[pos], a[old_high]});
    }
    val = 0 - (a[old_low] + a[high]);
    pos = bin_search(a, old_low, high, val);
    if (pos != -1) {
      alls.push_back({a[old_low], a[pos], a[high]});
    }
  }

  return alls;
}

int main()
{
  {
    std::vector<int> nums = { -1, 3, 4, -3, 0, -1, 3, -3 };
    std::vector<std::vector<int>> results = three_sum(nums);
    for (size_t i = 0; i < results.size(); i++) {
      for (size_t j = 0; j < results[i].size(); j++) {
        std::cout << results[i][j] << ",";
      }
      std::cout << std::endl;
    }
  }

  {
    std::vector<int> nums = { 0, 0, 0, 0 };
    std::vector<std::vector<int>> results = three_sum(nums);
    for (size_t i = 0; i < results.size(); i++) {
      for (size_t j = 0; j < results[i].size(); j++) {
        std::cout << results[i][j] << ",";
      }
      std::cout << std::endl;
    }
  }

  {
    std::vector<int> nums = { 2, -1, 3, 7, -2, -1, 0, -1 };
    std::vector<std::vector<int>> results = three_sum(nums);
    for (size_t i = 0; i < results.size(); i++) {
      for (size_t j = 0; j < results[i].size(); j++) {
        std::cout << results[i][j] << ",";
      }
      std::cout << std::endl;
    }
  }

  return 0;
}