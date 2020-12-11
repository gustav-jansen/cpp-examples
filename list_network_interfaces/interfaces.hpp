#ifndef interfaces_hpp
#define interfaces_hpp

#include <string>
#include <vector>

class interface {
public:
  interface(std::string name, std::string ip) :
      name(name), ip(ip) {}
  std::string name;
  std::string ip;
};

std::vector<interface> get_network_interfaces(void);
#endif
