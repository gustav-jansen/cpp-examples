#ifndef FWBufferConfig_hpp
#define FWBufferConfig_hpp

#include <string>

class FWBufferConfig {
public:
  std::string name;
  std::string hostip;
  int apiport;
  int capacity;
  std::string dataip;
  int basedataport;
  int basequeryport;
};

#endif
