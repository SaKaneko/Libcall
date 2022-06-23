#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>
#include "../include/dividecode.hpp"
std::string cut_string(std::string& S, int beg, int end) {
  std::string former, latter;
  former = S.substr(0, beg);
  latter = S.substr(end + 1);
  return former + latter;
}

int DivideCode(const std::filesystem ::path& p, std::string key) {
  std::cout << key << std::endl;
  std::ifstream ifs(p);
  bool comment_outed = false;
  int border         = 0;
  int buf_size       = 256;
  char str[buf_size];
  if (ifs.fail()) {
    printf("[info] %s can not be opened.", p.string().c_str());
    return false;
  }
  int line = 0;
  while (ifs.getline(str, buf_size)) {
    std::string Str       = str;
    int comment_out_start = 0;
    // check /**/ comment out
    while (1) {
      if (comment_outed) {
        if (Str.find("*/") != -1) {
          comment_outed = false;
          Str = cut_string(Str, comment_out_start, Str.find("*/") + 1);
        }
        else {
          Str = cut_string(Str, comment_out_start, Str.size() - 1);
          break;
        }
      }
      else {
        if (Str.find("/*") != -1) {
          comment_outed     = true;
          comment_out_start = Str.find("/*");
        }
        else {
          break;
        }
      }
    }
    // check // comment out
    if (Str.find("//") != 1) {
      Str = Str.substr(0, Str.find("//"));
    }
    // check "" arguments
    bool strings = false;
    while (1) {
      if (strings) {
        if (Str.substr(comment_out_start + 1).find("\"") == -1) {
          printf("[error] cpp file has invalid argument\n");
          return false;
        }
        else {
          Str =
              cut_string(Str, comment_out_start,
                         comment_out_start +
                             Str.substr(comment_out_start + 1).find("\"") + 1);
          strings = false;
        }
      }
      else {
        if (Str.find("\"") != -1) {
          strings           = true;
          comment_out_start = Str.find("\"");
        }
        else {
          break;
        }
      }
    }
    if (Str.find(key) != -1) {
      border = line;
    }
    line++;
  }
  return border;
}