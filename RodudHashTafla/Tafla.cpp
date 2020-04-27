#include <iostream>
#include <string>

#include "Tafla.h"
#include "Node.h"

RodudHashTafla::RodudHashTafla() {
    for (int i = 0; i < this->hash_toflu_lengd; i++)
        this->start[i] = nullptr;
}
RodudHashTafla::~RodudHashTafla() {
    for (int i = 0; i < hash_toflu_lengd; i++)
    {
        RodudHashTofluNode* current_node = this->start[i];
        while (current_node != nullptr)
        {
            RodudHashTofluNode* old_node = current_node;
            current_node = current_node->next;
            delete old_node;
        }
    }
}

int RodudHashTafla::hash(std::string titill) {
    int summa = 0;
    for (int i = 0; i < titill.length(); i++)
        summa += titill[i];

    return summa % this->hash_toflu_lengd;
}

void RodudHashTafla::append(Efni efni) {
    if(this->contains(efni.get_titill())) return;

    int titils_hash = this->hash(efni.get_titill());

    if(this->start[titils_hash] == nullptr) {
        this->start[titils_hash] = new RodudHashTofluNode(efni);
    } else {
        RodudHashTofluNode* nyttStak = new RodudHashTofluNode(efni);
        if(this->start[titils_hash]->data.get_id() < efni.get_id()) {
            nyttStak->next = this->start[titils_hash];
            this->start[titils_hash] = nyttStak;
        } else {
            // std::cout << "Going to loop!!!";
            RodudHashTofluNode* current = this->start[titils_hash];
            RodudHashTofluNode* prev = this->start[titils_hash];
            while(current && current->data.get_id() >= efni.get_id()) {
                prev = current;
                current = current->next;
            }
            prev->next = nyttStak;
            nyttStak->next = current;
        }
    }
}/*
void RodudHashTafla::remove(int id) {
    if(this->start->data.get_id() == id) {
        RodudHashTofluNode* new_start = this->start->next;
        RodudHashTofluNode* old_start = this->start;
        this->start = new_start;
        delete old_start;
    } else {
        RodudHashTofluNode* fyrra_stak = this->find_parent(id);
        if(!fyrra_stak) return;// Passa að það hafi verið fundið stak
        
        // if(fyrra_stak->next->next){
        //     //Eyða venjulega
        // } else {
        //     // Það er ekkert lokastak til þess að bæta við
        // }
        
        RodudHashTofluNode* new_child = fyrra_stak->next->next;
        RodudHashTofluNode* old_child = fyrra_stak->next;
        fyrra_stak->next = new_child;
        delete old_child;
    }
}
*/
RodudHashTofluNode* RodudHashTafla::find_parent(std::string titill) {
    int col_num = this->hash(titill);
    
    RodudHashTofluNode* current_node = this->start[col_num];
    RodudHashTofluNode* old_node = nullptr;

    while (current_node) {
        if (current_node->data.get_titill() == titill) return old_node;

        old_node = current_node;
        current_node = current_node->next;
    }

    return nullptr;
}
bool RodudHashTafla::contains(std::string titill) {
    RodudHashTofluNode* fundid_node = this->find_parent(titill);
    if (fundid_node) return true;
    else return false;
}

void RodudHashTafla::print() {
    for (int i = 0; i < this->hash_toflu_lengd; i++)
    {
        RodudHashTofluNode* current_node = this->start[i];
        while (current_node != nullptr)
        {
            current_node->data.print();
            current_node = current_node->next;
        }
    }
}

void RodudHashTafla::visualize() {
    for (int i = 0; i < this->hash_toflu_lengd; i++)
    {
        std::cout << i+1 << ". ";
        RodudHashTofluNode* current_node = this->start[i];
        while (current_node != nullptr)
        {
            std::cout << current_node->data.get_eight_letters() << " - ";
            current_node = current_node->next;
        }
        std::cout << "\n";
    }
}