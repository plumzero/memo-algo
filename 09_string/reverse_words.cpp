
// 151 反转字符串里的单词

// 问题
// 给定一句英文，要求倒叙输出每一个单词，并删除单词两边冗余的空格(句子前面和后面没有空格，两个单词之间没有空格)
// 注意: 不可以使用额外的辅助空间，即原地修改字符串

// 示例一
// 输入: "I am a programmer"
// 输出: "programmer a am I"

// 示例二
// 输入: "hello world! "
// 输出: "world! hello"

// 本示例只考虑了翻转后头部有空格的情况，另外还有考虑尾部有空格的情况，中间有冗余空格(空格数量 > 1)的情况

#include <string>
#include <iostream>

void reverse(std::string& str, int low, int high)
{
  while (low < high) {
    char ch = str[low];
    str[low] = str[high];
    str[high] = ch;
    low++;
    high--; 
  }
}

void erase_extra_spaces(std::string& str)
{
  int fast, slow, len;
  fast = slow = 0;
  len = (int)str.size();

  // 头部空格
  while (fast < len && str[fast] == ' ') {
    fast++;
  }
  
  // 中间空格
  for (; fast < len; fast++) {
    if (fast - 1 > 0 && str[fast - 1] == str[fast] && str[fast] == ' ') {
      continue;
    } else {
      str[slow] = str[fast];
      slow++;
    }
  }
  
  // 尾部空格
  if (slow - 1 > 0 && str[slow - 1] == ' ') {
    str.resize(slow - 1);
  } else {
    str.resize(slow);
  }
}

void reverse_words(std::string& str)
{
  erase_extra_spaces(str);

  int len = (int)str.size();

  reverse(str, 0, len - 1);

  int i, j;
  i = j = 0;

  while (i != len) {
    if (str[i] == ' ') {
      i++;
      j++;
    } else if (str[j] == ' ' || j == len) {
      reverse(str, i, j - 1);
      i = j;
    } else {
      j++;
    }
  }
}

int main()
{
  {
    std::string str = "I am a programmer";
    reverse_words(str);
    std::cout << str << std::endl;
  }

  {
    std::string str = "hello world! ";
    reverse_words(str);
    std::cout << str << std::endl;
  }

  return 0;
}