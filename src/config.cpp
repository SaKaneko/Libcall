#include <filesystem>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "../include/config.hpp"

void config::init() {
  libpath         = "~";
  targetcode      = "~";
  marker          = "BEGINMYLIB";
  config_txt_path = "~/libcall_config.txt";
}

config::config() {
  config::init();
}

bool config::path_valid(std::string in) {
  std::filesystem::path p = in;
  return std::filesystem::exists(p);
}

bool config::edit_config(std::string val, std::string in) {
  if (val == config_vals[0]) {
    if (path_valid(in)) {
      libpath = std::filesystem::absolute(in);
      return true;
    }
  }
  else if (val == config_vals[1]) {
    if (path_valid(in)) {
      targetcode = std::filesystem::absolute(in);
      return true;
    }
  }
  else if (val == config_vals[2]) {
    marker = in;
    return true;
  }
  else if (val == config_vals[3]) {
    if (path_valid(in)) {
      config_txt_path = std::filesystem::absolute(in);
      return true;
    }
  }
  else {
    printf("There is no such a config paramater abort.\n");
    exit(1);
    return false;
  }
  return false;
}

bool config::check_input(std::string val, std::string in) {
  std::vector<std::vector<std::string>> Expressions = {{config_vals[0], "L"},
                                                       {config_vals[1], "T"},
                                                       {config_vals[2], "M"},
                                                       {config_vals[3], "C"}};

  for (int i = 0; i < config_vals.size(); i++) {
    for (int j = 0; j < Expressions[i].size(); j++) {
      if (val == Expressions[i][j]) {
        return edit_config(Expressions[i][0], in);
      }
    }
  }
  return false;
}

void config::show_config() {
  std::cout << config_vals[0] << " " << libpath << std::endl;
  std::cout << config_vals[1] << " " << targetcode << std::endl;
  std::cout << config_vals[2] << " " << marker << std::endl;
  std::cout << config_vals[3] << " " << config_txt_path << std::endl;
}