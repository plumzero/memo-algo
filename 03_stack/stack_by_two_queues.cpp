
// 225 用队列实现栈

// 问题
// 使用队列(单向队列)实现栈的下列操作:
//  pop(): 弹出栈顶元素
//  push(x): 将 x 入栈
//  top(): 获取栈顶元素
//  empty(): 返回栈是否为空

// 分析
// 使用两个队列处理时，一个队列工作，一个队列备份。

#include <queue>
#include <iostream>

template<typename T>
class CStack
{
public:
  void push(T t);
  void pop();
  T top();
  bool empty();

private:
  std::queue<T> _work;
  std::queue<T> _back;
};

template<typename T>
void CStack<T>::push(T t)
{
  _work.push(t);
}

template<typename T>
void CStack<T>::pop()
{
  int count = _work.size();
  count--;
  while (count > 0) {
    _back.push(_work.front());
    _work.pop();
    count--;
  }

  _work.pop();

  _work = std::move(_back);
}

template<typename T>
T CStack<T>::top() {
  return _work.back();
}

template<typename T>
bool CStack<T>::empty()
{
  return _work.empty();
}

int main()
{
  CStack<char> stack;

  stack.push('a');
  stack.push('b');
  stack.push('c');

  std::cout << "top: " << stack.top() << std::endl;
  stack.pop();

  std::cout << "top: " << stack.top() << std::endl;
  stack.pop();

  stack.push('d');
  std::cout << "top: " << stack.top() << std::endl;
  stack.pop();

  return 0;
}