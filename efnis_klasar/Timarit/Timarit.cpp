#include <iostream>
#include <string>
#include "Timarit.h"

Timarit::Timarit(){
    this->id = 0;
    this->titill = "";
    this->tolublad = 0;
}
Timarit::Timarit(int id, std::string titill, int tolublad){ 
    this->id = id;
    this->titill = titill;
    this->tolublad = tolublad;
}

int Timarit::get_tolublad() { return this->tolublad; }
void Timarit::set_tolublad(int tolublad) { this->tolublad = tolublad; }

void Timarit::print(){
    std::cout << ">>>> Tímarit >>>>\n"
    << "ID: " << this->id << "\n"
    << "Titill: " << this->titill << "\n"
    << "Tölublað: " << this->tolublad << "\n";
}