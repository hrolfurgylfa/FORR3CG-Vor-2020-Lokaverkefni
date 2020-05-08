#include <iostream>
#include <string>

#include "Tafla.h"
#include "Node.h"

RodudHashTafla::RodudHashTafla() {
    this->initialize();
}
RodudHashTafla::RodudHashTafla(int lengd) {
    this->hash_toflu_lengd = lengd;
    this->initialize();
}
RodudHashTafla::RodudHashTafla(int lengd, int max_depth) {
    this->hash_toflu_lengd = lengd;
    this->max_depth = max_depth;
    this->initialize();
}
RodudHashTafla::RodudHashTafla(int lengd, int max_depth, int expand_value) {
    this->hash_toflu_lengd = lengd;
    this->max_depth = max_depth;
    this->expand_value = expand_value;
    this->initialize();
}
RodudHashTafla::~RodudHashTafla() {
    for (int i = 0; i < hash_toflu_lengd; i++)
    {
        RodudHashTofluNode* current_node = this->start[i];
        while (current_node != nullptr)
        {
            RodudHashTofluNode* old_node = current_node;
            current_node = current_node->next;
            delete old_node->data;
            delete old_node;
        }
    }
}
void RodudHashTafla::initialize() {
    this->start = new RodudHashTofluNode*[this->hash_toflu_lengd];
    for (int i = 0; i < this->hash_toflu_lengd; i++)
        this->start[i] = nullptr;
}

int RodudHashTafla::hash(std::string titill) {
    int summa = 0;
    for (int i = 0; i < titill.length(); i++)
        summa += titill[i];

    return summa % this->hash_toflu_lengd;
}

void RodudHashTafla::append(Efni* efni) {
    if(this->contains(efni->get_titill())) return;

    int titils_hash = this->hash(efni->get_titill());

    RodudHashTofluNode* nytt_stak = new RodudHashTofluNode(efni);
    if (this->start[titils_hash] == nullptr) {
        this->start[titils_hash] = nytt_stak;
    }
    else if ((this->start[titils_hash])->data->get_id() < efni->get_id()) {
        nytt_stak->next = this->start[titils_hash];
        this->start[titils_hash] = nytt_stak;
    }
    else {
        // std::cout << "Going to loop!!!";
        RodudHashTofluNode* current = this->start[titils_hash];
        RodudHashTofluNode* prev = this->start[titils_hash];
        while(current && current->data->get_id() >= efni->get_id()) {
            prev = current;
            current = current->next;
        }
        prev->next = nytt_stak;
        nytt_stak->next = current;
    }

    // Tékka hvort að listinn hafi nokkuð orðið of langur
    if (!this->in_expand_operation && this->check_linked_list_size(titils_hash)) this->expand(this->expand_value);
}
void RodudHashTafla::modify(std::string titill, Efni* efni) {
    if (this->contains(titill)) {
        int old_id = this->get_efni(titill)->get_id();
        efni->set_id(old_id);
        this->remove(titill);
        this->append(efni);
    }
}
void RodudHashTafla::remove(std::string titill) {
    int col_num = this->hash(titill);
    if (!this->start[col_num]) return;// Dálkurinn er tómur

    if (this->start[col_num]->data->get_titill() == titill) {
        RodudHashTofluNode* old_start = this->start[col_num];
        this->start[col_num] = this->start[col_num]->next;

        delete old_start->data;
        delete old_start;
    } else {
        RodudHashTofluNode* fyrra_stak = this->find_parent(titill);
        if (!fyrra_stak) return;// Passa að það hafi verið fundið stak
        
        RodudHashTofluNode* old_child = fyrra_stak->next;// Geyma instancið sem þarf að eyða
        fyrra_stak->next = fyrra_stak->next->next; // Taka stakið sem á að eyða úr linked listanum

        delete old_child->data;
        delete old_child;
    }
}

// Þetta fall finnur nodið á undan nodinu sem þú ert að leita að,
// þetta getur verið hentugt ef þú ert til dæmis að fikta í röð
// linked listans, annars ef það þarf ekki að gera það er fallið
// find_node betra vegna þess að þetta fall skilar nullptr ef 
// það sem þú ert að leita að er fyrst í this->start[i] listanum.
RodudHashTofluNode* RodudHashTafla::find_parent(std::string titill) {
    int col_num = this->hash(titill);
    
    RodudHashTofluNode* current_node = this->start[col_num];
    RodudHashTofluNode* old_node = nullptr;

    while (current_node) {
        if (current_node->data->get_titill() == titill) return old_node;

        old_node = current_node;
        current_node = current_node->next;
    }

    return nullptr;
}
// Þetta fall er svipað og find_parent en ef það þarf ekki að breyta staðsetningu
// nodesins í node listanum þá er þetta fall betra vegna þess að find_parent getur
// ekki fundið fyrsta stakið í this->start[i] listanum.
RodudHashTofluNode* RodudHashTafla::find_node(std::string titill) {
    int col_num = this->hash(titill);
    if (this->start[col_num] == nullptr) return nullptr;// Það er ekkert í listanum sem ég er að reyna að lúppa í gegnum
    if (this->start[col_num]->data->get_titill() == titill) return this->start[col_num];// Fyrsta stakið er það sem þarf að skila

    RodudHashTofluNode* parent = find_parent(titill);
    if (!parent) return nullptr;
    return parent->next;
}
// Þetta fall tékkar hvort að efni með ákveðnum titli sé í hash töflunni.
bool RodudHashTafla::contains(std::string titill) {
    if (this->find_node(titill)) return true;
    else return false;
}

// Þetta fall stækkar hash töflu arrayinn, add_to_size þaarf að vera stærri en 0.
void RodudHashTafla::expand(int add_to_size) {
    this->in_expand_operation = true;

    // Geyma stærðina
    int old_size = this->hash_toflu_lengd;
    this->hash_toflu_lengd += add_to_size;
    
    // Geyma listana
    RodudHashTofluNode** old_start = this->start;
    this->start = new RodudHashTofluNode*[this->hash_toflu_lengd];

    // lúppa í gegnum old_start og setja allt í new_start
    for (int i = 0; i < old_size; i++)
    {
        RodudHashTofluNode* current_node = old_start[i];
        while (current_node != nullptr)
        {
            RodudHashTofluNode* old_node = current_node;
            current_node = current_node->next;

            this->append(old_node->data);
            
            delete old_node;
        }
    }

    // Eyða gamla listanum
    delete old_start;

    // Ég er ekki lengur að vinna á listanum svo að append má núna aftur stækka hann
    this->in_expand_operation = false;

    // Tékka hvort að listinn hafi nokkuð orðið of langur
    if (this->check_linked_list_size()) this->expand(this->expand_value);
}
// Þetta fall skilar true ef að einhver dálkur í hash töflunni er orðinn of
// langur, annars skilar fallið false.
bool RodudHashTafla::check_linked_list_size() {
    for (int i = 0; i < this->hash_toflu_lengd; i++)
        if (this->check_linked_list_size(i)) return true;
    return false;
}
// Þetta fall skilar true ef að dálkurinn sem er settur inn er orðinn of langur,
// annars skilar fallið false.
bool RodudHashTafla::check_linked_list_size(int col_num) {
    int depth_count = 0;
    RodudHashTofluNode* current_node = this->start[col_num];
    while (current_node != nullptr)
    {
        RodudHashTofluNode* old_node = current_node;
        current_node = current_node->next;

        depth_count++;

        if (depth_count > this->max_depth) {
            return true;
            break;
        }
    }
    return false;
}

int RodudHashTafla::get_max_depth() { return this->max_depth; }
void RodudHashTafla::set_max_depth(int max_depth) {
    if (max_depth > 0) {
        this->max_depth = max_depth;
        if (check_linked_list_size()) expand(this->expand_value);
    }
}
int RodudHashTafla::get_expand_value() { return expand_value; }
void RodudHashTafla::set_expand_value(int expand_value) {
    if (expand_value > 0) this->expand_value = expand_value;
}

Efni* RodudHashTafla::get_efni(std::string titill) {
    RodudHashTofluNode* node = this->find_node(titill);
    if (node) return node->data;
    else return nullptr;
}
Bok* RodudHashTafla::get_bok(std::string titill) { return dynamic_cast<Bok*>(this->get_efni(titill)); }
Myndband* RodudHashTafla::get_myndband(std::string titill) { return dynamic_cast<Myndband*>(this->get_efni(titill)); }
Timarit* RodudHashTafla::get_timarit(std::string titill) { return dynamic_cast<Timarit*>(this->get_efni(titill)); }

void RodudHashTafla::print() {
    for (int i = 0; i < this->hash_toflu_lengd; i++)
    {
        RodudHashTofluNode* current_node = this->start[i];
        while (current_node != nullptr)
        {
            current_node->data->print();
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
            std::cout << current_node->data->get_eight_letters() << " - ";
            current_node = current_node->next;
        }
        std::cout << "\n";
    }
}