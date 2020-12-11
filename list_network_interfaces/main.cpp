#include <iostream>
#include "interfaces.hpp"

int main () {
  std::vector<interface> interfaces;

  interfaces = get_network_interfaces();
  for (auto &i: interfaces ) {
    std::cout << "Name: " << i.name << ", Address: " << i.ip << std::endl;
  }
}
