#include "include/employee.hpp"

// Employee constructor
Employee::Employee(std::string name, bool forkliftCertificate) :
    name(name), forkliftCertificate(forkliftCertificate) {}
        
// Getters & Setter Class variables
std::string Employee::getName() {
    return name;
}

bool Employee::getBusy() {
    return busy;
}

void Employee::setBusy(bool busy) {
    this -> busy = busy;
}

bool Employee::getForkliftCertificate() {
    return forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftCertificate) {
    this -> forkliftCertificate = forkliftCertificate;
}

std::ostream& operator<<(std::ostream& out, Employee& employee) {
    out << "Name: " << employee.getName() << 
        "\nBusy: " << employee.getBusy() << 
        "\nForklift Certificate: " << employee.getForkliftCertificate() << "\n";
    return out;
}