#ifndef message_hpp
#define message_hpp

#include <cstddef>

class Message {
  private:
    std::byte* bytes;

  public:
    int timestamp;
    Message() {
      bytes = nullptr;
      timestamp = 0;
    }

    Message(std::byte* msg, int t)
      : bytes(msg), timestamp(t) {}

    bool operator<(const Message& );
};
bool operator<(const Message& m1, const Message& m2);

struct CmpMsgTimestamp {
  bool operator()(const Message* m1, const Message* m2) {
    return m1->timestamp > m2->timestamp;
  }
};
#endif
