#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

int main() {
    unordered_map<string, string> passwordStorage; 

    string service, password;

    cout << "Enter the service name (e.g., Gmail, Facebook): ";
    cin >> service;
    cout << "Enter the password: ";
    cin >> password;

    passwordStorage[service] = password;

    cout << "Stored Password for " << service << ": " << passwordStorage[service] << endl;

    ofstream outFile("passwords.txt", ios::app); // Open in append mode
    if (outFile) {
        outFile << service << " " << password << endl;
        cout << "Password saved successfully!" << endl;
    } else {
        cout << "Error saving password!" << endl;
    }
    outFile.close();

    return 0;
}
