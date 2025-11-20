#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

// Declaring functions for Crop Manager
void mainMenu(int &choice);
void loadCrops();
void saveCrops();
void cropManager();
void addCrop();
void viewCrops();
void updateGrowthStage();
void deleteCrop();

// Livestock functions
void loadLivestock();
void saveLivestock();
void livestockManager();
void addLivestock();
void viewLivestock();
void updateLivestock();
void deleteLivestock();

void inventoryManager();
void loadInventory();
void saveInventory();
void addItem();
void updateItem();
void viewItem();


const int MAX = 50; // amount of rows

std::string fieldId[MAX] = {};
std::string crops[MAX] = {};
std::string fieldArea[MAX] = {};
std::string plantingDate[MAX] = {};
std::string harvestingDate[MAX] = {};
std::string growthStage[MAX] = {};

// Livestock Arrays
std::string animalId[MAX] = {};
std::string species[MAX] = {};
std::string age[MAX] = {};
std::string healthStatus[MAX] = {};
std::string lastCheckup[MAX] = {};


int main() {
    loadCrops();

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
            case 3: loadInventory();
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

void loadCrops() {
    std::string line;
    std::ifstream myfile("crops.csv");
    int index = 0;

    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            std::stringstream ss(line);

            std::getline(ss, fieldId[index], ',');
            std::getline(ss, crops[index], ',');
            std::getline(ss, fieldArea[index], ',');
            std::getline(ss, plantingDate[index], ',');
            std::getline(ss, harvestingDate[index], ',');
            std::getline(ss, growthStage[index], ',');

            index++;
        }
    }
    myfile.close();
}

void saveCrops() {
    std::ofstream myfile;
    myfile.open("crops.csv");

    for (int i = 0; i < MAX; i++) {
        if (fieldId[i] != "\0") {
            myfile << fieldId[i] + ","
                   << crops[i] + ","
                   << fieldArea[i] + ","
                   << plantingDate[i] + ","
                   << harvestingDate[i] + ","
                   << growthStage[i] + "\n";
        } 
        else {
            break;
        }
    }
    myfile.close();
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
                deleteCrop();
                break;

            // Exit to Main Menu
            case 5: 
                mainMenu(choice);
                break;

            default:
                std::cout << "Please select a valid option (1-5)";
                break;
        }
        
        saveCrops();
        std::cout << std::endl;
    } while (choice != 5);
}

void addCrop() {
    // Declare variables and apply character limit
    const int SIZE = 20;
    char id[SIZE];
    char crop[SIZE];
    char area[SIZE];
    char plant[SIZE];
    char harvest[SIZE];
    char stage[SIZE];

    std::cin.ignore(); // Clears input buffer

    // Take user input
    std::cout << "====== ADD CROP ======\n";
    std::cout << "Field ID: ";
    std::cin.getline(id, SIZE);
    std::cout << "Crop Type: ";
    std::cin.getline(crop, SIZE);
    std::cout << "Area (hectares): ";
    std::cin.getline(area, SIZE);
    std::cout << "Planting Date (YYYY-MM-DD): ";
    std::cin.getline(plant, SIZE);
    std::cout << "Harvesting Date (YYYY-MM-DD): ";
    std::cin.getline(harvest, SIZE);
    std::cout << "Growth Stage (Planting/Growing/Harvesting/Completed): ";
    std::cin.getline(stage, SIZE);

    // Adds data to empty row
    for (int i = 0; i < MAX; i++) {
        if (fieldId[i] == "\0") {
            fieldId[i] = id;
            crops[i] = crop;
            fieldArea[i] = area;
            plantingDate[i] = plant;
            harvestingDate[i] = harvest;
            growthStage[i] = stage;

            break;
        }
    }
}

void viewCrops() {
    int rows = 0;

    std::cout << "\n------------------------------ CROP LIST -----------------------------\n";
    std::cout << std::left
              << std::setw(5) << "ID"
              << std::setw(10) << "Type"
              << std::setw(10) << "Area"
              << std::setw(15) << "Planting"
              << std::setw(15) << "Harvesting"
              << std::setw(15) << "Growth Stage";
    std::cout << "\n----------------------------------------------------------------------\n";
    for (int i = 0; i < MAX; i++) { 
        if (fieldId[i] != "\0") {
            std::cout << std::left
                      << std::setw(5) << fieldId[i]
                      << std::setw(10) << crops[i]
                      << std::setw(10) << fieldArea[i]
                      << std::setw(15) << plantingDate[i]
                      << std::setw(15) << harvestingDate[i]
                      << std::setw(15) << growthStage[i] << "\n";
                      rows++;
        }
        else {
            break;
        }
    }
    if (rows == 0) {
        std::cout << "No records found!\n";
    }
    std::cout << "----------------------------------------------------------------------\n";
}

void updateGrowthStage() {
    char id[5];
    char newGrowthStage[50];
    bool found = false;

    
    std::cin.ignore();

    std::cout << "Enter Crop Field ID to update: ";
    std::cin.getline(id, 5);


    for (int i = 0; i < MAX; i++) {
        if (id == fieldId[i]) {
            std::cout << "Current Growth Stage: " << growthStage[i] << "\n";
            std::cout << "Enter New Growth Stage: ";
            std::cin.getline(newGrowthStage, 50);
            growthStage[i] = newGrowthStage;
            std::cout << "Successfully updated Growth Stage!";
            found = true;
        }
    }

    if (found == false) {
        std::cout << "Crop Field ID does not exist!";
    }
}

void deleteCrop() {
    char id[5];
    char answer;
    bool found = false;

    
    std::cin.ignore();

    std::cout << "Enter Crop Field ID to delete: ";
    std::cin.getline(id, 5);


    for (int i = 0; i < MAX; i++) {
        if (id == fieldId[i]) {
            std::cout << "\n----------------------------------------------------------------------\n";
            std::cout << std::left
                      << std::setw(5) << fieldId[i]
                      << std::setw(10) << crops[i]
                      << std::setw(10) << fieldArea[i]
                      << std::setw(15) << plantingDate[i]
                      << std::setw(15) << harvestingDate[i]
                      << std::setw(15) << growthStage[i];
            std::cout << "\n----------------------------------------------------------------------\n";
            std::cout << "Are you sure you want to delete this crop? (Y/N)\n>> ";
            std::cin >> answer;
            
            if (answer == 'Y' || answer == 'y') {
                fieldId[i] = "";
                crops[i] = "";
                fieldArea[i] = "";
                plantingDate[i] = "";
                harvestingDate[i] = "";
                growthStage[i] = "";

                std::cout << "Crop has been successfully removed!";
            }
            found = true;
        }
    }

    if (found == false) {
        std::cout << "Crop Field ID does not exist!";
    }
}


void loadLivestock() {
    std::string line;
    std::ifstream file("livestock.csv");
    int index = 0;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::stringstream ss(line);

            std::getline(ss, animalId[index], ',');
            std::getline(ss, species[index], ',');
            std::getline(ss, age[index], ',');
            std::getline(ss, healthStatus[index], ',');
            std::getline(ss, lastCheckup[index], ',');

            index++;
        }
    }
    file.close();
}

void saveLivestock() {
    std::ofstream file("livestock.csv");

    for (int i = 0; i < MAX; i++) {
        if (animalId[i] != "\0") {
            file << animalId[i] << ","
                 << species[i] << ","
                 << age[i] << ","
                 << healthStatus[i] << ","
                 << lastCheckup[i] << "\n";
        } else {
            break;
        }
    }
    file.close();
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
            case 3: updateLivestock(); break;
            case 4: deleteLivestock(); break;
            case 5: return;
            default: std::cout << "Please select a valid option (1-5)\n";
        }

        saveLivestock();
        std::cout << std::endl;

    } while (choice != 5);
}

void addLivestock() {
    const int SIZE = 30;
    char id[SIZE], sp[SIZE], a[SIZE], health[SIZE], checkup[SIZE];

    std::cin.ignore(); // important: clear leftover newline

    std::cout << "===== ADD LIVESTOCK =====\n";
    std::cout << "Animal ID: ";
    std::cin.getline(id, SIZE);

    std::cout << "Species (Cattle/Goat/Swine/etc.): ";
    std::cin.getline(sp, SIZE);

    std::cout << "Age (years): ";
    std::cin.getline(a, SIZE);

    std::cout << "Health Status: ";
    std::cin.getline(health, SIZE);

    std::cout << "Last Checkup Date (YYYY-MM-DD): ";
    std::cin.getline(checkup, SIZE);

    for (int i = 0; i < MAX; i++) {
        if (animalId[i] == "\0") {
            animalId[i] = id;
            species[i] = sp;
            age[i] = a;
            healthStatus[i] = health;
            lastCheckup[i] = checkup;
            break;
        }
    }

    std::cout << "Livestock successfully added!\n";
}

void viewLivestock() {
    int rows = 0;

    std::cout << "\n---------------------------- LIVESTOCK LIST ----------------------------\n";
    std::cout << std::left
              << std::setw(8) << "ID"
              << std::setw(15) << "Species"
              << std::setw(8) << "Age"
              << std::setw(20) << "Health Status"
              << std::setw(15) << "Last Checkup\n";
    std::cout << "------------------------------------------------------------------------\n";

    for (int i = 0; i < MAX; i++) {
        if (animalId[i] != "\0") {
            std::cout << std::left
                      << std::setw(8) << animalId[i]
                      << std::setw(15) << species[i]
                      << std::setw(8) << age[i]
                      << std::setw(20) << healthStatus[i]
                      << std::setw(15) << lastCheckup[i] << "\n";
            rows++;
        }
        else break;
    }

    if (rows == 0) {
        std::cout << "No livestock records found!\n";
    }

    std::cout << "------------------------------------------------------------------------\n";
}

void updateLivestock() {
    char id[10];
    char newHealth[50];
    char newCheckup[20];
    bool found = false;

    std::cin.ignore();

    std::cout << "Enter Animal ID to update: ";
    std::cin.getline(id, 10);

    for (int i = 0; i < MAX; i++) {
        if (animalId[i] == id) {
            std::cout << "Current Health: " << healthStatus[i] << "\n";
            std::cout << "New Health Status: ";
            std::cin.getline(newHealth, 50);

            std::cout << "New Last Checkup Date: ";
            std::cin.getline(newCheckup, 20);

            healthStatus[i] = newHealth;
            lastCheckup[i] = newCheckup;

            std::cout << "Livestock updated successfully!\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "Animal ID does not exist!\n";
    }
}

void deleteLivestock() {
    char id[10];
    char ans;
    bool found = false;

    std::cin.ignore();

    std::cout << "Enter Animal ID to delete: ";
    std::cin.getline(id, 10);

    for (int i = 0; i < MAX; i++) {
        if (animalId[i] == id) {

            // Show record
            std::cout << "\n--- RECORD FOUND ---\n";
            std::cout << "ID: " << animalId[i] << "\n";
            std::cout << "Species: " << species[i] << "\n";
            std::cout << "Age: " << age[i] << "\n";
            std::cout << "Health: " << healthStatus[i] << "\n";
            std::cout << "Checkup: " << lastCheckup[i] << "\n";

            std::cout << "Delete this livestock? (Y/N): ";
            std::cin >> ans;

            if (ans == 'Y' || ans == 'y') {
                animalId[i] = "";
                species[i] = "";
                age[i] = "";
                healthStatus[i] = "";
                lastCheckup[i] = "";

                std::cout << "Livestock removed successfully!\n";
            }
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Animal ID does not exist!\n";
    }
}


const int MAX_ITEMS = 100;

std::string itemName[MAX_ITEMS];
int itemQty[MAX_ITEMS];
double itemPrice[MAX_ITEMS];
int totalItems = 0;



    void inventoryManager(){ 
    int choice;

    do {
        std::cout << "\n===== INVENTORY MANAGER =====\n";
        std::cout << "1. Add Inventory Item\n";
        std::cout << "2. View All Items\n";
        std::cout << "3. Update Stock Quantity\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an Option: ";
        std::cin >> choice;

        if (std::cin.fail ()) {
            std::cin.clear ();
            std::cin.ignore(1000, '\n');
            std::cout << "\nInvalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: addItem ();
            break;

            case 2: viewItem ();
            break;

            case 3: updateItem ();
            break;

            case 4: std::cout << "Exiting program. Goodbye!\n";
            break;

            default: std::cout << "Invalid choice!\n";
        }

    } while (choice !=4);
}

void loadInventory() {
    std::ifstream file ("inventory.csv");
    
    if (!file.is_open())
        return;

    while (!file.eof() && totalItems < MAX_ITEMS) {
        std::getline(file, itemName[totalItems]);
        if (itemName[totalItems].empty())
        break;

        file >> itemQty[totalItems];
        file >> itemPrice[totalItems];
        file.ignore();

        totalItems++;
    }
    file.close();
}

void saveInventory() {
    std::ofstream file ("inventory.csv");
    for (int i = 0; i < totalItems; i++){
        file << itemName[i] << "\n";
        file << itemQty[i] << "\n";
        file << itemPrice[i] << "\n";
    }
    file.close();
}

void addItem() {
    if (totalItems >= MAX_ITEMS) {
        std::cout << "\nInventory is full! Cannot add more items.\n";
        return;
    }
    std::cin.ignore();

    std::cout << "\nEnter item name: ";
    std::getline(std::cin, itemName[totalItems]);

    std::cout << "Enter quantity: ";
    std:: cin >> itemQty[totalItems];

    std::cout << "Enter price per unit: ";
    std::cin >> itemPrice[totalItems];

    totalItems++;
    saveInventory();
    
    std::cout << "\nItem added successfully!\n";
}

void viewItem() {
    if (totalItems == 0) {
        std::cout << "\nNo items in inventory.\n";
        return;
    }

    double totalValue = 0;

    std::cout << "\n------------------------------ INVENTORY LIST -----------------------------\n";
    for (int i = 0; i < totalItems; i++) {
        std::cout << i + 1 << ". " << itemName[i] << " | Qty: " << itemQty[i] << " | Price: " << itemPrice[i] << "\n";

        totalValue += itemQty[i] * itemPrice[i];
    }
    std::cout << "\nTotal Inventory Value:  PHP" << totalValue << "\n";
}

void updateItem() {
    if (totalItems == 0) {
        std::cout << "\nNo items available to update.\n";
        return;
    }

    int itemNum;
    std::cout << "\nEnter item number to update (1-" << totalItems << "): ";
    std::cin >> itemNum;

    if (itemNum < 1 || itemNum > totalItems) {
        std::cout << "\nInvalid item number!\n";
        return;
    }

    int index = itemNum - 1;
    int change;

    std::cout << "\nCurrent quantity: " << itemQty[index] << "\n";
    std::cout << "Enter quantity to add (+) or subtract (-): ";
    std::cin >> change;

    if (change < 0 && -change > itemQty[index]) {
        std::cout << "\nError! Cannot subtract more than the current quantity (" << itemQty[index] << ").\n";
        return;
    }
    itemQty[index] += change;

    saveInventory();

    std::cout << "\nStock updated successfully!\n";
}