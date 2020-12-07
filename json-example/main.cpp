#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"

#include "message.hpp"
#include "DecompConfig.hpp"
#include "FWBufferConfig.hpp"
#include "ConductorConfig.hpp"
#include "EventBuilderConfig.hpp"

std::string read_file(std::string filename) {
  std::ifstream fh(filename);
  std::string json;

  fh.seekg(0, std::ios::end);
  json.resize(fh.tellg());
  fh.seekg(0, std::ios::beg);
  fh.read(&json[0], json.size());
  fh.close();

  return json;
}

int main() {
  rapidjson::Document d;
  std::string json = read_file("example.json");

  d.Parse(json.c_str());

  assert(d.HasMember("Decomps"));
  std::vector<DecompConfig> decomp_configs = get_decomp_configs(d["Decomps"]);

  assert(d.HasMember("FWBuffers"));
  std::vector<FWBufferConfig> fwb_configs = get_fwb_configs(d["FWBuffers"]);

  assert(d.HasMember("Conductor"));
  ConductorConfig conductor_config = get_conductor_config(d["Conductor"]);

  assert(d.HasMember("EventBuilder"));
  EventBuilderConfig eb_config = get_eb_config(d["EventBuilder"]);

  for ( auto &config : decomp_configs) {
    std::cout << "APIPort: " << config.apiport << std::endl;
    std::cout << "HostIP: " << config.hostip << std::endl;
    std::cout << "Name: " << config.name << std::endl;
    std::cout << "DataIP: " << config.dataip << std::endl;
    std::cout << "BaseDataPort: " << config.basedataport << std::endl << std::endl;
  }

  for ( auto &config : fwb_configs) {
    std::cout << "Name: " << config.name << std::endl;
    std::cout << "HostIP: " << config.hostip << std::endl;
    std::cout << "APIPort: " << config.apiport << std::endl;
    std::cout << "Capacity: " << config.capacity << std::endl;
    std::cout << "DataIP: " << config.dataip << std::endl;
    std::cout << "BaseDataPort: " << config.basedataport << std::endl;
    std::cout << "BaseQueryPort: " << config.basequeryport << std::endl << std::endl;
  }
  std::cout << "Host: " << conductor_config.host << std::endl;
  std::cout << "Port: " << conductor_config.port << std::endl << std::endl;

    std::cout << "APIPort: " << eb_config.apiport << std::endl;
    std::cout << "HostIP: " << eb_config.hostip << std::endl;
    std::cout << "Name: " << eb_config.name << std::endl;
    std::cout << "DataIP: " << eb_config.dataip << std::endl;
    std::cout << "DataPort: " << eb_config.dataport << std::endl;
    std::cout << "HeaderTimeout: " << eb_config.headertimeout << std::endl;
    std::cout << "DataTimeout: " << eb_config.datatimeout << std::endl << std::endl;
}
