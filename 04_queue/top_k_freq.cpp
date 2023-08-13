
// 347 前 k 个高频元素

// 问题
// 在一个数组中找到出现频率前 k 高的元素

// 示例一
// 输入 nums=[2,2,2,2,2,3,3,3,1], k=2
// 输出 [2,3]

// 步骤:
// 1. 统计元素出现的次数
// 2. 对次数排序
// 3. 找出前 k 个高频元素

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>

// 调整堆
void adjust_heap(std::vector<std::pair<int, int>>& heap, int s, int n)
{
  std::pair<int, int> elem = heap[s];
  for (int i = 2 * s + 1; i <= n; i = 2 * i + 1) {
    if (i < n && heap[i].second > heap[i + 1].second)
      i++;
    if (elem.second < heap[i].second)
      break;
    heap[s] = heap[i];
    s = i;
  }
  heap[s] = elem;
}

// 建小顶堆
void create_heap(std::vector<std::pair<int, int>>& heap)
{
  int n = heap.size() - 1;
  for (int s = (n - 1) / 2; s >= 0; s--) {
    adjust_heap(heap, s, n);
  }
}

std::vector<int> top_k_freq(const std::vector<int>& nums, int k)
{
  std::vector<std::pair<int, int>> pairs;
  std::unordered_map<int, int> hash;

  for (const auto & elem : nums) {
    hash[elem]++;
  }
  
  // assert(hash.size() >= k);

  for (const auto & elem : hash) {
    if (pairs.size() < (size_t)k) {
      pairs.push_back(elem);
      create_heap(pairs);
    } else {
      if (elem.second > pairs[0].second) {
        pairs[0] = elem;
        adjust_heap(pairs, 0, k - 1);
      }
    }
  }

  std::vector<int> res;
  for (auto elem : pairs) {
    res.push_back(elem.first);
  }

  return res;
}

class compression
{
public:
  bool operator()(const std::pair<int,int>& lhs, const std::pair<int,int>& rhs) {
    return lhs.second > rhs.second;
  }
};

// 也可以使用 std::priority_queue
std::vector<int> top_k_freq2(const std::vector<int>& nums, int k)
{
  std::vector<std::pair<int, int>> pairs;
  std::unordered_map<int, int> hash;

  for (const auto & elem : nums) {
    hash[elem]++;
  }

  std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, compression> prique;

  for (const auto & elem : hash) {
    prique.push(elem);
    if (prique.size() > (size_t)k) {
      prique.pop();
    }
  }

  std::vector<int> res;
  for (int i = k - 1; i >= 0; i--) {
    res.push_back(prique.top().first);
    prique.pop();
  }

  return res;
}


int main()
{
  {
    std::vector<int> res = top_k_freq({2,2,2,2,2,3,3,3,1}, 2);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
  }

  {
    std::vector<int> res = top_k_freq2({2,2,2,2,2,3,3,3,1}, 2);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
  }

  return 0;
}
