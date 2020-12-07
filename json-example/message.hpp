#ifndef message_hpp
#define message_hpp

#include <vector>
#include <string>

#include "rapidjson/document.h"

class DecompConfig;
class FWBufferConfig;

std::vector<DecompConfig> get_decomp_configs(rapidjson::Value &d);
std::vector<FWBufferConfig> get_fwb_configs(rapidjson::Value &d);

#endif
