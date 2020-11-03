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

void print_queue_of_ptr(std::priority_queue<Message*, std::vector<Message*>, CmpMsgTimestamp>& q) {
  while(!q.empty()) {
    Message* m = q.top();
    q.pop();
    std::cout << m->timestamp << std::endl;
  }
}

int main() {

  std::cout << "Priority queue: std::priority_queue<Message>\n";
  int data[] { 10, 20, 30 };
  int indices[] {4, 7, 1, 5, 2, 9, 34, 22, 57, 6, 12, 45};

  std::priority_queue<Message> q;
  for (int i : indices) {
    q.push(Message((std::byte*) data, i));
  }

  print_queue(q);


  std::cout << "Priority queue: std::priority_queue<Message*>\n";
  std::vector<Message*> msgs;
  for (int i : indices) {
    msgs.push_back(new Message((std::byte*) data, i));
  }

  std::priority_queue<Message*, std::vector<Message*>, CmpMsgTimestamp> q2;
  for (Message* m: msgs) {
    q2.push(m);
  }
  print_queue_of_ptr(q2);

  return 0;
}
