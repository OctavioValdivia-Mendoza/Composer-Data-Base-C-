#include <fstream>
#include "LinkedList.h"
#include "Composer.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
    LinkedList<composer> composers;
    ifstream inputFile("composers.txt");
    if (!inputFile.is_open()) {
        cout << "Error: Unable to open file composers.txt" << endl;
        return 1;
    }
    string line;
    while (getline(inputFile, line)) {
        std::string name = line.substr(0, line.find(','));
        int yearOfDeath = stoi(line.substr(line.find(',') + 1));
        composer composer(name, yearOfDeath);
        composers.insert(composer);
    }
    inputFile.close();
    while (true) {
        cout << "\n";
        cout <<
            "Enter 's' to search, 'r' to remove, "
            "'d' to display, 'e' to exit: ";
        char choice;
        cin >> choice;
        if (choice == 's') {
            string name;
            cout << "Enter the name of the composer: ";
            cin.ignore();
            getline(cin, name);
            composer composer(name, 0);
            if (composers.find(composer)) {
                cout << "\n\t" << name << " is found in the list" << endl;
            }
            else {
                cout << "\n\t" << name << " was not found in the list" << endl;
            }
        }
        else if (choice == 'r') {
            cout << "Enter the name of the composer: ";
            string name;
            cin.ignore();
            getline(cin, name);
            composer composer(name, 0);
            if (composers.remove(composer)) {
                cout << "\n\t" << name << " was successfully removed" << endl;
            }
            else {
                cout << "\n\t" << name << " was not found in the list" << endl;
            }
        }

        else if (choice == 'd') {
            composers.printList();
        }

        else if (choice == 'e') {
            break;
        }

        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
} 