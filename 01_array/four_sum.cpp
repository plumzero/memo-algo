
// 18 四数之和

// 问题
// 在一个数组中，找到四个元素(这四个元素就是一个四元组)，使其相加等于 target。
// 问在这个数组中可以找到多少组这样的元组(四元组不可重复)?

// 示例
// 输入 nums=[-1,3,4,-3,0,-1,3,-3], target=0
// 输出 [ [-3,-3,3,3], [-3,-1,0,4] ]

// 分析
// 先将数组排序，将第一个元素 nums[0] 放在一边，求剩余元素三数之和为 target-nums[0] 的结果

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> four_sum(std::vector<int>& a)
{
  std::sort(a.begin(), a.end());

  std::vector<std::vector<int>> vec;
  int n = (int)a.size() - 1;

  for (int i = 0; i <= n - 4; i++) {
    if (i > 0 && a[i - 1] == a[i])
      continue;
    for (int j = i + 1; j <= n - 3; j++) {
      if (j > i + 1 && a[j - 1] == a[j])
        continue;
      int k = j + 1;
      int l = n - 1;
      while (k < l) {
        int sum = a[i] + a[j] + a[k] + a[l];
        if (sum == 0) {
          vec.push_back({a[i], a[j], a[k], a[l]});
          k++;
          l--;
          // 去重
          while (a[k - 1] == a[k])
            k++;
          while (a[l + 1] == a[l])
            l--;
        } else if (sum > 0) {
          l--;
        } else {
          k++;
        }
      }
    }
  }

  return vec;
}

int main()
{
  {
    std::vector<int> nums = { -1, 3, 4, -3, 0, -1, 3, -3 };
    std::vector<std::vector<int>> results = four_sum(nums);
    std::cout << "size = " << results.size() << std::endl;
    for (size_t i = 0; i < results.size(); i++) {
      for (size_t j = 0; j < results[i].size(); j++) {
        std::cout << results[i][j] << ",";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  return 0;
}