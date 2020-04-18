#include <iostream>
#include <string>

int utf8_string_length(std::string string) {
    int length = 0;
    unsigned char continuation_character_mask = 0b11000000;

    std::cout << "Continuation byte: " << 0b10000000 << "\n";
    for (int i = 0; i < string.length(); i++)
    {
        unsigned char byte_after_mask = string[i] & continuation_character_mask;
        std::cout << "Masked value: " << (int)byte_after_mask << "\n";
        if (byte_after_mask != 0b10000000) length++;
    }
    
    return length;
}

std::string utf8_string_index(std::string string, int index) {
    //TODO
}