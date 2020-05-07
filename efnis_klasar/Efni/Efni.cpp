#include <iostream>
#include <string>

#include "../../extra_functions/utf8_string_extention.h"

#include "Efni.h"

Efni::Efni() {
    this->id = 0;
    this->titill = "";
}
Efni::Efni(int id, std::string titill) {
    this->id = id;
    this->titill = titill;
}
Efni::~Efni() {}

int Efni::get_id() { return this->id; }
void Efni::set_id(int id) { this->id = id; }
std::string Efni::get_titill() { return this->titill; }
void Efni::set_titill(std::string titill) { this->titill = titill; }

void Efni::print() {
    std::cout << ">>>> Efni >>>>\n"
    << "ID: " << this->id << "\n"
    << "Titill: " << this->titill << "\n";
}

std::string Efni::get_eight_letters() {
    std::cout << "!!!4\n";
    std::string return_string = "";
    for (int i = 0; i < 8; i++)
    {
        std::cout << this->id << "\n";
        std::cout << "!!!6\n";
        if (i < utf8_string_length(this->titill)){
            std::cout << "Checking string index at: " << i << "\n";
            return_string += utf8_string_index(this->titill, i);
        }
        else
            return_string += " ";
    }

    std::cout << "!!!5\n";
    return return_string;
}