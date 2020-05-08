#include <iostream>
#include <string>
#include <sstream>

std::string get_titill(std::stringstream &ss) {            
    std::string titill = "";
    ss >> titill;

    // Passa að það sé titill
    if (titill == "")
        std::cout << "Vinsamlegast sláðu inn titil." << "\n";
    
    return titill;
}