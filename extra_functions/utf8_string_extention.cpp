#include <iostream>
#include <string>

bool is_continuation_byte(char stafur) {
    if (((unsigned char)stafur & 0b11000000) == 0b10000000) return true;
    else return false;
}

int has_continuation_bytes(char stafur) {
    /*
        This function returns the number of continuation bytes if it has any. 
        Otherwise if it has non it returs 0 and if it is a continuation byte
        it returns -1.
    */

    // 0 Aukastafir samkvæmt UTF-8 standartinum, ég fylgdi töflu á wikipedia
    // til þessað setja þetta upp: https://en.wikipedia.org/wiki/UTF-8#Description
    if (((unsigned char)stafur & 0b10000000) == 0b00000000) return 0;
    // 1 Aukastafur samkvæmt UTF-8 standartinum
    else if (((unsigned char)stafur & 0b11100000) == 0b11000000) return 1;
    // 2 Aukastafir samkvæmt UTF-8 standartinum
    else if (((unsigned char)stafur & 0b11110000) == 0b11100000) return 2;
    // 3 Aukastafir samkvæmt UTF-8 standartinum
    else if (((unsigned char)stafur & 0b11111000) == 0b11110000) return 3;
    // Ef ekkert af þessu passaði hlýtur stafurinn að vera continuation byte
    else return -1;
}

int utf8_string_length(std::string string) {
    int length = 0;
    for (int i = 0; i < string.length(); i++){
        if (!is_continuation_byte(string[i])) length++;
    }
    
    return length;
}

std::string utf8_string_index(std::string string, int index) {
    std::string stafur = "";
    int string_index = 0;

    for (int i = 0; i < string.length(); i++)
    {
        if (is_continuation_byte(string[i])) continue;
        
        if (string_index == index)
        {
            stafur += string[i];
            for (int i2 = 1; i2 < has_continuation_bytes(string[i])+1; i2++)
                stafur += string[i+i2];
            break;
        }

        string_index++;
    }

    return stafur;
}