#include "DiamondTrap.hpp"

int main() {
    
    DiamondTrap Diamond("Doggo");

    Diamond.attack("Cat");
    Diamond.whoAmI();

    std::cout << "\n------------\n" << std::endl;
    return 0;
}