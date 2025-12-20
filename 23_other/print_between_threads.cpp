
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

class ThreadPrint
{
private:
  int max{10};
  int count{1};
  bool flag{false};
  bool done{false};
  std::condition_variable cv;
  std::mutex mtx;
public:
  ThreadPrint(int max) : max(max) {}
  void PrintOdd()
  {
    while (true) {
      std::unique_lock<std::mutex> lock(mtx);
      cv.wait(lock, [&]{ return !flag || done; });
      if (count > max) {
        done = true;
        cv.notify_one(); // !!!这里不要忘记通知
        break;
      }
      std::cout << "odd: " << count << std::endl;
      count++;
      flag = !flag;
      cv.notify_one();
    }
    // std::cout << "debug odd" << std::endl;
  }
  void PrintEven()
  {
    while (true) {
      std::unique_lock<std::mutex> lock(mtx);
      cv.wait(lock, [&]{ return flag || done; });
      if (count > max) {
        done = true;
        cv.notify_one(); // !!!这里不要忘记通知
        break;
      }
      std::cout << "even: " << count << std::endl;
      count++;
      flag = !flag;
      cv.notify_one();
    }
    // std::cout << "debug even" << std::endl;
  }
};

int main()
{
  ThreadPrint obj(10);

  std::thread odd([&]{obj.PrintOdd();});
  std::thread even([&]{obj.PrintEven();});

  odd.join();
  even.join();

  return 0;
}