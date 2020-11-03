#include <cstddef>
#include <iostream>
#include <queue>
#include "message.hpp"

void print_queue(std::priority_queue<Message>& q) {
  while(!q.empty()) {
    Message m = q.top();
    q.pop();
    std::cout << m.timestamp << std::endl;
  }
}

int main() {

  int data[] { 10, 20, 30 };
  int indices[] {4, 7, 1, 5, 2, 9, 34, 22, 57, 6, 12, 45};

  std::priority_queue<Message> q;
  for (int i : indices) {
    q.push(Message((std::byte*) data, i));
  }

  print_queue(q);
  return 0;
}
