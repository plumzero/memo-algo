
// 454 四数相加II

// 给出四个长度相同的数组，找出有几种元组可以使 A[i] + B[j] + C[k] + D[l] = 0

// 示例
// 输入 A=[3,1,4], B=[-2,4,3], C=[-1,3,2], D=[3,-2,0]
// 输出 2
// 两种元组如下:
// A[0] + B[0] + C[0] + D[2] = 0
// A[1] + B[0] + C[1] + D[1] = 0

// 分析
// 四个数组分成两组，对每组中的两个数组中的元素进行加和处理，得到所有可能的加和的集
// 接下来就转换为求两数之和

#include <vector>
#include <unordered_map>
#include <iostream>

int four_sum_count(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D, int target)
{
  std::unordered_map<int, int> hash;
  for (auto & a : A) {
    for (auto & b : B) {
      hash[a + b]++;
    }
  }

  int count = 0;
  for (auto & c : C) {
    for (auto & d : D) {
      count += hash[target - (c + d)];
    }
  }

  return count;
}


int main()
{
  {
    std::vector<int> a1 = { 3, 1, 4 };
    std::vector<int> a2 = { -2, 4, 3 };
    std::vector<int> a3 = { -1, 3, 2 };
    std::vector<int> a4 = { 3, -2, 0 };

    std::cout << four_sum_count(a1, a2, a3, a4, 0) << std::endl;
  }

  {
    std::vector<int> a1 = { 3, 1, 4 };
    std::vector<int> a2 = { -2, 4, 3 };
    std::vector<int> a3 = { -1, 3, 2 };
    std::vector<int> a4 = { 3, -2, 0 };

    std::cout << four_sum_count(a1, a2, a3, a4, 2) << std::endl;
  }

  return 0;
}
