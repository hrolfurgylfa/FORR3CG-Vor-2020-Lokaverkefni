#include <iostream>
#include <string>
#include "Efni.h"

Efni::Efni() {
    this->id = 0;
    this->titill = "";
}
Efni::Efni(int id, std::string titill) {
    this->id = id;
    this->titill = titill;
}

int Efni::get_id() { return this->id; }
void Efni::set_id(int id) { this->id = id; }
std::string Efni::get_titill() { return this->titill; }
void Efni::set_titill(std::string titill) { this->titill = titill; }

void Efni::print() {
    std::cout << ">>>> Efni >>>>\n"
    << "ID: " << this->id << "\n"
    << "Titill: " << this->titill << "\n";
}