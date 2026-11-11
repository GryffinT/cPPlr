#pragma once

#include <vector>
#include <optional>
#include <string>
#include <optional>

std::string getSong(std::optional<std::string> fileOfInterest, std::optional<std::string> subDir, std::string libPath);
bool download(const std::string& url, const std::string& outpath, std::string libPath);

