#include <stdlib.h>
#include <string>
#include <iostream>
void help() {
  std::string usage =
      "Usage\n\n"
      "libcall --help\n"
      "libcall [target] lib1 lib2 lib3 ... [options]\n\n"
      "example\n"
      "libcall main.cpp mod uftree -libpath ~/mylib -marker BEGINMYLIB\n\n";
  std::string options =
      "Options\n\n"
      "-L <path-to-mylib>\n"
      "-libpath <path-to-mylib> = Explicitly specify an original "
      "library directory.\n";

  std::cout << usage << options;
  exit(0);
  return;
}