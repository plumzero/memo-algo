
// 239 滑动窗口最大值

// 问题
// 一个大小为 k 的滑动窗口，从前向后在数组 nums 移动，返回滑动窗口每移动一次时窗口中的最在值
// 要求时间复杂度为 O(n)

// 这里假设数组中每个元素都不一样

// 示例
// 输入 [2,4,-2,-4,3,1,5], k=4
// 输出 [4,4,3,5]
// 滑动窗口在数组上每移动一次后取窗口中的最大值，如下
// [2,4,-2,-4],3,1,5    4
// 2,[4,-2,-4,3],1,5    4
// 2,4,[-2,-4,3,1],5    3
// 2,4,-2,[-4,3,1,5]    5

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <iterator>

std::vector<int> max_sliding_window(const std::vector<int>& nums, int k)
{
  if (k > (int)nums.size())
    return {};

  std::vector<int> maxs;
  std::deque<int> queue;

  int i;
  for (i = 0; i < k; i++) {
    while (!queue.empty() && nums[i] > queue.back()) {
      queue.pop_back();
    }
    queue.push_back(nums[i]);
  }

  maxs.push_back(queue.front());

  for (i = k; i < (int)nums.size(); i++) {
    if (queue.front() == nums[i - k]) {
      queue.pop_front();
    }
    while (!queue.empty() && nums[i] > queue.back()) {
      queue.pop_back();
    }
    queue.push_back(nums[i]);
    maxs.push_back(queue.front());
  }

  return maxs;
}
// 上面的实现利用了单调队列的思想，也可以对单调队列进行封装后使用
class MyQueue
{
public:
  void push(int value) {
    while (!que.empty() && value > que.back()) {
      que.pop_back();
    }
    que.push_back(value);
  }
  void pop(int value) {
    if (!que.empty() && que.front() == value) {
      que.pop_front();
    }
  }
  int front() {
    return que.front();
  }

std::deque<int> que;
};

std::vector<int> max_sliding_window2(const std::vector<int>& nums, int k)
{
  MyQueue queue;
  std::vector<int> maxs;

  int i;
  for (i = 0; i < k; i++) {
    queue.push(nums[i]);
  }

  maxs.push_back(queue.front());

  for (i = k; i < (int)nums.size(); i++) {
    queue.pop(nums[i - k]);
    queue.push(nums[i]);
    maxs.push_back(queue.front());
  }
  
  return maxs;
}

int main()
{
  {
    std::vector<int> maxs = max_sliding_window({2, 4, -2, -4, 3, 1, 5}, 4);
    std::copy(maxs.begin(), maxs.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
  }

  {
    std::vector<int> maxs = max_sliding_window2({2, 4, -2, -4, 3, 1, 5}, 4);
    std::copy(maxs.begin(), maxs.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
  }

  return 0;
}