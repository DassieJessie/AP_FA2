# Warehouse
## Adaptive Programming
### Year 1 Period 4 - 2023

## Introduction
For this project we'll be implementing the UML structer found below. 

In a warehouse you can store shelves with pallets on them. These pallets are handled by qualified employees. 

## How to run
Download project
> To run main, please change your makefile project outline:
> - Build Target: [all]
> - Launch target: [main]
> - Makefile: [Makefile]
>
> To run tests, please change the following:
> - Launch target: [test]

## Main Output
````
===== Warehouse =====
No employees yet 
No shelves yet 

===== Warehouse Check =====
Warehouse Employees: 
Name: Dassie
Busy: 0
Forklift Certificate: 1

Name: Jesse
Busy: 0
Forklift Certificate: 0

Warehouse Shelves: 
=== Shelf pallets === 
Item name: Cherry Red Keyboards
Item count: 50
Remaining space: 0

Item name: HyperX Headsets
Item count: 30
Remaining space: 0

Item name: Logitech Headsets
Item count: 30
Remaining space: 0

Item name: 
Item count: 0
Remaining space: 0

=== Shelf pallets === 
Item name: Mac Laptops
Item count: 50
Remaining space: 0

Item name: Laptop Chargers
Item count: 75
Remaining space: 0

Item name: Laptop Cases
Item count: 35
Remaining space: 0

Item name: Windows Laptops
Item count: 100
Remaining space: 0

=== Shelf pallets === 
Item name: Cherry Red Keyboards
Item count: 25
Remaining space: 0

Item name: HyperX Headsets
Item count: 20
Remaining space: 0

Item name: Logitech Headsets
Item count: 20
Remaining space: 0

Item name: Action Headsets
Item count: 10
Remaining space: 0

Sorted shelf:
=== Shelf pallets === 
Item name: Laptop Cases
Item count: 35
Remaining space: 0

Item name: Mac Laptops
Item count: 50
Remaining space: 0

Item name: Laptop Chargers
Item count: 75
Remaining space: 0

Item name: Windows Laptops
Item count: 100
Remaining space: 0

===== Check Stock =====
Cherry Red Keyboards: 75
HyperX Headsets: 50

===== Pick up Stock =====
20 Cherry Red Keyboards 
New Total: 55

200 Cherry Red Keyboards 
New Total: 55 - Cannot pick up 200 items

50 Cherry Red Keyboards 
New Total: 5
````

## Proof of validation
### Test Warehouse
