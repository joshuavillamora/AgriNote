#include <iostream>

// Declaring functions
void mainMenu(int &choice);

int main() {
    int choice;

    do {
        mainMenu(choice);
        
        switch (choice) {
            // Crop Management
            case 1:
                std::cout << "This is Crop Management\n"; // temporary, feel free to remove
                break;

            // Livestock Management
            case 2:
                std::cout << "This is Livestock Management\n"; // temporary, feel free to remove
                break;

            // Inventory Management
            case 3:
                std::cout << "This is Inventory Management\n"; // temporary, feel free to remove
                break;

            // Financial Management
            case 4:
                std::cout << "This is Financial Management\n"; // temporary, feel free to remove
                break;
                
            // System Overview
            case 5:
                std::cout << "This is System Overview\n"; // temporary, feel free to remove
                break;

            // Exit Main Menu
            case 6:
                std::cout << "Thank you for using AgriNote!\n";
                break;

            default:
                std::cout << "Please select a valid option (1-6)\n";
                break;
        }
    } while (choice != 6);


    return 0;
}

// Functions
void mainMenu(int &choice) {
    std::cout << "==========================\n";
    std::cout << "     AGRINOTE MANAGER\n";
    std::cout << "  Farm Management System\n";
    std::cout << "==========================\n";
    std::cout << "1. Crop Management\n";
    std::cout << "2. Livestock Management\n";
    std::cout << "3. Inventory Management\n";
    std::cout << "4. Financial Management\n";
    std::cout << "5. System Overview\n";
    std::cout << "6. Exit\n";
    std::cout << "==========================\n";

    std::cin >> choice;
}

