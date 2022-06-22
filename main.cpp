#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include "include/help.hpp"
#include "include/config.hpp"
#include "include/read_config_txt.hpp"
#include "include/targetcode.hpp"
#include "include/targetutil.hpp"

using namespace std;
config Cf;

void read_config_txt_path(int& argc, std::vector<std::string>& argv) {
  for (int i = 1; i < argc - 1; i++) {
    if (argv[i] == "-C" || argv[i] == "-config_txt_path") {
      if (Cf.check_input(argv[i].substr(1), argv[i + 1])) {
        // printf("input_success\n");
        argv.erase(argv.begin() + i);
        argv.erase(argv.begin() + i);
        i--;
      }
      else {
        printf("[input error] error in config_txt_path %s , %s\n",
               argv[i].c_str(), argv[i + 1].c_str());
        help();
      }
    }
  }
}

void read_preargs(int& argc, std::vector<std::string>& argv) {
  if (argc <= 1 || argv[1] == "--help") {
    help();
  }
  if (argv[1].substr(argv[1].size() - 4) == ".cpp") {
    if (Cf.check_input("T", argv[1])) {
      argv.erase(argv.begin() + 1);
    }
    else {
      printf("[input error] We can't find %s\n", argv[1].c_str());
    }
  }
  else {
    printf("[input error] %s is not a cpp file\n", argv[1].c_str());
    help();
  }
  for (int i = 1; i < argc - 1; i++) {
    if (argv[i][0] == '-' && argv[i] != "--help") {
      if (Cf.check_input(argv[i].substr(1), argv[i + 1])) {
        // printf("input_success\n");
        argv.erase(argv.begin() + i);
        argv.erase(argv.begin() + i);
        i--;
      }
      else {
        printf("input_fail\n");
        help();
      }
    }
  }

  return;
}

void read_args(int& argc, std::vector<std::string>& argv) {

  return;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> Argv(argc);
  for (int i = 0; i < argc; i++) {
    Argv[i] = argv[i];
  }
  /*
  for (const auto& file :
       std::filesystem::directory_iterator(std::filesystem::absolute(".")))
  {
    cout << file.path().stem() << endl;
  }*/

  read_config_txt_path(argc, Argv);
  read_config_txt(Cf);
  read_preargs(argc, Argv);
  read_args(argc, Argv);
  Cf.show_config();
  target T(Cf.targetcode);
  dividetarget(T, Cf);
  printf("===========formar=============\n");
  for (const auto& i : T.formar) {
    cout << i << endl;
  }
  printf("===========latter=============\n");
  for (const auto& i : T.latter) {
    cout << i << endl;
  }

  for (const auto& i : Argv) {
    cout << i << endl;
  }
  return 0;
}