
// 1 两数之和

// 问题
// 在数组中找到两个元素的数值之和为目标值，返回这两个元素的下标

// 输入 nums=[2,7,11,15], target=9
// 输出 [0,1]

// 分析
// 因为需要同时保存元素及对应的索引，所以这里借助 std::unordered_map

#include <vector>
#include <unordered_map>
#include <iostream>

std::vector<int> two_sum(std::vector<int>& nums, int target)
{
  std::unordered_map<int, int> hash;
  for (size_t i = 0; i < nums.size(); i++) {
    int val = nums[i];
    int another = target - val;
    if (hash.find(another) != hash.end()) {
      return {hash[another], (int)i};
    }
    hash.insert({val, i});
  }

  return {};
}

int main()
{
  {
    std::vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    std::vector<int> pair = two_sum(nums, target);
    if (pair.size() == 2) {
      std::cout << "[" << pair[0] << "," << pair[1] << "]" << std::endl;
    }
  }

  return 0;
}
