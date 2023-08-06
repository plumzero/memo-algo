
// 242 有效的字母异位词

// 问题
// 判断字符串 s 中的字符是否可以通过改变顺序的方式变成字符串 t(如果字符串 s 与字符串 t 相同，那么也是可以的)
// 字符串中只包含小写字母

#include <string>
#include <iostream>

bool is_anagram(std::string s, std::string t)
{
  int hash[26] = { 0 };
  
  for (size_t i = 0; i < s.size(); i++) {
    hash[s[i] - 'a']++;
  }
  
  for (size_t i = 0; i < t.size(); i++) {
    hash[t[i] - 'a']--;
  }

  for (size_t i = 0; i < sizeof(hash) / sizeof(int); i++) {
    if (hash[i] != 0) {
      return false;
    }
  }

  return true;
}

int main()
{
  {
    std::string s = "aee";
    std::string t = "eae";
    std::cout << std::boolalpha << is_anagram(s, t) << std::endl;
  }

  {
    std::string s = "asd";
    std::string t = "asd";
    std::cout << std::boolalpha << is_anagram(s, t) << std::endl;
  }

  {
    std::string s = "asd";
    std::string t = "afd";
    std::cout << std::boolalpha << is_anagram(s, t) << std::endl;
  }

  return 0;
}