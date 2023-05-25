#include "include/pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount) :
    itemCount(itemCount), itemName(itemName), itemCapacity(itemCapacity) {}

Pallet::Pallet() :
    itemCount(0), itemName(""), itemCapacity(0) {}


std::string Pallet::getItemName() {
    return itemName;
}

int Pallet::getItemCount() {
    return itemCount;
}

bool Pallet::isEmpty() const {
    return itemCount == 0;
}

bool Pallet::isFull() const {
    return itemCount == itemCapacity;
}

int Pallet::getRemainingSpace() {
    return itemCapacity - itemCount;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity) {
    if (isEmpty()) {
        this -> itemName = itemName;
        this -> itemCapacity = itemCapacity;
        return true;
    }
    return false;
}

bool Pallet::takeOne() {
    if (!isEmpty()) {
        itemCount--;
        return true;
    }
    return false;
}

bool Pallet::putOne() {
    if (!isFull()) {
        itemCount++;
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, Pallet& pallet) {
    out << "Item name: " << pallet.getItemName() <<
        "\nItem count: " << pallet.getItemCount() <<
        "\nRemaining space: " << pallet.getRemainingSpace() << "\n";
    
    return out;
}