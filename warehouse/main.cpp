#include <iostream>
#include <string>
#include "src/include/warehouse.hpp"
#include "src/include/pallet.hpp"
#include "src/include/shelf.hpp"
#include "src/include/employee.hpp"

int main(void){
    std::cout << "===== Warehouse =====\n";

    // Starting our warehouse business
    Warehouse dassiesWarehouse;
    std::cout << dassiesWarehouse;
    
    // Stocking up our warehouse
    Pallet p1("Cherry Red Keyboards", 50, 50);
    Pallet p2("HyperX Headsets", 30, 30);
    Pallet p3("Logitech Headsets", 30, 30);

    Pallet p4("Mac Laptops", 50, 50);
    Pallet p5("Laptop Chargers", 75, 75);
    Pallet p6("Laptop Cases", 35, 35);
    Pallet p7("Windows Laptops", 100, 100);

    Pallet p8("Cherry Red Keyboards", 25, 25);
    Pallet p9("HyperX Headsets", 20, 20);
    Pallet p10("Logitech Headsets", 20, 20);
    Pallet p11("Action Headsets", 10, 10);

    // Storing all items on shelves
    Shelf s1(p1, p2, p3);
    dassiesWarehouse.addShelf(s1);

    Shelf s2(p4, p5, p6, p7);
    dassiesWarehouse.addShelf(s2);

    Shelf s3(p8, p9, p10, p11);
    dassiesWarehouse.addShelf(s3);

    // Hiring employees to take care of our stock
    Employee e1("Dassie", true);
    dassiesWarehouse.addEmployee(e1);

    Employee e2("Jesse", false);
    dassiesWarehouse.addEmployee(e2);

    //Check out warehouse
    std::cout << "\n===== Warehouse Check =====\n" << 
        dassiesWarehouse << "\n";

    // Rearrange shelves
    std::cout << "Sorted shelf:\n" << s2;

    //Check how much product we have in total
    std::cout << "\n===== Check Stock =====" <<
        "\nCherry Red Keyboards: " << std::to_string(dassiesWarehouse.getItemAmount("Cherry Red Keyboards")) <<
        "\nHyperX Headsets: " << std::to_string(dassiesWarehouse.getItemAmount("HyperX Headsets")) << "\n";

    return 0;
}
