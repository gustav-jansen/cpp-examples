#include "message.hpp"

bool Message::operator<(const Message& other) {
  return timestamp < other.timestamp;
}

bool operator<(const Message& m1, const Message& m2) {
  return m1.timestamp < m2.timestamp;
}
