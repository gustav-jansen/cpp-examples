#ifndef message_hpp
#define message_hpp

#include <vector>
#include <string>

#include "rapidjson/document.h"

class DecompConfig;
class FWBufferConfig;
class ConductorConfig;
class EventBuilderConfig;

std::vector<DecompConfig> get_decomp_configs(rapidjson::Value &d);
std::vector<FWBufferConfig> get_fwb_configs(rapidjson::Value &d);
ConductorConfig get_conductor_config(rapidjson::Value &d);
EventBuilderConfig get_eb_config(rapidjson::Value &d);

#endif
