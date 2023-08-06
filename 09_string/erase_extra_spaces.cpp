

// 删除空格

// 问题
// 给出一句英文，删除最前面的空格，最后面的空格，以及中间的冗余空格(使只有一个空格)
// 要求: 不使用额外的辅助空间，即原地修改字符串

// 示例一
// 输入: " I am a  programmer"
// 输出: "I am a programmer"

// 示例二
// 输入: " hello world! "
// 输出: "hello world!"

#include <string>
#include <iostream>

// 这段代码，要记下来!!!
void erase_extra_spaces(std::string& str)
{
  int slow = 0;
  int fast = 0;
  int len = (int)str.size();

  while (fast < len && str[fast] == ' ') {
    fast++;
  }

  for (; fast < len; fast++) {
    if (fast - 1 >= 0 && str[fast - 1] == str[fast] && str[fast] == ' ') {
      continue;
    } else {
      str[slow] = str[fast];
      slow++;
    }
  }

  if (slow - 1 > 0 && str[slow - 1] == ' ') {
    str.resize(slow - 1);
  } else {
    str.resize(slow);
  }

}

int main()
{
  {
    std::string str = " I am a  programmer";
    erase_extra_spaces(str);
    std::cout << str << std::endl;
  }

  {
    std::string str = " hello world! ";
    erase_extra_spaces(str);
    std::cout << str << std::endl;
  }

  return 0;
}