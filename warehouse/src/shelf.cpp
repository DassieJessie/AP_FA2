#include "include/shelf.hpp"

Shelf::Shelf() :
    pallets({Pallet(), Pallet(), Pallet(), Pallet()}) {}
        
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

