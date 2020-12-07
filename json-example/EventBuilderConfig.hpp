#ifndef EventBuilderConfig_hpp
#define EventBuilderConfig_hpp

#include <string>

class EventBuilderConfig {
public:
  int apiport;
  std::string hostip;
  std::string name;
  std::string dataip;
  int dataport;
  int headertimeout;
  int datatimeout;
};

#endif
