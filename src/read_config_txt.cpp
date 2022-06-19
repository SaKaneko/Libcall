#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "../include/config.hpp"
#include "../include/read_config_txt.hpp"

std::vector<std::string> split(const std::string& src, const char* delim) {
  std::vector<std::string> vec;
  std::string::size_type len = src.length();

  for (std::string::size_type i = 0, n; i < len; i = n + 1) {
    n = src.find_first_of(delim, i);
    if (n == std::string::npos) {
      n = len;
    }
    vec.push_back(src.substr(i, n - i));
  }

  return vec;
}

bool read_config_txt(config& Cf) {
  if (std::filesystem::exists(std::filesystem::absolute(Cf.config_txt_path))) {
    std::ifstream ifs(Cf.config_txt_path.string());

    int buf_size = 81;

    char str[buf_size];
    if (ifs.fail()) {
      printf("[info] %s can not be opened.",
             Cf.config_txt_path.string().c_str());
    }
    while (ifs.getline(str, buf_size)) {
      std::string Str              = str;
      std::vector<std::string> ret = split(Str, " ");
      if (ret.size() == 3 && ret[1] == "=") {
        printf("[info] import paramater %s , %s \n", ret[0].c_str(),
               ret[2].c_str());
        Cf.check_input(ret[0], ret[2]);
      }
      else {
        printf("[info] invalid format in libcall_config.txt \n valiable = "
               "value\n");
      }
    }
  }
  else {
    printf("[info] %s not exist.\n",
           std::filesystem::absolute(Cf.config_txt_path).string().c_str());
  }
}