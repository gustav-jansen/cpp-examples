#include <iostream>
#include <string>
#include "message.hpp"

int main() {
  std::string contents, url;
  url = "https://curl.se/libcurl/c/curl_easy_setopt.html";

  contents = get_message(url);

  std::cout << "URL Content:\n" << contents;

  return 0;
}
