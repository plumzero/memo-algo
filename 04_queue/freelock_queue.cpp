
#include <atomic>
#include <vector>
#include <iostream>

// 实现上可能还是有点问题
template <typename T>
class FreelockQueue
{
private:
  std::vector<T> queue;
  size_t capacity;
  std::atomic<size_t> head{0};
  std::atomic<size_t> tail{0};

  bool is_full() { return (tail + 1) % capacity == head; } // for debug
  bool is_empty() { return head == tail; } // for debug

public:
  FreelockQueue(size_t cap) : capacity(cap) { queue.resize(cap); }
  bool Enqueue(const T& value)
  {
    size_t new_tail = 0;
    size_t old_tail = tail.load(std::memory_order_acquire);
    do {
      new_tail = (old_tail + 1) % capacity;
      if (new_tail == head.load(std::memory_order_acquire)) {
        return false;
      }
      queue[old_tail] = value;
    } while (!tail.compare_exchange_weak(old_tail, new_tail, std::memory_order_acq_rel, std::memory_order_release));

    return true;
  }
  bool Dequeue(T& value)
  {
    size_t new_head = 0;
    size_t old_head = head.load(std::memory_order_acquire);
    do {
      if (old_head == tail.load(std::memory_order_acquire)) {
        return false;
      }
      value = queue[old_head];
      new_head = (old_head + 1) % capacity;
    } while (!head.compare_exchange_weak(old_head, new_head, std::memory_order_acq_rel, std::memory_order_release));
    
    return true;
  }

  void Print() {
    std::cout << std::boolalpha;
    std::cout << "cap=" << capacity;
    std::cout << ",size=" << (tail + capacity - head) % capacity;
    std::cout << ",head=" << head;
    std::cout << ",tail=" << tail;
    std::cout << ",empty=" << is_empty();
    std::cout << ",full=" << is_full();
    for (size_t i = head; i != tail; i = (i + 1) % capacity) {
        std::cout << "," << queue[i];
    }
    std::cout << std::endl;
  }
};

int main()
{
  FreelockQueue<int> queue{4};
  queue.Print();
  
  queue.Enqueue(1);
  queue.Print();

  queue.Enqueue(2);
  queue.Print();

  queue.Enqueue(3);
  queue.Print();

  int x;
  queue.Dequeue(x);
  std::cout << x << "|";
  queue.Print();

  queue.Dequeue(x);
  std::cout << x << "|";
  queue.Print();

  queue.Dequeue(x);
  std::cout << x << "|";
  queue.Print();

  std::cout << std::endl;
  queue.Enqueue(11);
  queue.Enqueue(12);
  queue.Enqueue(13);
  queue.Print();

  return 0;
}