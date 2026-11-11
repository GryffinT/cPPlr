#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include "database/database.hpp"
#include "player/player.hpp"

int main() {

  curl_global_init(CURL_GLOBAL_DEFAULT);

  const std::string libPath {"database/mediaLib/"};

  std::string url = "https://dn721800.ca.archive.org/0/items/Graduation-Kanye_West/05%20Good%20Life.mp3";
  std::string outpath = "Kanye.mp3";

  download(url, outpath, libPath);

  std::vector<std::string> playlist {"Kanye"};

  play(playlist, std::nullopt, libPath);

  curl_global_cleanup();

}
