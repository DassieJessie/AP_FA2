#include "include/warehouse.hpp"

Warehouse::Warehouse() :
    employees({}), shelves({}) {}

void Warehouse::addEmployee(Employee employee) {
    employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf) {
    shelves.push_back(shelf);
}

bool Warehouse::hasForkliftCeritificate() {
    for (Employee employee : employees) {
        if (!employee.getForkliftCertificate()){
            return false;
        }
    }
    return true;
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    if (!hasForkliftCeritificate()) {
        return false;
    }

    int lenPallets = shelf.pallets.size();
    // Sort from left to right
    for (int i = 0; i < lenPallets - 1; i++) {
        int minIndex = i;
        for (int j = 0 ; j < lenPallets -1; j++) {
            if (shelf.pallets[minIndex].getItemCount() > shelf.pallets[j].getItemCount()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            shelf.swapPallet(i, minIndex);
        }
    }

    return true;
}

int Warehouse::getItemAmount(std::string itemName) {
    int totalAvailable = 0;

    for (Shelf& shelf : shelves) {
        for (Pallet& pallet : shelf.pallets) {
            if (pallet.getItemName() == itemName) {
                totalAvailable += pallet.getItemCount();
            }
        }
    }

    return totalAvailable;
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    // Validate pick count
    if (getItemAmount(itemName) < itemCount || itemCount <= 0) {
        return false;
    }

    for (Shelf& shelf : shelves) {
        for (Pallet& pallet : shelf.pallets) {
            if (pallet.getItemName() == itemName) {
                while (pallet.getItemCount() > 0 && itemCount != 0) {
                    pallet.takeOne();
                    itemCount--;
                }
            }
        }
    }

    return true;
}