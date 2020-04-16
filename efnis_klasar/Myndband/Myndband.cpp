#include <iostream>
#include <string>
#include "Myndband.h"

Myndband::Myndband(){
    this->id = 0;
    this->titill = "";
    this->lengd = 0;
}
Myndband::Myndband(int id, std::string titill, int lengd){ 
    this->id = id;
    this->titill = titill;
    this->lengd = lengd;
}

int Myndband::get_lengd() { return this->lengd; }
void Myndband::set_lengd(int lengd) { this->lengd = lengd; }

void Myndband::print(){
    std::cout << ">>>> Myndband >>>>\n"
    << "ID: " << this->id << "\n"
    << "Titill: " << this->titill << "\n"
    << "Lengd: " << this->lengd << "\n";
}