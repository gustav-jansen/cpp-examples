#include <string>
#include <fstream>

 std::string read_file(std::string filename) {
  std::ifstream fh(filename);
  std::string result;

  fh.seekg(0, std::ios::end);
  result.resize(fh.tellg());
  fh.seekg(0, std::ios::beg);
  fh.read(&result[0], result.size());
  fh.close();

  return result;
}

