#include "include/pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount) :
    itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount) {}

Pallet::Pallet():
    itemName(""), itemCapacity(0), itemCount(0) {}


std::string Pallet::getitemName() {
    return itemName;
}

int Pallet::getitemCount() {
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