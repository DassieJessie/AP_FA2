#pragma once
#include "icontainer.hpp"
#include <array>
#include "pallet.hpp"

class Shelf : public IContainer {
    public:
        std::array<Pallet, 4> pallets;

        // Shelf constructor
        Shelf();
        
        bool swapPallet(int slot, int slot2);
        bool isEmpty() const override;
        bool isFull() const override;

        // Shelf destructor
        ~Shelf();

};