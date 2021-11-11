#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <string>
#include <vector>
#include <regex>

#include "strings.hpp"


using namespace std;

namespace jggtools {
// From http ://www.olivierlanglois.net/idioms_for_using_cpp_in_c_programs.html
	// Variant #1
	char* myStrdup(const char* s, int size) {
		++size;
		char* res = static_cast<char*>(malloc(size));
		if (!res) throw runtime_error("No memory");
		memcpy(res, s, size);
		 return res;
	}

	// Variant #2
	char* myStrdup(const char* s) {
		return myStrdup(s, (int) strlen(s));
	}
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
//#ifdef __cplusplus
vector<string> tokenize(string src, const char* pat) {
	regex reg(pat);

	sregex_token_iterator iter(src.begin(), src.end(), reg, -1);
	sregex_token_iterator end;
	vector<string> vec(iter, end);
	return vec;
}
vector<char *> tokenize(const char* src, const char* pat) {
    vector<string> wrk = tokenize(string(src), pat);
    vector<char *> res(wrk.size());
    for (size_t i  = 0 ; i < wrk.size(); i++) res[i] = (char *) wrk[i].c_str();
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
// #endif
}
