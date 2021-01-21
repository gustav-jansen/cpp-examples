#ifndef ThreadedAndSortedTimestamps_hpp
#define ThreadedAndSortedTimestamps_hpp

#include <cstddef>
#include <cstdint>
#include <vector>
#include <mutex>

#include "TimestampedItem.hpp"

class ThreadedAndSortedTimestamps {
public:
  void insert(TimestampedItem item);
  std::vector<TimestampedItem> get_all(void);
private:
  std::priority_queue<TimestampedItem> q;
  std::mutex mtx;
};
#endif
