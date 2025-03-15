#include <iostream>
#include <unordered_map>
#include <fstream>
#include <conio.h>  // Required for _getch() on Windows

using namespace std;

int main() {
    unordered_map<string, string> passwordStorage;
    string service, password;

    cout << "Enter the service name (e.g., Gmail, Facebook): ";
    cin >> service;

    cout << "Enter the password: ";
    char ch;
    while ((ch = _getch()) != '\r') { // Read characters until Enter is pressed
        if (ch == '\b' && !password.empty()) { 
            // Handle backspace
            cout << "\b \b";  // Erase last '*'
            password.pop_back();
        } else if (ch != '\b') {
            password.push_back(ch);
            cout << '*';  // Print '*' instead of the actual character
        }
    }
    cout << endl;

    // Store in map
    passwordStorage[service] = password;

    // Write to file
    ofstream outFile("passwords.txt", ios::app);
    if (outFile) {
        outFile << service << " " << password << endl;
        cout << "Password saved successfully!" << endl;
    } else {
        cout << "Error saving password!" << endl;
    }
    outFile.close();

    return 0;
}
