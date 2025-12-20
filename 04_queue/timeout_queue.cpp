
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <iostream>

template <typename T>
class TimeoutQueue
{
private:
  std::vector<T> queue;
  size_t capacity{1024};
  size_t head{0};
  size_t tail{0};
  std::mutex mtx;
  std::condition_variable not_full;
  std::condition_variable not_empty;

  bool is_full() { return (tail + 1) % capacity == head; }
  bool is_empty() { return head == tail; }

public:
  TimeoutQueue(size_t cap) : capacity(cap) { queue.resize(cap); }
  bool Enqueue(const T& value, uint64_t timeout) {
    std::unique_lock<std::mutex> lock(mtx);

    bool success = not_full.wait_for(lock, std::chrono::milliseconds(timeout), [this]{ return !is_full(); });
    if (! success) {
      return false;
    }

    queue[tail] = value;
    tail = (tail + 1) % capacity;

    not_empty.notify_one();

    return true;
  }

  bool Dequeue(T& value, uint64_t timeout) {
    std::unique_lock<std::mutex> lock(mtx);

    bool success = not_empty.wait_for(lock, std::chrono::milliseconds(timeout), [this]{ return !is_empty(); });
    if (! success) {
      return false;
    }

    value = queue[head];
    head = (head + 1) % capacity;

    not_full.notify_one();

    return true;
  }

  void Print() {
    std::lock_guard<std::mutex> lock(mtx);
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
  TimeoutQueue<int> queue{4};
  queue.Print();
  
  queue.Enqueue(1, 1000);
  queue.Print();

  queue.Enqueue(2, 1000);
  queue.Print();

  queue.Enqueue(3, 1000);
  queue.Print();

  int x;
  queue.Dequeue(x, 1000);
  std::cout << x << "|";
  queue.Print();

  queue.Dequeue(x, 1000);
  std::cout << x << "|";
  queue.Print();

  queue.Dequeue(x, 1000);
  std::cout << x << "|";
  queue.Print();

  std::cout << std::endl;
  queue.Enqueue(11, 1000);
  queue.Enqueue(12, 1000);
  queue.Enqueue(13, 1000);
  queue.Print();

  return 0;
}