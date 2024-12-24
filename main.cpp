#include "func.h"
#include <iostream>
#include <string>

int main() {
    std::string filename = "notes.txt";
    Manager manager(filename);

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add note\n";
        std::cout << "2. Show notes\n";
        std::cout << "3. Remove note\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string text, password;
                std::cout << "Enter your note: ";
                std::getline(std::cin, text);
                std::cout << "Enter password if you want to protect note: ";
                std::getline(std::cin, password);
                manager.addNote(text, password);
                break;
            }
            case 2:
                manager.printNotes();
            break;
            case 3:
                manager.removeNote();
            break;
            case 4:
                std::cout << "Exiting\n";
            return 0;
            default:
                std::cout << "Unknown option\n";
        }
    }
    return 0;
}
