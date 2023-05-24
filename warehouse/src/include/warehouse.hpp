#pragma once
#include <vector>
#include "employee.hpp"
#include "shelf.hpp"

class Warehouse {
    public:
        std::vector<Employee> employees;
        std::vector<Shelf> shelves;

        Warehouse();

        void addEmployee(Employee employee);
        void addShelf(Shelf shelf);
        bool hasForkliftCeritificate();
        bool rearrangeShelf(Shelf& shelf);
        int getItemAmount(std::string itemName);
        bool pickItems(std::string itemName, int itemCount);
};