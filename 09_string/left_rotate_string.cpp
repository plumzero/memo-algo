
// 58 2 左旋转字符串

// 问题:
// 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 定义一个函数实现字符串的左旋转操作的功能。
// 比如，输入字符串 "abcdefg" 和数字 2，该函数将返回左旋转两位得到的结果 "cdefgab"

// 分析:
// 比如对于字符串 "abcdefg", 按照给定的数字 2 分成两个部分 "ab" 和 "cdefg"，将这两部分
// 分别左旋得到 "bagfedc"，之后对字符串整个旋转得到 "cdefgab"

#include <stdio.h>

void reverse(char* pb, char* pe)
{
  // assert(pb != nullptr && pe != nullptr);

  while (pb < pe) {
    char ch = *pb;
    *pb = *pe;
    *pe = ch;
    pb++;
    pe--;
  }
}

void left_rotate(char* str, int n)
{
  // assert(str != nullptr && n >= 0);

  int len = -1;
  while (str[++len]);

  if (n > len) {
    return ;
  }

  char* p1 = str;
  char* p2 = str + n - 1;
  char* p3 = str + n;
  char* p4 = str + len - 1;
  reverse(p1, p2);
  reverse(p3, p4);
  reverse(p1, p4);
}

int main()
{
  {
    char str[] = "abcdefg";
    left_rotate(str, 2);
    printf("%s\n", str);
  }

  {
    char str[] = "abcdefg";
    left_rotate(str, 0);
    printf("%s\n", str);
  }

  {
    char str[] = "abcdefg";
    left_rotate(str, 10);
    printf("%s\n", str);
  }

  return 0;
}
