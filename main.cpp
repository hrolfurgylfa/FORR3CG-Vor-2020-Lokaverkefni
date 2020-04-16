#include <iostream>
#include <string>

#include "efnis_klasar/Efni/Efni.h"

#include "efnis_klasar/Bok/Bok.h"
#include "efnis_klasar/Timarit/Timarit.h"
#include "efnis_klasar/Myndband/Myndband.h"


int main() {
    std::cout << "Forrit byrjar!" << "\n\n" << std::flush;

    Efni efni = Efni(1, "Bók");
    efni.print();

    Bok bok = Bok(2, "Prufa", "Jón");
    bok.print();

    Timarit timarit = Timarit(3, "Jóns Bílar", 4);
    timarit.print();

    Myndband myndband = Myndband(4, "MORE Nondestructive Modeling in Blender", 35);
    myndband.print();

    std::cout << "\nForrit búið!" << std::flush;
    return 0;
}