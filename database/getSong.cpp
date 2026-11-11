#include <filesystem>
#include <iostream>
#include <string>
#include <optional>
#include <vector>

std::string getSong(std::optional<std::string> fileOfInterest, std::optional<std::string> subDir, std::string libPath ) {

  std::filesystem::path baseDir {libPath};

  const std::filesystem::path dir { subDir ? baseDir / *subDir : baseDir };
  
  bool success {false};
    
  if ( !(std::filesystem::exists(dir) && std::filesystem::is_directory(dir)) ) {
 
    std::cout << "Dir is either not a directory or does not exist." << "\n";
    return "";

  }

  if (std::filesystem::is_empty(dir)) {

    std::cout << "Dir contains no files." << "\n";
    return "";

  }
  

  for ( const auto& entry : std::filesystem::recursive_directory_iterator(dir) ) {

    if ( !( entry.path().extension() == ".mp3") ) continue;

    if ( fileOfInterest ) {

      if (entry.path().filename() != *fileOfInterest ) continue;
      std::cout << "FOI found: " << entry.path() << "\n";
      success = true;
      return entry.path();

    }

    if (!fileOfInterest) std::cout << "Entry found: " << entry.path() << "\n";

  }

  if ( fileOfInterest && !success ) std::cout << "FOI not found: \"" << fileOfInterest.value() << "\"\n"; 

  return 0;

}
/*
int main() {

  std::vector<std::string> list {"trueSong", "audTest", "test", "jazzSong"};

  play(list, "jazz");

  return 0;

}
*/
