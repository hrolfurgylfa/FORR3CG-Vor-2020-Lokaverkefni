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
        int max_depth = 3;
        int expand_value = 2;

        bool in_expand_operation = false;

        void initialize();
    public:
        RodudHashTafla();
        RodudHashTafla(int lengd);
        RodudHashTafla(int lengd, int max_depth);
        RodudHashTafla(int lengd, int max_depth, int expand_value);
        ~RodudHashTafla();

        int hash(std::string titill);

        void append(Efni* efni);
        void modify(std::string titill, Efni* efni);
        void remove(std::string titill);

        RodudHashTofluNode* find_parent(std::string titill);
        RodudHashTofluNode* find_node(std::string titill);
        bool contains(std::string titill);

        void expand(int add_to_size);
        bool check_linked_list_size();
        bool check_linked_list_size(int col_num);

        int get_max_depth();
        void set_max_depth(int max_depth);
        int get_expand_value();
        void set_expand_value(int expand_value);

        Efni* get_efni(std::string titill);
        Bok* get_bok(std::string titill);
        Myndband* get_myndband(std::string titill);
        Timarit* get_timarit(std::string titill);

        void print();
        void visualize();
};

#endif