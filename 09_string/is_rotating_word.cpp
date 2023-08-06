
// 对字符串的旋转操作描述如下: 例如对于 str = "123456"，它的所有旋转词为:
// "123456", "234561", "345612", "456123", "561234", "612345"
// 给定两个字符串 str1 和 str2, 实现判断 str1 是否是 str2 的旋转词 

#include <string>
#include <iostream>

// s 是原词
// t 是待判断旋转词
// 将两个 s 拼接到一起，那么 t 如果是 s 的旋转词，那么 t 一定是 ss 的子串
bool is_rotating_word(const std::string& s, const std::string& t)
{
  size_t slen = s.size();
  size_t tlen = t.size();

  if (slen != tlen) {
    return false;
  }

  std::string s2 = s + s;

  if (s2.find(t) != std::string::npos) {
    return true;
  }

  return false;
}

int main()
{
  std::cout << std::boolalpha << is_rotating_word("123456", "123456") << std::endl;
  std::cout << std::boolalpha << is_rotating_word("123456", "234561") << std::endl;
  std::cout << std::boolalpha << is_rotating_word("123456", "345612") << std::endl;
  std::cout << std::boolalpha << is_rotating_word("123456", "456123") << std::endl;
  std::cout << std::boolalpha << is_rotating_word("123456", "612345") << std::endl;
  std::cout << std::boolalpha << is_rotating_word("123456", "612354") << std::endl;

  return 0;
}