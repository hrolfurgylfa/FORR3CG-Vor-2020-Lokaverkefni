#include "../efnis_klasar/Efni/Efni.h"
#include "Node.h"

#ifndef RODUD_HASH_TAFLA_H
#define RODUD_HASH_TAFLA_H

class RodudHashTafla {
    private:
        RodudHashTofluNode* start[5];
        int hash_toflu_lengd = 5;
    public:
        RodudHashTafla();
        ~RodudHashTafla();

        int hash(std::string titill);

        void append(Efni efni);
        void remove(std::string titill);

        RodudHashTofluNode* find_parent(std::string titill);
        bool contains(std::string titill);

        void print();
        void visualize();
};

#endif