#pragma once
#include <string.h>
#include <ctype.h>
#include <malloc.h>

#include "strings.h"

char* toUpper(char* str) {
		for (size_t i = 0; i < strlen(str); i++) str[i] = toupper(str[i]);
		return str;
}
char* toLower(char* str) {
		for (size_t i = 0; i < strlen(str); i++) str[i] = tolower(str[i]);
		return str;
}
char* toUpperNew(char* str) {
    size_t i;
    char *res = 0x0;;
    if (str != 0x0) {
        res = (char *) malloc(strlen(str) + 1);
	    for (i = 0; i < strlen(str); i++) res[i] = toupper(str[i]);
        res[i] = 0x0;
    }
	return res;
}
char* toLowerNew(char* str) {
    size_t i;
    char *res = 0x0;;
    if (str != 0x0) {
        res = (char *) malloc(strlen(str) + 1);
	    for (i = 0; i < strlen(str); i++) res[i] = tolower(str[i]);
        res[i] = 0x0;
    }
	return res;
}
char ** tokenize(char* src, const char* pat) {
    size_t i = 0;
    char **res; 
    string str(src);
	regex reg(pat);

	sregex_token_iterator iter(str.begin(), str.end(), reg, -1);
	sregex_token_iterator end;
	vector<char *> vec(iter, end);
    res = (char **) malloc((vec.size() + 1) * sizeof(char *));
    for (i = 0; i < vec.size(); i++) res[i] = strdup(vec[i]);
    *res[i] = 0x0;
    return res;
}

void tokenizeFree(char **ptr) {
   int i = 0;
   while(*ptr[i]) free(ptr[i++]);
   free(ptr);
}

