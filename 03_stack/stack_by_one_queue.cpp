
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
    T t = _work.front();
    _work.pop();
    _work.push(t);
    count--;
  }

  _work.pop();
}

template<typename T>
T CStack<T>::top()
{
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
