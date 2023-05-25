#include "include/catch.hpp"
#include "../src/include/warehouse.hpp"


TEST_CASE("Pick item wrong amount", "Warehouse::pickItems") {
    Warehouse w;

    Shelf s1;
    s1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };

    w.addShelf(s1);
    w.addEmployee(Employee("Bob", true));

    bool pickedItems = w.pickItems("Books", 200);
    // Cannot pick items
    REQUIRE(!pickedItems);
    REQUIRE(w.getItemAmount("Books") == 100);

    pickedItems = w.pickItems("Books", 100);
    REQUIRE(pickedItems);
}

TEST_CASE("Pick item on none existing item", "Warehouse::pickItems") {
    Warehouse w;

    Shelf s1;
    s1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };

    w.addShelf(s1);
    w.addEmployee(Employee("Bob", true));

    bool pickedItems = w.pickItems("Laptops", 20);
    // Cannot pick items
    REQUIRE(!pickedItems);
    REQUIRE(w.getItemAmount("Books") == 100);
}

TEST_CASE("Cannot pick negative items", "Warehouse::pickItems") {
    Warehouse w;

    Shelf s1;
    s1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };

    w.addShelf(s1);
    w.addEmployee(Employee("Bob", true));

    bool pickedItems = w.pickItems("Books", -20);
    // Cannot pick items
    REQUIRE(!pickedItems);
    REQUIRE(w.getItemAmount("Books") == 100);

    pickedItems = w.pickItems("Books", 0);
    REQUIRE(!pickedItems);
}

TEST_CASE("Changes the appropiate amounts", "Warehouse::pickItems") {
    Warehouse w;

    Shelf s1;
    s1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };

    w.addShelf(s1);
    w.addEmployee(Employee("Bob", true));

    bool pickedItems = w.pickItems("Books", 40);
    REQUIRE(pickedItems);

    REQUIRE(w.getItemAmount("Books") == 60);
}

TEST_CASE("Pick items without shelves", "Warehouse::pickItems"){
    Warehouse w;
    bool pickedItems = w.pickItems("Books", 40);
    REQUIRE(!pickedItems);
}

TEST_CASE("Pick from multiple shelves and pallets", "Warehouse::pickItems") {
    Warehouse w;

    Shelf s1;
    s1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };

    Shelf s2;
    s2.pallets = {
        Pallet("Toilet Roll", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Toilet Roll", 100, 30), 
        Pallet("Books", 100, 10)
    };

    w.addShelf(s1);
    w.addShelf(s2);
    w.addEmployee(Employee("Bob", true));

    REQUIRE(w.getItemAmount("Books") == 150);

    bool pickedItems = w.pickItems("Books", 120);
    REQUIRE(pickedItems);

    REQUIRE(w.getItemAmount("Books") == 30);

}

TEST_CASE("Pick items employee busy", "Warehouse::pickItems") {
    Warehouse w;

    Shelf s1;
    s1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };

    w.addShelf(s1);
    w.addEmployee(Employee("Bob", true));
    w.employees[0].setBusy(true);

    bool pickedItems = w.pickItems("Books", 20);
    REQUIRE(!pickedItems);

}
