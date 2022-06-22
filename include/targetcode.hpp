#pragma once
#include <string>
#include <filesystem>
#include <vector>

struct target {
  std::filesystem::path p;
  std::vector<std::string> formar, latter;
  target(std::filesystem::path P) : p(P) {}
};
