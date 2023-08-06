
// 344 反转字符串

// 问题
// 将一个字符串反转

#include <string>
#include <iostream>

void reverse(std::string& str)
{
  int low = 0, high = str.size() - 1;

  while (low < high) {
    auto ch = str[low];
    str[low] = str[high];
    str[high] = ch;
    low++;
    high--; 
  }
}

int main()
{
  std::string str = "hello";

  reverse(str);

  std::cout << str << std::endl;

  return 0;
}