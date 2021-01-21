#include "TimestampedItem.hpp"

bool operator<(const TimestampedItem &it1, const TimestampedItem &it2) {
  return it1.timestamp > it2.timestamp;
}
