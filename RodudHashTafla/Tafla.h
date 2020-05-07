#include "../efnis_klasar/Efni/Efni.h"
#include "../efnis_klasar/Bok/Bok.h"
#include "../efnis_klasar/Myndband/Myndband.h"
#include "../efnis_klasar/Timarit/Timarit.h"

#include "Node.h"

#ifndef RODUD_HASH_TAFLA_H
#define RODUD_HASH_TAFLA_H

class RodudHashTafla {
    private:
        RodudHashTofluNode** start;
        int hash_toflu_lengd = 5;
    public:
        RodudHashTafla();
        RodudHashTafla(int lengd);
        ~RodudHashTafla();

        int hash(std::string titill);

        void append(Efni* efni);
        void remove(std::string titill);

        RodudHashTofluNode* find_parent(std::string titill);
        RodudHashTofluNode* find_node(std::string titill);
        bool contains(std::string titill);

        Efni* get_efni(std::string titill);
        Bok* get_bok(std::string titill);
        Myndband* get_myndband(std::string titill);
        Timarit* get_timarit(std::string titill);

        void print();
        void visualize();
};

#endif