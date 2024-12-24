#include "func.h"

#include <iostream>
#include <fstream>

bool Note::isProtect() const {
    return password.size() > 0;
}


bool Note::checkPassword(std::string& Ipassword) const {
    return Ipassword == password;
}


void Manager::addNote(std::string& text, std::string& password) {
    Note newNote(text, password);
    notes.push_back(newNote);
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << newNote.text << '\n' << newNote.password << '\n';
        file.close();
    } else {
        std::cout << "Error open file\n"<<std::endl;
    }
}

void Manager::removeNote() {
    if (notes.empty()) {
        std::cout << "No notes\n";
        return;
    }


    for (size_t i = 0; i < notes.size(); ++i) {
        std::cout << i << ": " << (notes[i].isProtect() ? "**** <Protected>" : notes[i].text) << '\n';
    }

    std::cout << "Enter index to remove note: ";
    int index;
    std::cin >> index;

    if (index >= 0 && index < static_cast<int>(notes.size())) {
        notes.erase(notes.begin() + index);


        std::ofstream file(filename);
        if (file.is_open()) {
            for (auto& note : notes) {
                file << note.text << '\n' << note.password << '\n';
            }
            file.close();
        } else {
            std::cout << "Error open file\n";
        }

        std::cout << "Note removed\n";
    } else {
        std::cout << "Invalid index\n";
    }
}


void Manager::printNotes() {
    notes.clear();
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string text, password;
        while (std::getline(file, text) && std::getline(file, password)) {
            Note loadedNote(text, password);
            notes.push_back(loadedNote);
        }
        file.close();
    } else {
        std::cout << "Error open file\n"<<std::endl;
    }


    for (size_t i = 0; i < notes.size(); ++i) {
        if (notes[i].isProtect()) {
            std::cout << i << ": **** <Protected>\n" << std::endl;
        } else {
            std::cout << i << ": " << notes[i].text << '\n' << std::endl;
        }
    }

    std::cout << "\nEnter index of protected note (-1 to exit):  ";
    int index;
    std::cin >> index;

    if (index >= 0 && index < static_cast<int>(notes.size())) {
        if (notes[index].isProtect()) {
            std::string inputPassword;
            std::cout << "Enter password:  ";
            std::cin.ignore();
            std::getline(std::cin, inputPassword);

            if (notes[index].checkPassword(inputPassword)) {
                std::cout << "Text: " << notes[index].text << '\n';
            } else {
                std::cout << "Incorrect password\n";
            }
        } else {
            std::cout << "This note does not have a password\n";
        }
    } else if (index != -1) {
        std::cout << "Incorrect index\n";
    }
}


