#include <string>

#ifndef EFNI_H
#define EFNI_H

class Efni
{
protected:
    int id;
    std::string titill;
public:
    Efni();
    Efni(int id, std::string titill);
    virtual ~Efni();

    int get_id();
    void set_id(int id);
    std::string get_titill();
    void set_titill(std::string titill);

    virtual void print();
    std::string get_eight_letters();

};

#endif