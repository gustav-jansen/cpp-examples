#include "message.hpp"

#include "DecompConfig.hpp"
#include "FWBufferConfig.hpp"

DecompConfig get_decomp_config(rapidjson::Value &d) {
  DecompConfig config;

  assert(d.HasMember("APIPort"));
  assert(d["APIPort"].IsInt());
  config.apiport = d["APIPort"].GetInt();

  assert(d.HasMember("HostIP"));
  assert(d["HostIP"].IsString());
  config.hostip = d["HostIP"].GetString();

  assert(d.HasMember("Name"));
  assert(d["Name"].IsString());
  config.name = d["Name"].GetString();

  assert(d.HasMember("DataIP"));
  assert(d["DataIP"].IsString());
  config.dataip = d["DataIP"].GetString();

  assert(d.HasMember("BaseDataPort"));
  assert(d["BaseDataPort"].IsInt());
  config.basedataport = d["BaseDataPort"].GetInt();

  return config;
}
std::vector<DecompConfig> get_decomp_configs(rapidjson::Value &d) {
  std::vector<DecompConfig> configs;

  assert(d.IsArray());
  for (rapidjson::SizeType i = 0; i < d.Size(); i++) {
    configs.push_back(get_decomp_config(d[i]));
  }

  return configs;
}

FWBufferConfig get_fwb_config(rapidjson::Value &d) {
  FWBufferConfig config;

  assert(d.HasMember("Name"));
  assert(d["Name"].IsString());
  config.name = d["Name"].GetString();

  assert(d.HasMember("HostIP"));
  assert(d["HostIP"].IsString());
  config.hostip = d["HostIP"].GetString();

  assert(d.HasMember("APIPort"));
  assert(d["APIPort"].IsInt());
  config.apiport = d["APIPort"].GetInt();

  assert(d.HasMember("Capacity"));
  assert(d["Capacity"].IsInt());
  config.capacity = d["Capacity"].GetInt();

  assert(d.HasMember("DataIP"));
  assert(d["DataIP"].IsString());
  config.dataip = d["DataIP"].GetString();

  assert(d.HasMember("BaseDataPort"));
  assert(d["BaseDataPort"].IsInt());
  config.basedataport = d["BaseDataPort"].GetInt();

  assert(d.HasMember("BaseQueryPort"));
  assert(d["BaseQueryPort"].IsInt());
  config.basequeryport = d["BaseQueryPort"].GetInt();

  return config;
}
std::vector<FWBufferConfig> get_fwb_configs(rapidjson::Value &d) {
  std::vector<FWBufferConfig> configs;

  assert(d.IsArray());
  for (rapidjson::SizeType i = 0; i < d.Size(); i++) {
    configs.push_back(get_fwb_config(d[i]));
  }

  return configs;
}
