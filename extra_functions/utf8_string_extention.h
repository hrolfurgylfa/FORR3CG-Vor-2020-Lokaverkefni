#include <string>

#ifndef UTF8_STRING_EXTENTION
#define UTF8_STRING_EXTENTION

bool is_continuation_byte(char stafur);
int has_continuation_bytes(char stafur);

int utf8_string_length(std::string string);
std::string utf8_string_index(std::string string, int index);

#endif