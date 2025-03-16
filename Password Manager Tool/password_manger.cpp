#include <iostream>
#include <unordered_map>
#include <fstream>
#include <conio.h>  // Required for _getch() on Windows

using namespace std;

void printMenu() {
    cout << "1. Add a new password" << endl;
    cout << "2. Retrieve a password" << endl;
    cout << "3. Exit" << endl;
}

void addPass() {
    string website, username, password;
    cout << "Enter website: ";
    cin >> website;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";

    char ch;
    while((ch = _getch()) != '\r'){
        if(ch == '\b'){
            cout<<"\b \b";
            password.pop_back();
        }else if(ch != '\b'){
            password.push_back(ch);
            cout<<"*";
        }
    }
    cout << endl;

    ofstream file("passwords.txt", ios::app);
    file << website << " " << username << " " << password << endl;
    file.close();
}


void retrievePass(){
    string website;
    cout<<"Enter website: ";
    cin>>website;
    ifstream file("passwords.txt");
    string line;
    while(getline(file,line)){
        if(line.find(website)!=string::npos){
            cout<<line<<endl;
            return;
        }
    }
    cout<<"Password not found"<<endl;
}

int main() {
    int choice;

    printMenu();
    cout<<"Enter your choice --> ";
    cin >> choice;

    switch (choice) {
        case 1:
            addPass();
            break;
        case 2:
            retrievePass();
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice" << endl;
    }
    return 0;
}
