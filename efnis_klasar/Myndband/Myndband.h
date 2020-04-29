#include <string>

#include "../Efni/Efni.h"

#ifndef MYNDBAND_H
#define MYNDBAND_H

class Myndband : public Efni
{
private:
    int lengd;
public:
    Myndband();
    Myndband(int id, std::string titill, int lengd);

    int get_lengd();
    void set_lengd(int lengd);

    void print();
};

#endif