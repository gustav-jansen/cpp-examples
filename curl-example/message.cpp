#include <iostream>
#include "string.h"
#include <curl/curl.h>
#include "message.hpp"

static size_t WriteDataToString(void *data, size_t size, size_t nmemb, void *userp) {
  std::string *contents = (std::string*) userp;
  size_t fullsize = size*nmemb;

  contents->append( (char*) data, fullsize );
  return fullsize;
}

std::string get_message(std::string url) {
  CURL *session;
  std::string contents;

  session = curl_easy_init();

  if ( session ) {
    CURLcode res;
    char error_buffer[CURL_ERROR_SIZE];
    error_buffer [0] = 0;
    curl_easy_setopt(session, CURLOPT_URL, url.c_str());
    curl_easy_setopt(session, CURLOPT_WRITEFUNCTION, WriteDataToString);
    curl_easy_setopt(session, CURLOPT_WRITEDATA, &contents);

    curl_easy_setopt(session, CURLOPT_ERRORBUFFER, error_buffer);
    curl_easy_setopt(session, CURLOPT_VERBOSE, 1L);

    res = curl_easy_perform(session);
    if ( res != CURLE_OK) {
      std::cerr << "CURL error code: " << res << std::endl;
      std::cerr << "Error in CURL: ";
      if ( strlen(error_buffer) ) {
        std::cerr << error_buffer << std::endl;
      } else {
        std::cerr << curl_easy_strerror(res) << std::endl;
      }
    }

    curl_easy_cleanup(session);
  } else {
      std::cerr << "Error creating CURL session." << std::endl;
  }
  return contents;
}
