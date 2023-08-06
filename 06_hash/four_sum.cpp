
// 18 四数之和

// 问题
// 在一个数组中，找到四个元素(这四个元素就是一个四元组)，使其相加等于 target。
// 问在这个数组中可以找到多少组这样的元组(四元组不可重复)?

// 示例
// 输入 nums=[-1,3,4,-3,0,-1,3,-3], target=0
// 输出 [ [-3,-3,3,3], [-3,-1,0,4] ]

// 分析
// 先将数组排序，将第一个元素 nums[0] 放在一边，求剩余元素三数之和为 target-nums[0] 的结果

// 程序仍然有点问题...

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

void three_sum(std::vector<int>& a, int low, int high, int fixed, int remain, std::vector<std::vector<int>>& results)
{
  while (low < high) {
    int pos, val;
    val = remain - (a[low] + a[high]);
    pos = bin_search(a, low, high, val);
    if (pos != -1) {
      results.push_back({a[fixed], a[low], a[pos], a[high]});
    }
    int old_low = low;
    int old_high = high;
    while (low < high && a[old_low] == a[low])
      low++;
    while (low < high && a[old_high] == a[high])
      high--;
    val = remain - (a[low] + a[old_high]);
    pos = bin_search(a, low, old_high, val);
    if (pos != -1) {
      results.push_back({a[fixed], a[low], a[pos], a[old_high]});
    }
    val = remain - (a[old_low] + a[high]);
    pos = bin_search(a, old_low, high, val);
    if (pos != -1) {
      results.push_back({a[fixed], a[old_low], a[pos], a[high]});
    }
  }
}

std::vector<std::vector<int>> four_sum(std::vector<int>& a, int target)
{
  std::vector<std::vector<int>> results;

  std::sort(a.begin(), a.end());

  int low = 0, high = (int)a.size() - 1;
  while (low < high) {
    three_sum(a, low + 1, high, low, target - a[low], results);
    // three_sum(a, low, high - 1, high, target - a[high], results);
    int old_low = low;
    int old_high = high;
    while (low < high && a[old_low] == a[low])
      low++;
    // while (low < high && a[old_high] == a[high])
    //   high--;
  }

  return results;
}

int main()
{
  {
    std::vector<int> nums = { -1, 3, 4, -3, 0, -1, 3, -3 };
    std::vector<std::vector<int>> results = four_sum(nums, 0);
    for (size_t i = 0; i < results.size(); i++) {
      for (size_t j = 0; j < results[i].size(); j++) {
        std::cout << results[i][j] << ",";
      }
      std::cout << std::endl;
    }
  }

  return 0;
}