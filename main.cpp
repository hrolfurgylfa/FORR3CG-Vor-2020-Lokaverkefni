#include <iostream>
#include <string>

// #include "RodudHashTafla/Tafla.h"

#include "RodudHashTafla/Tafla.h"
#include "RodudHashTafla/Node.h"

#include "efnis_klasar/Efni/Efni.h"
#include "efnis_klasar/Bok/Bok.h"
#include "efnis_klasar/Timarit/Timarit.h"
#include "efnis_klasar/Myndband/Myndband.h"

#include "extra_functions/utf8_string_extention.h"


int main() {
    std::cout << "Forrit byrjar!" << "\n\n" << std::flush;

    // Efni efni = Efni(1, "Bók");
    // efni.print();
    // std::cout << efni.get_eight_letters() << "|\n" << std::flush;

    // Bok bok = Bok(2, "Prufa", "Jón");
    // bok.print();

    // Timarit timarit = Timarit(3, "Jóns Bílar", 4);
    // timarit.print();

    // Myndband myndband = Myndband(4, "MORE Nondestructive Modeling in Blender", 35);
    // myndband.print();

    // Búa til og filla töfluna
    RodudHashTafla tafla = RodudHashTafla();
    std::cout << "RodudHashTafla created\n";
    tafla.append(new Bok(1, "C++ basics", "Hrólfur"));
    tafla.append(new Efni(2, "Prufa"));
    tafla.append(new Efni(3, "Test"));
    tafla.append(new Myndband(4, "Hrólfs C++ Kennsla", 5));
    tafla.append(new Efni(5, "Random prufa"));
    tafla.visualize();

    std::cout << "------------------------------\n";
    tafla.append(new Bok(6, "Ahsoka", "E. K. Johnston"));
    tafla.append(new Efni(7, "Prufa2"));
    tafla.append(new Efni(8, "Test3"));
    tafla.append(new Myndband(9, "LTT Wan Show", 73));
    tafla.append(new Efni(10, "Random prufa 1"));
    tafla.visualize();

    std::cout << "------------------------------\n";
    tafla.append(new Timarit(11, "Top Gear", 53));
    tafla.append(new Efni(12, "Prufa4"));
    tafla.append(new Efni(13, "Test7"));
    tafla.append(new Myndband(14, "Is \"Paris Syndrome\" A Real Thing?", 2));
    tafla.append(new Efni(15, "Random prufa 5"));
    tafla.visualize();

    std::cout << "------------------------------\n";
    tafla.set_max_depth(1);
    tafla.visualize();

    // Finna hluti
    // std::cout << "\n";
    // tafla.get_myndband("Hrólfs C++ Kennsla")->print();
    // // std::cout << tafla.get_myndband("Hrólfs C++ Kennsla")->get_lengd();
    // std::cout << "\n";
    // tafla.get_bok("C++ basics")->print();
    // // std::cout << "Bók: " << tafla.get_bok("C++ basics")->get_hofundur();

    // Eyða hlutum
    // std::cout << "\nEyða hlutum:\n";
    // tafla.remove("Prufa");
    // tafla.remove("Test");
    // tafla.remove("Random prufa");
    // tafla.remove("This Item Does Not Exist");
    // tafla.visualize();

    // std::cout << "Lengd: " << utf8_string_length("Bóæ") << "\n";
    // std::cout << "Stafur 2: " << utf8_string_index("Bóæ", 1) << "\n";
    // std::cout << "Number of continuation bytes: " << has_continuation_bytes("𝖌"[0]);

    std::cout << "\nForrit búið!" << std::flush;
    return 0;
}