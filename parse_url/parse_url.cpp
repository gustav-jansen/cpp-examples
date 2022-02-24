#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string url{"https://curl.se:8888/libcurl/c/curl_easy_setopt.html"};

  std::vector<std::string> tokens{"://", ":", "/"};
  std::string chopped = url;
  for (auto token: tokens) {
    std::size_t pos = chopped.find_first_of(token);
    std::cout << chopped.substr(0, pos) << std::endl;
    chopped = chopped.substr(pos+token.length());
  }
  std::cout << chopped << std::endl;

  return 0;
}
