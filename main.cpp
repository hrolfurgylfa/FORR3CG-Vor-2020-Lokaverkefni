#include <iostream>
#include <string>

// #include "RodudHashTafla/Tafla.h"

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

    // rodud_hash_tafla = RodudHashTafla();
    // rodud_hash_tafla.hash("Prufa");

    std::cout << "Lengd: " << utf8_string_length("Bóæ") << "\n";
    std::cout << "Stafur 2: " << utf8_string_index("Bóæ", 1) << "\n";
    std::cout << "Number of continuation bytes: " << has_continuation_bytes("𝖌"[0]);

    std::cout << "\nForrit búið!" << std::flush;
    return 0;
}