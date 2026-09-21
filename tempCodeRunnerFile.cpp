#include <iostream>
#include <string>
#include <iomanip>

int main() {
    // -------------------------------------------------------------------------
    // PHASE 2: PART I — Inputs & Primitive Data Types
    // -------------------------------------------------------------------------
    std::string foodName;
    char itemCode;
    int itemQuantity;
    double unitPrice;
    char memberInput;
    bool isMember = false;
    
    // 1. Input Collection
    std::cout << "Enter food item name: ";
    std::getline(std::cin, foodName);

    std::cout << "Enter item code (single character): ";
    std::cin >> itemCode;

    std::cout << "Enter item quantity: ";
    std::cin >> itemQuantity;

    std::cout << "Enter unit price: $";
    std::cin >> unitPrice;

    std::cout << "Is customer a rewards member? (y/n): ";
    std::cin >> memberInput;

    if (memberInput == 'y' || memberInput == 'Y') {
        isMember = true;
    }

}