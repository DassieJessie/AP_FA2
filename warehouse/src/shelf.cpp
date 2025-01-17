#include "include/shelf.hpp"

Shelf::Shelf(Pallet p1) : pallets({p1, Pallet(), Pallet(), Pallet()}) {}
Shelf::Shelf(Pallet p1, Pallet p2) : pallets({p1, p2, Pallet(), Pallet()}) {}
Shelf::Shelf(Pallet p1, Pallet p2, Pallet p3) : pallets({p1, p2, p3, Pallet()}) {}
Shelf::Shelf(Pallet p1, Pallet p2, Pallet p3, Pallet p4) : pallets({p1, p2, p3, p4}) {}
Shelf::Shelf() : pallets({Pallet(), Pallet(), Pallet(), Pallet()}) {}
        
bool Shelf::swapPallet(int slot, int slot2) {
    // Validate input
    int lenPallets = pallets.size();
    if (slot < 0 || slot2 < 0 || slot > lenPallets || slot2 > lenPallets) {
        return false;
    }

    // Swap pallets
    std::swap(pallets[slot], pallets[slot2]);
    return true;
}

bool Shelf::isEmpty() const {
    for (Pallet pallet : pallets) {
        if (!pallet.isEmpty()) {
            return false;
        }
    }

    return true;
}

bool Shelf::isFull() const {
    for (Pallet pallet : pallets) {
        if (!pallet.isFull()) {
            return false;
        }
    }

    return true;
}

std::ostream& operator<<(std::ostream& out, Shelf& shelf) {
    // Pallets
    out << "=== Shelf pallets === \n";
    for (Pallet pallet : shelf.pallets) {
        out << pallet << "\n";
    }

    return out;
}

Shelf::~Shelf() {}

