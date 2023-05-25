#pragma once
#include <iostream>
#include "icontainer.hpp"
#include <string>

class Pallet : public IContainer {
    private:
        int itemCount; // Only mutable through taking and putting
        std::string itemName; // Only mutable if empty
        int itemCapacity; // Only mutable if empty

    public:
        // Pallet constructors
        Pallet(std::string itemName, int itemCapacity, int itemCount);
        Pallet();

        // Getters class variables
        std::string getItemName();
        int getItemCount();

        bool isEmpty() const override;
        bool isFull() const override;

        int getRemainingSpace();
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
        bool takeOne();
        bool putOne();

        friend std::ostream& operator<<(std::ostream& out, Pallet& pallet);
};