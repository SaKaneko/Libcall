#pragma once
#include <filesystem>
#include <string>
#include <map>
#include <vector>
const std::vector<std::string> config_vals = {"libpath", "targetcode", "marker",
                                              "config_txt_path"};

struct config {
  std::filesystem::path libpath;
  std::filesystem::path targetcode;
  std::string marker;
  std::filesystem::path config_txt_path;

  void init();
  config();
  bool path_valid(std::string in);
  bool edit_config(std::string val, std::string in);
  bool check_input(std::string val, std::string in);
  void show_config();
};