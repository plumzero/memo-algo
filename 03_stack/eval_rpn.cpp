
// 150 逆波兰表达式求值
// 逆波兰表达式即后缀表达式

// 问题
// 给出逆波兰表达式，求得对应的值

// 示例一
// 输入 ["5", "2", "-", "4", "*"]
// 输出 12
// 解释 该算式转化为常见的中缀算术表达式为 ((5 - 2) × 4) = 12

// 为了简便，只定义 + - * / 四种运算，整型运算

#include <stack>
#include <string>
#include <vector>
#include <iostream>

int eval_rpn(const std::vector<std::string>& exprs) {
  std::stack<std::string> stack;

  for (size_t i = 0; i < exprs.size(); i++) {
    std::string s = exprs[i];
    if (s != "+" && s != "-" && s != "*" && s != "/") {
      stack.push(s);
    } else {
      int num1 = std::stoi(stack.top());
      stack.pop();
      int num2 = std::stoi(stack.top());
      stack.pop();
      int result;
      if (s == "+") result = num2 + num1;
      if (s == "-") result = num2 - num1;
      if (s == "*") result = num2 * num1;
      if (s == "/") result = num2 / num1;
      stack.push(std::to_string(result));
    }
  }

  return std::stoi(stack.top());
}

int main()
{
  {
    // ((5 - 2) × 4) = 12
    std::cout << eval_rpn({ "5", "2", "-", "4", "*" }) << std::endl;
  }

  {
    // 4 + 13 / 5
    std::cout << eval_rpn({ "4", "13", "5", "/", "+" }) << std::endl;
  }

  return 0;
}