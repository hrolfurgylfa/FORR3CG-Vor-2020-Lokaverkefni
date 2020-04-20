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
    std::string return_string = "";
    std::cout << "Length: " << this->titill.length() << "\n";
    for (int i = 0; i < 8; i++)
    {
        if (i < utf8_string_length(this->titill)) {
            return_string += utf8_string_index(this->titill, i);
            std::cout << "i: " << utf8_string_index(this->titill, i) << "\n";
        }
        else {
            return_string += " ";
            std::cout << "i: " << "space" << "\n";
        }
    }

    return return_string;
}