#pragma once
#include <iostream>
#include "icontainer.hpp"
#include <array>
#include "pallet.hpp"

class Shelf : public IContainer {
    public:
        std::array<Pallet, 4> pallets;

        // Shelf constructor
        Shelf(Pallet p1, Pallet p2, Pallet p3, Pallet p4);
        Shelf(Pallet p1, Pallet p2, Pallet p3);
        Shelf(Pallet p1, Pallet p2);
        Shelf(Pallet p1);
        Shelf();
        
        bool swapPallet(int slot, int slot2);
        bool isEmpty() const override;
        bool isFull() const override;

        friend std::ostream& operator<<(std::ostream& out, Shelf& shelf);

        // Shelf destructor
        ~Shelf();

};