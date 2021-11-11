#pragma once

#ifndef __cplusplus
 extern "C" {
char* toUpper(char* str);
char* toLower(char* str);
char* toUpperNew(char* str);
char* toLowerNew(char* str);
char** tokenize(const char* src, const char* pat);
void   tokenizeFree(chr **ptr) {
 }
#endif