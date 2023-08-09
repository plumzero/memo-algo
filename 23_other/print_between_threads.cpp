

#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <iostream>

int main()
{

  std::mutex mtx;
  std::condition_variable cv;
  bool flag = false;

  std::thread([&](){
    while (true) {
      std::unique_lock<std::mutex> locker(mtx);
      cv.wait(locker, [&flag]()->bool { return !flag; });
      std::cout << "thread A" << std::endl;
      flag = !flag;
      cv.notify_one();
    }
  }).detach();

  std::thread([&](){
    while (true) {
      std::unique_lock<std::mutex> locker(mtx);
      cv.wait(locker, [&flag]()->bool { return flag; });
      std::cout << "thread B" << std::endl;
      flag = !flag;
      cv.notify_one();
    }
  }).detach();

  while (true) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  return 0;
}