
// 541 反转字符串II

// 问题
// 分段反转字符串，在字符串中，从前向后遍历，每隔 2k 个字符的前 k 个字符需要反转，
// 如果剩下的字符小于 k 个，则反转剩下的所有字符
// 如果剩下的字符小于 2k 且大于或等于 k 个，则反转前 k 个字符

#include <string>
#include <iostream>

void reverse(std::string& str, int begin, int end)
{
  int low = begin;
  int high = end - 1;
  while (low < high) {
    char ch = str[low];
    str[low] = str[high];
    str[high] = ch;
    low++;
    high--; 
  }  
}

void section_reverse(std::string& str, int k)
{
  int i = 0;
  int flag = 0;
  int size = (int)str.size();
  for (i = 0; i < size; i += k) {
    if (flag % 2 == 0) {
      int j = (i + k > size ? size : i + k);
      reverse(str, i, j);
    }
    flag++;
  }
}

int main()
{
  {
    std::string str = "asdfghjkl";
    int k = 3;
    section_reverse(str, k);
    std::cout << str << std::endl;
  }

  {
    std::string str = "asdfghjk";
    int k = 3;
    section_reverse(str, k);
    std::cout << str << std::endl;
  }

  {
    std::string str = "asdfghjklw";
    int k = 3;
    section_reverse(str, k);
    std::cout << str << std::endl;
  }

  return 0;
}