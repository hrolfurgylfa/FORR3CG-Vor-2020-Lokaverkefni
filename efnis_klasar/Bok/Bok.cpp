#include <iostream>
#include <string>
#include "Bok.h"

Bok::Bok(){
    this->id = 0;
    this->titill = "";
    this->hofundur = "";
}
Bok::Bok(int id, std::string titill, std::string hofundur){ 
    this->id = id;
    this->titill = titill;
    this->hofundur = hofundur;
}

std::string Bok::get_hofundur() { return this->hofundur; }
void Bok::set_hofundur(std::string hofundur) { this->hofundur = hofundur; }

void Bok::print(){
    std::cout << ">>>> Bók >>>>\n"
    << "ID: " << this->id << "\n"
    << "Titill: " << this->titill << "\n"
    << "Höfundur: " << this->hofundur << "\n";
}