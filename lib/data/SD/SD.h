#pragma once
#include <string>

class OnboardSD {
  public:
    static void init();
    static void write(const std::string& filename, const std::string& data);
    static std::string read(const std::string& filename);
};