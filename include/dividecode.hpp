#pragma once
#include <iostream>
#include <filesystem>
#include <string>
std::string cut_string(std::string& S, int beg, int end);
int DivideCode(const std::filesystem ::path& p, std::string key = "#include");