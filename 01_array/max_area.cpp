
// 11 盛雨水最多的容器

// 问题
// 给定一个长度为 n 的整数数组 height，有 n 条重线，第 i 条线的两个端点是 (i,0) 和 (i,height[i])
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水
// 返回容器可以储存的最大水量

// 示例
// 输入 [1,8,6,2,5,4,8,3,7]
// 输出 49

#include <vector>
#include <iostream>
#include <algorithm>

int max_area(const std::vector<int>& height)
{
  int low = 0;
  int high = (int)height.size() - 1;
  int area = 0;

  while (low < high) {
    int x = (high - low) * std::min(height[low], height[high]);
    area = std::max(area, x);
    if (height[low] < height[high])
      low++;
    else
      high--;
  }

  return area;
}

int main()
{
  {
    std::vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    std::cout << max_area(height) << std::endl;
  }

  return 0;
}