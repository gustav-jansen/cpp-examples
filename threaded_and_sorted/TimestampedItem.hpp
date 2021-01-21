#ifndef TimestampedItem_hpp
#define TimestampedItem_hpp

#include <cstddef>
#include <cstdint>
#include <vector>
#include <queue>

class TimestampedItem {
public:
  TimestampedItem(uint64_t timestamp, std::byte* payload) :
      timestamp(timestamp), payload(payload) {}
  uint64_t timestamp;
private:
  std::byte* payload;
};
bool operator<(const TimestampedItem& it1, const TimestampedItem& it2);
#endif
