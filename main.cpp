#include <iostream>
#include <string>
#include <sstream>

#include "RodudHashTafla/Tafla.h"
#include "RodudHashTafla/Node.h"

#include "efnis_klasar/Efni/Efni.h"
#include "efnis_klasar/Bok/Bok.h"
#include "efnis_klasar/Timarit/Timarit.h"
#include "efnis_klasar/Myndband/Myndband.h"

#include "extra_functions/utf8_string_extention.h"
#include "extra_functions/ui_functions.h"


int main(int argc, char* argv[]) {

    std::cout << "Forrit byrjar!" << "\n\n" << std::flush;

    // Setup global variables
    bool testing = false;

    // Parse arguments
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if (arg == "-t") testing = true;
    }

    RodudHashTafla tafla = RodudHashTafla();

    // Setja upp testing kóða
    if (testing) {
        
        // Filla hash töfluna
        tafla.append(new Bok(1, "C++ basics", "Hrólfur"));
        tafla.append(new Efni(2, "Prufa"));
        tafla.append(new Efni(3, "Test"));
        tafla.append(new Myndband(4, "Hrólfs C++ Kennsla", 5));
        tafla.append(new Efni(5, "Random prufa"));
        
        tafla.append(new Bok(6, "Ahsoka", "E. K. Johnston"));
        tafla.append(new Efni(7, "Prufa2"));
        tafla.append(new Efni(8, "Test3"));
        tafla.append(new Myndband(9, "LTT Wan Show", 73));
        tafla.append(new Efni(10, "Random prufa 1"));
        
        tafla.append(new Timarit(11, "Top Gear", 53));
        tafla.append(new Efni(12, "Prufa4"));
        tafla.append(new Efni(13, "Test7"));
        tafla.append(new Myndband(14, "Is \"Paris Syndrome\" A Real Thing?", 2));
        tafla.append(new Efni(15, "Random prufa 5"));
    }

    // User interface
    int next_id;
    if (testing) next_id = 16;
    else next_id = 0;
    std::string input_strengur, skipun;
    do {
        // Reset skipun
        skipun = "";

        // Read the command from the user
        std::cout << ">>> " << std::flush;
        std::getline(std::cin, input_strengur);

        // Parse the command
        std::stringstream ss;
        ss << input_strengur;
        ss >> skipun;

        if (skipun == "" || skipun == "help") {
            std::cout
            << "help - Þessi skipun sýnir þessar hjálpar upplýsingar." << "\n"
            << "\n"
            << "add [titill] bók/myndband/tímarit [höfundur/lengd/tölublað] - Setja inn bók/myndband/tímarit í safnið." << "\n"
            << "get [titill] - Sýnir hlutinn með nafninu sem þú slærð inn." << "\n"
            << "\n"
            << "modify [titill] bók/myndband/tímarit [nýr titill] [nýr höfundur/ný lengd/nýtt tölublað] - Breyta bók/myndband/tímarit í safninu." << "\n"
            << "remove [titill] - Eyða hlut með þessu nafni úr safninu." << "\n"
            << "\n"
            << "print - Prentar út allt í töflunni." << "\n"
            << "visualize - Sýnir allt í töflunni og í hvaða dálki það er." << "\n"
            << "\n"
            << "exit - Loka forritinu" << "\n"
            << "\n" << std::flush;
        } else if (skipun == "add") {
            
            std::string titill = get_titill(ss);
            if (titill == "") continue;

            std::string data_type;
            ss >> data_type;

            // Tékka á gagnatýpu
            if (data_type == "bók") {
                std::string extra_data = "";
                ss >> extra_data;
                tafla.append(new Bok(next_id, titill, extra_data));
            } else if ( data_type == "myndband") {
                int extra_data = 0;
                ss >> extra_data;
                tafla.append(new Myndband(next_id, titill, extra_data));
            } else if ( data_type == "tímarit") {
                int extra_data = 0;
                ss >> extra_data;
                tafla.append(new Timarit(next_id, titill, extra_data));
            } else {
                std::cout << "Það er bara hægt að bæta við bók/myndband/tímarit, ekki " << data_type << ".\n";
            }

            next_id++;

        } else if (skipun == "get") {

            std::string titill = get_titill(ss);
            if (titill == "") continue;
            
            std::cout << "\n";

            Efni* efni = tafla.get_efni(titill);
            if (efni) efni->print();
            else std::cout << "Það sem þú varst að leita að var ekki fundið.\n";
                
            std::cout << "\n";
            
        } else if (skipun == "modify") {

            std::string titill = get_titill(ss);
            if (titill == "") continue;

            std::string data_type;
            std::string new_titill;
            ss >> data_type >> new_titill;

            // Tékka á gagnatýpu
            if (data_type == "bók") {
                std::string extra_data = "";
                ss >> extra_data;
                tafla.modify(titill, new Bok(0, new_titill, extra_data));
            } else if ( data_type == "myndband") {
                int extra_data = 0;
                ss >> extra_data;
                tafla.modify(titill, new Myndband(0, new_titill, extra_data));
            } else if ( data_type == "tímarit") {
                int extra_data = 0;
                ss >> extra_data;
                tafla.modify(titill, new Timarit(0, new_titill, extra_data));
            } else {
                std::cout << "Það er bara hægt að bæta við bók/myndband/tímarit, ekki " << data_type << ".\n";
            }

        } else if (skipun == "remove") {

            std::string titill = get_titill(ss);
            if (titill == "") continue;

            tafla.remove(titill);
            
        } else if (skipun == "print") {

            std::cout << "\n";
            tafla.print();
            std::cout << "\n";
            
        } else if (skipun == "visualize") {

            std::cout << "\n";
            tafla.visualize();
            std::cout << "\n";
            
        } else if (skipun == "exit") {
            std::cout << "Exiting program..." << "\n" << std::flush;
        } else {
            std::cout << "Skipunin sem þú slóst inn var ekki fundin, sláðu inn help til þess að fá lista yfir skipanir sem virka.\n" << "\n" << std::flush;
        }

    } while (skipun != "exit");
    
    return 0;
}