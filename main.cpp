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
void deleteCrops();

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
    std::cout << "Growth Stage (Planting/Growing/Harvesting/Completed): ";
    std::cin >> crop.growthStage;

    // Add to in memory Vector
    crops.push_back(crop);

    // Save to crops.csv file
    std::ofstream file("crops.csv", std::ios::app);
    if (file.is_open()) {
        file << crop.id << ","
             << crop.type << ","
             << crop.area << ","
             << crop.plantingDate << ","
             << crop.harvestDate << ","
             << crop.growthStage << "\n";

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

    std::string id, type, area, plantingDate, harvestDate, growthStage;
    
    std::cout << "\n------------------------------ CROP LIST -----------------------------\n";
    std::cout << std::left
              << std::setw(5) << "ID"
              << std::setw(10) << "Type"
              << std::setw(10) << "Area"
              << std::setw(15) << "Planting"
              << std::setw(15) << "Harvesting"
              << std::setw(15) << "Growth Stage";
    std::cout << "\n----------------------------------------------------------------------\n";

    // Assigns data to each comma seperated variable
    while (file.good()) {
        std::getline(file, id, ',');
        std::getline(file, type, ',');
        std::getline(file, area, ',');
        std::getline(file, plantingDate, ',');
        std::getline(file, harvestDate, ',');
        std::getline(file, growthStage, '\n');

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
                  << std::setw(15) << harvestDate 
                  << std::setw(15) << growthStage << "\n";
    }

    file.close();
}

void updateGrowthStage() {
    std::vector<cropData> crops;
    cropData crop;

    std::ifstream file("crops.csv");

    std::string id, type, area, plantingDate, harvestDate, growthStage;
    int selectedId;
    bool found = false;
    
    while (file.good()) {
        std::getline(file, id, ',');
        std::getline(file, type, ',');
        std::getline(file, area, ',');
        std::getline(file, plantingDate, ',');
        std::getline(file, harvestDate, ',');
        std::getline(file, growthStage, '\n');

        if (id.empty()) continue; // skip empty lines
        
        crop.id = std::stoi(id);
        crop.type = type;
        crop.area = std::stoi(area);
        crop.plantingDate = plantingDate;
        crop.harvestDate = harvestDate;
        crop.growthStage = growthStage;

        crops.push_back(crop);
    }
    file.close();
    
    std::cout << "\n===== UPDATING GROWTH STAGE =====\n";
    std::cout << "Enter a Crop Field ID: ";
    std::cin >> selectedId;

    for (auto &tempCrop : crops) {
        if (tempCrop.id == selectedId) {
            found = true;
            std::cout << "Current Growth Stage: " << tempCrop.growthStage << "\n";
            std::cout << "Enter new Growth Stage (Planting/Growing/Harvesting/Completed): ";
            std::cin >> tempCrop.growthStage;
            break;
        }
    }

    if (!found) {
        std::cout << "\nCrop with ID " << selectedId << " not found.\n";
        return;
    }

    // Overwrite CSV with updated data
    std::ofstream outFile("crops.csv", std::ios::trunc); // clear file first

    for (auto &tempCrop : crops) {
        outFile << tempCrop.id << ","
             << tempCrop.type << ","
             << tempCrop.area << ","
             << tempCrop.plantingDate << ","
             << tempCrop.harvestDate << ","
             << tempCrop.growthStage << "\n";
    }

    outFile.close();

    std::cout << "\nGrowth stage updated successfully!\n";
}

void deleteCrops() {
    std::vector<cropData> crops;
    cropData crop;

    std::ifstream file("crops.csv");

    std::string id, type, area, plantingDate, harvestDate, growthStage;
    int selectedId;
    bool found = false;
    char answer;
    char blank = ' ';
    
    while (file.good()) {
        std::getline(file, id, ',');
        std::getline(file, type, ',');
        std::getline(file, area, ',');
        std::getline(file, plantingDate, ',');
        std::getline(file, harvestDate, ',');
        std::getline(file, growthStage, '\n');

        if (id.empty()) continue; // skip empty lines
        
        crop.id = std::stoi(id);
        crop.type = type;
        crop.area = std::stoi(area);
        crop.plantingDate = plantingDate;
        crop.harvestDate = harvestDate;
        crop.growthStage = growthStage;

        crops.push_back(crop);
    }
    file.close();
    
    std::cout << "\n===== DELETE CROP =====\n";
    std::cout << "Enter a Crop Field ID: ";
    std::cin >> selectedId;

    for (auto &tempCrop : crops) {
        if (tempCrop.id == selectedId) {
            found = true;
            std::cout << "\n----------------------------------------------------------------------\n";
            std::cout << std::left
                    << std::setw(5) << crop.id
                    << std::setw(10) << crop.type
                    << std::setw(10) << (crop.area + " ha")
                    << std::setw(15) << crop.plantingDate
                    << std::setw(15) << crop.harvestDate 
                    << std::setw(15) << crop.growthStage << "\n";
            std::cout << "----------------------------------------------------------------------\n";
            std::cout << "Are you sure you want to delete this crop? (Y/N) ";
            std::cin >> answer;
            if (answer == 'Y' || answer == 'y') {     
                crop.id = blank;
                crop.type = blank;
                crop.area = blank;
                crop.plantingDate = blank;
                crop.harvestDate = blank;
                crop.growthStage = blank;   
            }
            break;
        }
    }  
}