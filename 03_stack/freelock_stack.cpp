
#include <vector>
#include <atomic>
#include <iostream>

template <typename T>
class FreelockStack
{
private:
	std::vector<T> stack;
  size_t capacity{10};
	std::atomic<size_t> top{0};	// top 指向的是下一个可用位置，而不是栈顶元素的位置
public:
  FreelockStack(size_t cap) : capacity(cap) { stack.resize(cap); }
  bool Push(const T& value) {
    size_t old_top = top.load(std::memory_order_acquire);
    
    do {
      if (old_top >= capacity) {
        return false;
      }
      stack[old_top] = value;
    } while (!top.compare_exchange_weak(old_top, old_top + 1, std::memory_order_acq_rel, std::memory_order_relaxed));
    
    return true;
  }

  bool Pop(T& value) {
    size_t old_top = top.load(std::memory_order_acquire);
    
    do {
      if (old_top == 0) {
        return false;
      }
      value = stack[old_top - 1];
    } while (!top.compare_exchange_weak(old_top, old_top - 1, std::memory_order_acq_rel, std::memory_order_relaxed));
    
    return true;
  }

  void Print() {
    std::cout << std::boolalpha;
    std::cout << "top=" << top.load(std::memory_order_acquire);
    std::cout << ",size=" << stack.size();
    for (size_t i = 0; i < stack.size(); i++) {
        std::cout << "," << stack[i];
    }
    std::cout << std::endl;
  }
};

int main()
{
  FreelockStack<int> stack(2);
  stack.Print();
  
  stack.Push(1);
  stack.Print();

  stack.Push(2);
  stack.Print();

  stack.Push(3);
  stack.Print();

  int x;
  stack.Pop(x);
  std::cout << x << "|";
  stack.Print();

  stack.Pop(x);
  std::cout << x << "|";
  stack.Print();

  stack.Pop(x);
  std::cout << x << "|";
  stack.Print();

  std::cout << std::endl;
  stack.Push(11);
  stack.Push(12);
  stack.Push(13);
  stack.Print();

  return 0;
}