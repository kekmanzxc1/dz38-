#include <iostream>
#include <fstream>
#include <string>

class Firma {
private:
    std::string name;
    std::string owner;
    std::string phone;
    std::string address;
    std::string activity;

public:
    Firma() {}

    void input() {
        std::cout << "Enter the name of the company: ";
        std::getline(std::cin, name);
        std::cout << "Enter the owner's name: ";
        std::getline(std::cin, owner);
        std::cout << "Enter your phone number: ";
        std::getline(std::cin, phone);
        std::cout << "Enter the address: ";
        std::getline(std::cin, address);
        std::cout << "Enter the type of activity: ";
        std::getline(std::cin, activity);
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file;
        file.open(filename, std::ios::app);

        if (file.is_open()) {
            file << "Company name: " << name << '\n';
            file << "Owner: " << owner << '\n';
            file << "Phone: " << phone << '\n';
            file << "Address: " << address << '\n';
            file << "Type of activity: " << activity << '\n';
            file << "----------------------------------------\n";
            file.close();
            std::cout << "Information saved successfully!\n";
        }
        else {
            std::cerr << "Error opening a file for writing!\n";
        }
    }
};

void showMenu() {
    std::cout << "===== Program menu =====\n";
    std::cout << "1. Add a new company\n";
    std::cout << "2. Exit the program\n";
    std::cout << "=========================\n";
    std::cout << "Select the option: ";
}

int main() {
    int choice;
    std::string filename = "firms.txt";

    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            Firma newFirma;
            newFirma.input();
            newFirma.saveToFile(filename);
        }
        else if (choice == 2) {
            std::cout << "End of the program\n";
        }
        else {
            std::cout << "Please try again\n";
        }
    } while (choice != 2);
}
