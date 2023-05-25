#include "include/warehouse.hpp"

Warehouse::Warehouse() :
    employees({}), shelves({}) {}

void Warehouse::addEmployee(Employee employee) {
    employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf) {
    shelves.push_back(shelf);
}

bool Warehouse::hasAvailableCertifiedEmployee() {
    for (Employee employee : employees) {
        if (employee.getForkliftCertificate() && !employee.getBusy()){
            return true;
        }
    }
    return false;
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    if (!hasAvailableCertifiedEmployee()) {
        return false;
    }

    int lenPallets = shelf.pallets.size();
    // Sort from left to right
    for (int i = 0; i < lenPallets - 1; i++) {
        int minIndex = i;
        for (int j = i + 1 ; j < lenPallets; j++) {
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

int Warehouse::getEmployeeTotal() {
    return employees.size();
}

int Warehouse::getShelfTotal() {
    return shelves.size();
}

std::ostream& operator<<(std::ostream& out, Warehouse& warehouse) {
    // Get Employees + Shelves
    if (warehouse.getEmployeeTotal() == 0) {
        out << "No employees yet \n";
    } else {
        out << "Warehouse Employees: \n";
        for (Employee employee : warehouse.employees) {
            out << employee << "\n";
        }
    }

    if (warehouse.getShelfTotal() == 0) {
        out << "No shelves yet \n";
    } else {
        out << "Warehouse Shelves: \n";
        for (Shelf shelf : warehouse.shelves) {
            out << shelf << "\n";
        }
    }

    return out;
}