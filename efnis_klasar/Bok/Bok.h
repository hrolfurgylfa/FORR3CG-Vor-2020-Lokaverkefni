#include <string>

#include "../Efni/Efni.h"

#ifndef BOK_H
#define BOK_H

class Bok : public Efni
{
private:
    std::string hofundur;
public:
    Bok();
    Bok(int id, std::string titill, std::string hofundur);

    std::string get_hofundur();
    void set_hofundur(std::string hofundur);

    void print();
};

#endif