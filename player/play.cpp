
#define MINIAUDIO_IMPLEMENTATION

#include "miniaudio.h"
#include "../database/database.hpp"
#include <vector>
#include <optional>
#include <string>
#include <iostream>

int play(const std::vector<std::string>& playlist, std::optional<std::string> subDir, std::string libPath) {

  for ( const std::string& song : playlist ) {

    const auto track = getSong(song + ".mp3", subDir, libPath);

    std::cout << track << "\n";

    ma_engine engine;
    ma_result res = ma_engine_init(NULL, &engine);
    if ( res != MA_SUCCESS ) {
      std::cout << ma_result_description(res) << "\n";
    }
    
    res = ma_engine_play_sound(&engine, track.c_str(), NULL);
    if ( res != MA_SUCCESS ) {
      std::cout << ma_result_description(res) << "\n";
    }

    std::cin.get();

    ma_engine_uninit(&engine);

  }

  return 0;

}
