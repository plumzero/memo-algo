
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
    auto ch = str[low];
    str[low] = str[high];
    str[high] = ch;
    low++;
    high--; 
  }
}

void reverse_words(std::string& str)
{
  reverse(str, 0, (int)str.size() - 1);

  int i, j;
  int step = 0;

  i = 0;
  // 头部空格情况
  while (str[i] == ' ') {
    i++;
    step = 1;
  }
  j = i;

  while (j != (int)str.size()) {
    if (str[i] == ' ') {
      i++;
      j++;
    } else if (str[j] != ' ') {
      j++;
    } else {
      reverse(str, i, j - 1);
      i = j;
    }
  }

  if (step > 0) {
    int len = str.size() - step;
    for (int i = 0; i < len; i++) {
      str[i] = str[i + step];
    }
    str.erase(len);
  }

  // 翻转后尾部空格的处理...略
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