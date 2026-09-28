#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    // Variables for menu selection
    char menuChoice;
    char sizeChoice;
    string foodName = "";
    double unitPrice = 0.0;
    
    // Variables from Lab 4
    int quantity = 0;
    char isMember = 'n';
    double subtotal = 0.0;

    // 1. Display the formatted menu chart
    cout << left;
    cout << setw(20) << "Drink" 
         << setw(15) << "Small (s)" 
         << setw(15) << "Medium (m)" 
         << setw(15) << "Large (l)" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << setw(20) << "A. Fanta Strawberry" 
         << setw(15) << "2.50" 
         << setw(15) << "3.50" 
         << setw(15) << "4.50" << endl;
    cout << setw(20) << "B. Powerade" 
         << setw(15) << "5.00" 
         << setw(15) << "7.00" 
         << setw(15) << "9.00" << endl;
    cout << setw(20) << "C. Smoothie" 
         << setw(15) << "4.00" 
         << setw(15) << "5.50" 
         << setw(15) << "7.00" << endl;
    cout << endl;

    // 2. Ask user to select an option and size
    cout << "Enter the letter of your item choice (A, B, or C): ";
    cin >> menuChoice;
    menuChoice = toupper(menuChoice); // Normalize to uppercase

    cout << "Enter the size (s for Small, m for Medium, l for Large): ";
    cin >> sizeChoice;
    sizeChoice = tolower(sizeChoice); // Normalize to lowercase

    // 3. Use switch/if statements to determine foodName and unitPrice
    switch (menuChoice) {
        case 'A':
            foodName = "Fanta Strawberry";
            if (sizeChoice == 's') unitPrice = 2.50;
            else if (sizeChoice == 'm') unitPrice = 3.50;
            else if (sizeChoice == 'l') unitPrice = 4.50;
            break;
        case 'B':
            foodName = "Powerade";
            if (sizeChoice == 's') unitPrice = 5.00;
            else if (sizeChoice == 'm') unitPrice = 7.00;
            else if (sizeChoice == 'l') unitPrice = 9.00;
            break;
        case 'C':
            foodName = "Smoothie";
            if (sizeChoice == 's') unitPrice = 4.00;
            else if (sizeChoice == 'm') unitPrice = 5.50;
            else if (sizeChoice == 'l') unitPrice = 7.00;
            break;
        default:
            cout << "Invalid menu selection!" << endl;
            return 1; // Exit program if invalid
    }

    // 4. Ask for quantity and membership (adapted from Lab 4)
    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Are you a member? (y/n): ";
    cin >> isMember;

    // 5. Calculate subtotal and display summary
    subtotal = unitPrice * quantity;

    // Optional member discount logic if your Lab 4 had it
    // if (tolower(isMember) == 'y') { subtotal *= 0.90; } // example 10% discount

    cout << "\n--- Order Summary ---" << endl;
    cout << "Item: " << foodName << " (" << sizeChoice << ")" << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Unit Price: $" << fixed << setprecision(2) << unitPrice << endl;
    cout << "Subtotal: $" << subtotal << endl;

    return 0;
}