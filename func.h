#pragma once

#include <string>
#include <vector>

class Note {
public:
    std::string text;
    std::string password;

    Note(std::string& text, std::string& password): text(text), password(password) {};
    bool isProtect() const;
    bool checkPassword(std::string& Ipassword) const;

};


class Manager {
private:
    std::vector<Note> notes;
    std::string filename;

public:
    Manager(std::string& filename): filename(filename){};
    void addNote(std::string& text, std::string& password);
    void removeNote();
    void printNotes();

};