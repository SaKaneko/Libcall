#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "config.hpp"
std::vector<std::string> split(const std::string& src, const char* delim);
bool read_config_txt(config& Cf);