#include <curl/curl.h>
#include <cstdio>
#include <string>
#include <iostream>

bool download(const std::string& url, const std::string& outpath, std::string libPath) {

  CURL* curl = curl_easy_init();
  if (!curl) return false;

  libPath.append(outpath);

  FILE* f = std::fopen(libPath.c_str(), "wb");
  if (!f) { curl_easy_cleanup(curl); return false; }

  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

  CURLcode rc = curl_easy_perform(curl);

  std::fclose(f);

  curl_easy_cleanup(curl);

  return rc == CURLE_OK;

}

/*
int main() {

  curl_global_init(CURL_GLOBAL_DEFAULT);
  download("https://example.com", "./mediaLib/out.html");
  curl_global_cleanup();

}
*/
