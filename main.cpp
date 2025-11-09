#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

// Declaring functions
void mainMenu(int &choice);
void cropManager();
void addCrop();
void viewCrops();

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

                break;

            // Delete crops
            case 4:

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

// Stores each crops data
struct cropData {
    int id;
    int area;
    std::string type;
    std::string plantingDate;
    std::string harvestDate;
};

// Stores all crops in memory
std::vector<cropData> crops;

void addCrop() {
    cropData crop;

    std::cout << "====== ADD CROP ======\n";
    std::cout << "Field ID: ";
    std::cin >> crop.id;
    std::cout << "Crop Type: ";
    std::cin >> crop.type;
    std::cout << "Area (hectares): ";
    std::cin >> crop.area;
    std::cout << "Planting Date (YYYY-MM-DD): ";
    std::cin >> crop.plantingDate;
    std::cout << "Harvesting Date (YYYY-MM-DD): ";
    std::cin >> crop.harvestDate;

    // Add to in memory Vector
    crops.push_back(crop);

    // Save to crops.csv file
    std::ofstream file("crops.csv", std::ios::app);
    if (file.is_open()) {
        file << crop.id << ","
             << crop.type << ","
             << crop.area << ","
             << crop.plantingDate << ","
             << crop.harvestDate << "\n";

        file.close();
        
        std::cout << "\nCrop added successfully!\n";
    } else {
        std::cerr << "\nError: Could not open crops.csv file.\n";
    }
}

void viewCrops() {
    std::ifstream file("crops.csv");
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open crops.csv for reading.\n";
        return;
    }


    std::string id, type, area, plantingDate, harvestDate;
    
    std::cout << "\n---------------------- CROP LIST ----------------------\n";
    std::cout << std::left
              << std::setw(5) << "ID"
              << std::setw(10) << "Type"
              << std::setw(10) << "Area"
              << std::setw(15) << "Planting"
              << std::setw(15) << "Harvesting" << "\n";
    std::cout << "-------------------------------------------------------\n";

    // Assigns data to each comma seperated variable
    while (file.good()) {
        std::getline(file, id, ',');
        std::getline(file, type, ',');
        std::getline(file, area, ',');
        std::getline(file, plantingDate, ',');
        std::getline(file, harvestDate, '\n');

        // Skip if line is empty
        if (id.empty()) {
            break;
        }

        // Display crop data
        std::cout << std::left
                  << std::setw(5) << id
                  << std::setw(10) << type
                  << std::setw(10) << (area + " ha")
                  << std::setw(15) << plantingDate
                  << std::setw(15) << harvestDate << "\n";
    }

    file.close();
}
