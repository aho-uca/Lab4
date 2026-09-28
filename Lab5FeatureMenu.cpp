#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

int main() {
    // Variables for menu selection
    char menuChoice;
    char sizeChoice;
    string foodName = "";
    double unitPrice = 0.0;
    
    // Order inputs
    int quantity = 0;
    char memberInput = 'n';
    bool isMember = false;
    string cashierNotes = "";

    // 1. Display the formatted menu chart
    cout << left;
    cout << setw(20) << "Drink" 
         << setw(15) << "Small (s)" 
         << setw(15) << "Medium (m)" 
         << setw(15) << "Large (l)" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << setw(20) << "A. Fanta Strawberry" 
         << setw(15) << "$2.50" 
         << setw(15) << "$3.50" 
         << setw(15) << "$4.50" << endl;
    cout << setw(20) << "B. Powerade" 
         << setw(15) << "$5.00" 
         << setw(15) << "$7.00" 
         << setw(15) << "$9.00" << endl;
    cout << setw(20) << "C. Smoothie" 
         << setw(15) << "$4.00" 
         << setw(15) << "$5.50" 
         << setw(15) << "$7.00" << endl;
    cout << endl;

    // 2. Ask user to select an option and size
    cout << "Enter the letter of your item choice (A, B, or C): ";
    cin >> menuChoice;
    menuChoice = toupper(menuChoice); // Normalize to uppercase

    cout << "Enter the size (s for Small, m for Medium, l for Large): ";
    cin >> sizeChoice;
    sizeChoice = tolower(sizeChoice); // Normalize to lowercase

    // 3. Use switch statements to determine foodName and unitPrice
    switch (menuChoice) {
        case 'A':
            foodName = "Fanta Strawberry";
            if (sizeChoice == 's') unitPrice = 2.50;
            else if (sizeChoice == 'm') unitPrice = 3.50;
            else if (sizeChoice == 'l') unitPrice = 4.50;
            else unitPrice = 2.50;
            break;
        case 'B':
            foodName = "Powerade";
            if (sizeChoice == 's') unitPrice = 5.00;
            else if (sizeChoice == 'm') unitPrice = 7.00;
            else if (sizeChoice == 'l') unitPrice = 9.00;
            else unitPrice = 5.00;
            break;
        case 'C':
            foodName = "Smoothie";
            if (sizeChoice == 's') unitPrice = 4.00;
            else if (sizeChoice == 'm') unitPrice = 5.50;
            else if (sizeChoice == 'l') unitPrice = 7.00;
            else unitPrice = 4.00;
            break;
        default:
            cout << "Invalid menu selection! Defaulting to Fanta Strawberry Small.\n";
            foodName = "Fanta Strawberry";
            unitPrice = 2.50;
            sizeChoice = 's';
            break;
    }

    // 4. Ask for quantity and membership
    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Are you a member? (y/n): ";
    cin >> memberInput;

    if (memberInput == 'y' || memberInput == 'Y') {
        isMember = true;
    }

    // Clear input buffer for getline
    cin.ignore(10000, '\n');

    cout << "Enter cashier notes: ";
    getline(cin, cashierNotes);

    // -------------------------------------------------------------------------
    // Calculations: Subtotal, Discount & Multi-Tier Taxes
    // -------------------------------------------------------------------------
    double subtotal = quantity * unitPrice;
    double discountAmount = 0.0;

    if (isMember) {
        discountAmount = subtotal * 0.10; // 10% discount
    }

    double discountedSubtotal = subtotal - discountAmount;

    // Specific Tax Rates Breakdown
    double stateTaxRate = 0.065;       // Arkansas State Tax: 6.5%
    double countyTaxRate = 0.005;      // Faulkner County Tax: 0.5%
    double municipalTaxRate = 0.02125; // Conway Municipal Tax: 2.125%

    double stateTaxAmount = discountedSubtotal * stateTaxRate;
    double countyTaxAmount = discountedSubtotal * countyTaxRate;
    double municipalTaxAmount = discountedSubtotal * municipalTaxRate;

    double totalTaxAmount = stateTaxAmount + countyTaxAmount + municipalTaxAmount;
    double subtotalPlusTax = discountedSubtotal + totalTaxAmount;

    // -------------------------------------------------------------------------
    // TIP MENU LOGIC
    // -------------------------------------------------------------------------
    char tipChoice;
    double tipAmount = 0.0;

    double tip15 = discountedSubtotal * 0.15;
    double tip20 = discountedSubtotal * 0.20;
    double tip25 = discountedSubtotal * 0.25;

    cout << "\n========================================\n";
    cout << "               TIP MENU                 \n";
    cout << "========================================\n";
    cout << left << setw(20) << "Tip Selection" << right << setw(18) << "Amount" << "\n";
    cout << "----------------------------------------\n";
    cout << left << setw(20) << "A. 15%" << right << "$" << setw(17) << tip15 << "\n";
    cout << left << setw(20) << "B. 20%" << right << "$" << setw(17) << tip20 << "\n";
    cout << left << setw(20) << "C. 25%" << right << "$" << setw(17) << tip25 << "\n";
    cout << left << setw(20) << "D. Other Amount" << "\n";
    cout << "========================================\n";

    cout << "What tip do you choose? ";
    cin >> tipChoice;
    tipChoice = toupper(tipChoice);

    switch (tipChoice) {
        case 'A':
            tipAmount = tip15;
            break;
        case 'B':
            tipAmount = tip20;
            break;
        case 'C':
            tipAmount = tip25;
            break;
        case 'D':
            cout << "How much would you like to tip? $";
            cin >> tipAmount;
            break;
        default:
            cout << "Invalid tip choice. Defaulting to $0.00 tip.\n";
            tipAmount = 0.0;
            break;
    }

    double grandTotal = subtotalPlusTax + tipAmount;

    string sizeLabel = "";
    if (sizeChoice == 's') sizeLabel = "Small";
    else if (sizeChoice == 'm') sizeLabel = "Medium";
    else if (sizeChoice == 'l') sizeLabel = "Large";

    // -------------------------------------------------------------------------
    // Formatted Receipt & Tax Table Output
    // -------------------------------------------------------------------------
    cout << "\n========================================\n";
    cout << "            STORE RECEIPT               \n";
    cout << "========================================\n";

    cout << fixed << setprecision(2);

    cout << left  << setw(20) << "Item Name:"     << right << setw(18) << foodName << "\n";
    cout << left  << setw(20) << "Size:"          << right << setw(18) << sizeLabel << "\n";
    cout << left  << setw(20) << "Quantity:"      << right << setw(18) << quantity << "\n";
    cout << left  << setw(20) << "Unit Price:"    << right << "$" << setw(17) << unitPrice << "\n";
    cout << left  << setw(20) << "Subtotal:"      << right << "$" << setw(17) << subtotal << "\n";

    if (isMember) {
        cout << left  << setw(20) << "Member Discount (10%):" << right << "-$" << setw(16) << discountAmount << "\n";
    }

    // Sales Tax Breakdown Table
    cout << "\n--- SALES TAX BREAKDOWN ---\n";
    cout << left  << setw(22) << "Tax Name" << setw(10) << "Rate" << right << setw(6) << "Amount" << "\n";
    cout << "----------------------------------------\n";
    cout << left  << setw(22) << "Arkansas State" << setw(10) << "6.5%"  << right << "$" << setw(5) << stateTaxAmount << "\n";
    cout << left  << setw(22) << "Faulkner County"  << setw(10) << "0.5%"  << right << "$" << setw(5) << countyTaxAmount << "\n";
    cout << left  << setw(22) << "Conway Municipal" << setw(10) << "2.125%" << right << "$" << setw(5) << municipalTaxAmount << "\n";
    cout << "----------------------------------------\n";

    cout << left  << setw(20) << "Total Tax:"     << right << "$" << setw(17) << totalTaxAmount << "\n";
    cout << left  << setw(20) << "Tip:"           << right << "$" << setw(17) << tipAmount << "\n";
    cout << "----------------------------------------\n";
    cout << left  << setw(20) << "GRAND TOTAL:"   << right << "$" << setw(17) << grandTotal << "\n";
    cout << "========================================\n";

    // Inventory Audit Table
    cout << "\n--- INVENTORY AUDIT TABLE ---\n";
    cout << left 
              << setw(15) << "CHOICE" 
              << setw(15) << "QTY" 
              << setw(15) << "PRICE" 
              << right << setw(10) << "MEMBER?" << "\n";
    cout << "-------------------------------------------------------\n";

    string codeDisplay = string(1, menuChoice) + "-" + sizeChoice;
    cout << left 
              << setw(15) << codeDisplay 
              << setw(15) << quantity 
              << "$" << setw(14) << unitPrice 
              << right << setw(10) << (isMember ? "YES" : "NO") << "\n";

    cout << "\nCashier Notes: " << cashierNotes << "\n";

    return 0;
}
