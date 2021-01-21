#include "ThreadedAndSortedTimestamps.hpp"

void ThreadedAndSortedTimestamps::insert(TimestampedItem item) {
  mtx.lock();
  q.push(item);
  mtx.unlock();

}

std::vector<TimestampedItem> ThreadedAndSortedTimestamps::get_all(void) {
  std::vector<TimestampedItem> vec;
  mtx.lock();
  while (!q.empty()) {
    vec.push_back(q.top());
    q.pop();
  }
  mtx.unlock();
  return vec;
}
