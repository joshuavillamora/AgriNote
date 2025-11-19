#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// Declaring functions
void mainMenu(int &choice);
void cropManager();
void addCrop();
void viewCrops();
void updateGrowthStage();
void deleteCrop();

//Declaring of fucntions for Livestock module
void livestockManager();
void addLivestock();
void viewLivestock();
void updateLivestock();
void deleteLivestock();

int main() {
    int choice;

    do {
        mainMenu(choice);
        
        switch (choice) {
            // Crop Management
            case 1:
                cropManager();
                break;

            // Livestock Management
            case 2: livestockManager();
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
    std::cout << "Choice: ";
    std::cin >> choice;
    std::cout << std::endl;
}

void cropManager() {
    int choice;

    do {
        std::cout << "===== CROP MANAGER =====\n";
        std::cout << "1. Add New Crop\n";
        std::cout << "2. View All Crops\n";
        std::cout << "3. Update Growth Stage\n";
        std::cout << "4. Delete Harvested Crop\n";
        std::cout << "5. Back to Main Menu\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            // Add crop
            case 1:
                addCrop();
                break;

            // View crops
            case 2:
                viewCrops();
                break;

            // Update growth stages
            case 3:
                updateGrowthStage();
                break;

            // Delete crops
            case 4:
                deleteCrops();
                break;

            // Exit to Main Menu
            case 5: 
                mainMenu(choice);
                break;

            default:
                std::cout << "Please select a valid option (1-5)";
                break;
        }

        std::cout << std::endl;
    } while (choice != 5);
}

void addCrop() {
    std::cout << "====== ADD CROP ======\n";
    std::cout << "Field ID: ";
    std::cout << "Crop Type: ";
    std::cout << "Area (hectares): ";
    std::cout << "Planting Date (YYYY-MM-DD): ";
    std::cout << "Harvesting Date (YYYY-MM-DD): ";
    std::cout << "Growth Stage (Planting/Growing/Harvesting/Completed): ";
}

void viewCrops() {
    std::cout << "\n------------------------------ CROP LIST -----------------------------\n";
    std::cout << std::left
              << std::setw(5) << "ID"
              << std::setw(10) << "Type"
              << std::setw(10) << "Area"
              << std::setw(15) << "Planting"
              << std::setw(15) << "Harvesting"
              << std::setw(15) << "Growth Stage";
    std::cout << "\n----------------------------------------------------------------------\n";
}

void updateGrowthStage() {
    
}

void deleteCrop() {

}

void livestockManager() {
    int choice;
    do {
        std::cout << "===== LIVESTOCK MANAGER =====\n";
        std::cout << "1. Add New Livestock\n";
        std::cout << "2. View All Livestock\n";
        std::cout << "3. Update Health Status\n";
        std::cout << "4. Delete Livestock Record\n";
        std::cout << "5. Back to Main Menu\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: addLivestock(); break;
            case 2: viewLivestock(); break;
            case 3: deleteLivestock(); break;
            case 4: updateGrowthStage(); break;
            case 5: mainMenu(choice); break;
            default: std::cout << "Please select a valid option (1-5)\n"; break;

        }

        std::cout <<std::endl;
    } while (choice !=5);
}

void addLivestock() {
    std::cout << "===== ADD LIVESTOCK =====\n";
    std::cout << "Animal ID: ";
    std::cout << "Species (Cattle/Poultry/Swine/Goat/etc.): ";
    std::cout << "Age (years): ";
    std::cout << "Health Status (Healthy?Sick/Undertreatment): ";
    std::cout << "Last Checkup Date (YYYY-MM-DD): ";
}

void viewLivestock() {
     std::cout << "\n------------------------------ LIVESTOCK LIST -----------------------------\n";
    std::cout << std::left
              << std::setw(6) << "ID"
              << std::setw(12) << "species"
              << std::setw(8) << "Age"
              << std::setw(18) << "Health Status"
              << std::setw(15) << "Last Checkup" << "\n";
    std::cout << "\n----------------------------------------------------------------------\n";
}
 

void updateLivestockHealth() {

}



void deleteLivestock() {
    
}