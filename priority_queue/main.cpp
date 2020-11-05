#include <cstddef>
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include "message.hpp"

int data[] { 10, 20, 30 };
std::vector<Message*> messages[10];

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

std::mutex mtx;
std::priority_queue<Message*, std::vector<Message*>, CmpMsgTimestamp> q3;
void add_to_queue(int i) {
  std::cout << "I am thread #" << i << std::endl;
  int indices[] {4, 7, 1, 5, 2, 9, 3, 8, 6, 0};
  for (int idx : indices) {
    messages[i].push_back(new Message((std::byte*) data, 10*(9-i)+idx));
  }
  for (Message* m: messages[i]) {
    mtx.lock();
    q3.push(m);
    mtx.unlock();
  }
}
int main() {

  std::cout << "Priority queue: std::priority_queue<Message>\n";
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

  std::thread threads[10];
  for ( int i=0; i<10;i++ )
    threads[i] = std::thread(add_to_queue, i);

  for (auto& th : threads) th.join();

  std::cout << "Priority queue: std::priority_queue<Message*> - threaded\n";
  print_queue_of_ptr(q3);
  return 0;
}
