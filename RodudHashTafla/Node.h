#include "../efnis_klasar/Efni/Efni.h"

#ifndef RODUD_HASH_TOFLU_NODE_H
#define RODUD_HASH_TOFLU_NODE_H

struct RodudHashTofluNode {
    Efni data;
    RodudHashTofluNode* next;

    RodudHashTofluNode(Efni efni) {
        this->data = efni;
        this->next = nullptr;
    }
};

#endif