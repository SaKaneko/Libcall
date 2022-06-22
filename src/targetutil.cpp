#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../include/targetutil.hpp"
std::string cut_string(std::string& S, int beg, int end) {
  std::string former, latter;
  former = S.substr(0, beg);
  latter = S.substr(end + 1);
  return former + latter;
}

bool dividetarget(target& T, config& Cf) {
  std::ifstream ifs(T.p);
  bool comment_outed    = false;
  int marker_line       = -1;
  int last_include_line = 0;
  int buf_size          = 256;
  char str[buf_size];
  if (ifs.fail()) {
    printf("[info] %s can not be opened.", Cf.config_txt_path.string().c_str());
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
    if (Str.find(Cf.marker) != -1) {
      marker_line = line;
    }
    if (Str.find("#include") != -1) {
      last_include_line = line;
    }
    line++;
  }

  int border = std::max(marker_line, last_include_line);
  std::ifstream ifs2(T.p);
  if (ifs2.fail()) {
    printf("[info] %s can not be opened.", Cf.config_txt_path.string().c_str());
    return false;
  }
  line = 0;
  while (ifs2.getline(str, buf_size)) {
    std::string Str = str;
    if (line <= border) {
      T.formar.push_back(Str);
    }
    else {
      T.latter.push_back(Str);
    }
    line++;
  }
  return true;
}
bool rewritetarget(target& T, config& Cf, std::vector<std::string>& heads,
                   std::vector<std::string>& libs) {

  return false;
}