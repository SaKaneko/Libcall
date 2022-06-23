#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../include/targetutil.hpp"
#include "../include/dividecode.hpp"

bool dividetarget(target& T, config& Cf) {
  int border = std::max(DivideCode(T.p), DivideCode(T.p, Cf.marker));
  std::ifstream ifs2(T.p);
  int buf_size = 256;
  char str[buf_size];
  int line = 0;
  if (ifs2.fail()) {
    printf("[info] %s can not be opened.", Cf.config_txt_path.string().c_str());
    return false;
  }
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