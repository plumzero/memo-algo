
// 20 有效的括号

// 问题
// 一个字符串只要有左括号"("，就要有")"来闭合，"{" "}" "[" "]" 也同理。
// 字符串只包含以上字符，判断字符串是否合法。

#include <stack>
#include <string>
#include <iostream>

bool is_valid_bracket(std::string s)
{
  std::stack<char> stack;

  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      stack.push(s[i]);
    } else {
      if (stack.empty()) {
        return false;
      }
      char t = stack.top();
      if ((s[i] == ')' && t != '(') || (s[i] == ']' && t != '[') || (s[i] == '}' && t != '{')) {
        return false;
      }
      stack.pop();
    }
  }

  if (!stack.empty()) {
    return false;
  }

  return true;
}

int main()
{
  {
    std::string s = "()[{}]";
    std::cout << std::boolalpha << s << ": " << is_valid_bracket(s) << std::endl;
  }

  {
    std::string s = "()[{}]]";
    std::cout << std::boolalpha << s << ": " << is_valid_bracket(s) << std::endl;
  }

  {
    std::string s = "()[{}(";
    std::cout << std::boolalpha << s << ": " << is_valid_bracket(s) << std::endl;
  }

  {
    std::string s = "(){}[]{[]}";
    std::cout << std::boolalpha << s << ": " << is_valid_bracket(s) << std::endl;
  }

  {
    std::string s = "{[}(])";
    std::cout << std::boolalpha << s << ": " << is_valid_bracket(s) << std::endl;
  }

  return 0;
}