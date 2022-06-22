#pragma once
#include <iostream>
#include "targetcode.hpp"
#include "config.hpp"
bool dividetarget(target& T, config& Cf);
bool rewritetarget(target& T, config& Cf, std::vector<std::string>& heads,
                   std::vector<std::string>& libs);