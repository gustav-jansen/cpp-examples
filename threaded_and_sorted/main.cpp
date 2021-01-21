#include <iostream>
#include <vector>
#include <thread>
#include "ThreadedAndSortedTimestamps.hpp"

#define NUMBER_OF_THREADS 10
void add_to_queue(ThreadedAndSortedTimestamps *q, int i) {
  int indices[] {4, 7, 1, 5, 2, 9, 3, 8, 6, 0};
  for (int idx : indices) {
    q->insert(TimestampedItem((uint64_t) NUMBER_OF_THREADS*(NUMBER_OF_THREADS-1-i)+idx, (std::byte *) nullptr));
  }
}

int main() {
  ThreadedAndSortedTimestamps q;
  std::thread threads[NUMBER_OF_THREADS];
  for (int i=0; i<NUMBER_OF_THREADS; i++) {
    threads[i] = std::thread(add_to_queue, &q, i);
  }

  for (auto& th : threads) th.join();

  std::vector<TimestampedItem> vec = q.get_all();

  for (auto &it: vec) {
    std::cout << "Timestamp after sort: " << it.timestamp << std::endl;
  }
  return 0;
}

