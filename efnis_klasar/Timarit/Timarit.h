#include <string>

#include "../Efni/Efni.h"

#ifndef TIMARIT_H
#define TIMARIT_H

class Timarit : public Efni
{
private:
    int tolublad;
public:
    Timarit();
    Timarit(int id, std::string titill, int tolublad);

    int get_tolublad();
    void set_tolublad(int tolublad);

    void print();
};

#endif