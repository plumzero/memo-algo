
// 问题: 不占用额外的存储空间，将一个字符串就地逆置，并重新存放在原字符串中

// 要求: 使用递归

// 分析:
// 如果不使用递归，可以定义指向首字符和尾字符的两个指针，相向移动，将各指针所指向的字符调换。
// 假设字符串数组为 a[0...n-1], 将数组看作两个部分， a[0...n-2] 和 a[n-1]，将这两部分逆置，
// 之后将 a[0...n-2] 分为 a[0...n-3] 和 a[n-2]，再次逆置...
// 尝试了一下，感觉不可行

// 分析2:
// 字符的逆转和栈的出入很像，在每层的调用栈中设置一个临时变量，用来保存特定的字符，之后在递归
// 返回时将调用栈内的字符依次放入到原来的数组中

#include <stdio.h>

int reverse(char s[], int i)
{
    if (s[i] == '\0')
        return 0;
    
    char ch = s[i];

    int k = reverse(s, i + 1);
    s[k] = ch;

    return k + 1;
}

int main()
{
    char s[] = { "Hello World!" };
    reverse(s, 0);

    printf("%s\n", s);

    return 0;
}