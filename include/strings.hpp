#pragma once
#include <string>
#include <vector>
#ifdef __cplusplus
namespace jggtools {
char* toUpper(char* str);
char* toLower(char* str);
char* toUpperNew(char* str);
char* toLowerNew(char* str);

  std::vector<std::string> tokenize(std::string src, const char* pat);
  std::vector<char *>      tokenize(const char* src, const char* pat);
}
#endif