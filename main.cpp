#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "SearchDatabase.hpp"
#include "OrderedDatabase.hpp"
#include "InactiveDriverDatabase.hpp"
#include "Address.hpp"
#include "Date.hpp"
#include "Driver.hpp"
#include "Ticket.hpp"

using namespace std;

void load(SearchDatabase& searchDB, OrderedDatabase& orderedDB); //loads drivers from csv
void displayMenu(SearchDatabase& searchDB, OrderedDatabase& orderedDB, InactiveDatabase& inactiveDB); // main UI
void insertDriver(SearchDatabase& searchDB, OrderedDatabase& orderedDB); // prompt and inser driver
void searchDriver(SearchDatabase& searchDB); // search driver
void retrieveRecent(OrderedDatabase& orderedDB); // retrieve N most recent licenses
void retrieveOldest(OrderedDatabase& orderedDB); // retrieve N oldest licenses
void moveInactive(SearchDatabase& searchDB, OrderedDatabase& orderedDB, InactiveDatabase& inactiveDB); // move driver to inactive database  
void displayDrivers(OrderedDatabase& orderedDB); // display N drivers
void exitProgram(); // exit
void displayDriver(Driver* driver); // helper function to display driver details

int main() {
    SearchDatabase searchDB;
    OrderedDatabase orderedDB;
    InactiveDatabase inactiveDB;

    load(searchDB, orderedDB);
    displayMenu(searchDB, orderedDB, inactiveDB);

    return 0;
}

//load drivers from csv file and insert into search and ordered databases

void load(SearchDatabase& searchDB, OrderedDatabase& orderedDB) {
    ifstream inFile("drivers.csv");

    if (!inFile.is_open()) {
        cout << "Error: Could not open drivers.csv\n";
        return;
    }

    string line;
    getline(inFile, line); // skip header row

    while (getline(inFile, line)) {
        stringstream ss(line);

        string dlStr, ageStr, expStr;
        string street, city, state;
        string zipStr, numberStr;

        getline(ss, dlStr, ',');
        getline(ss, ageStr, ',');
        getline(ss, expStr, ',');
        getline(ss, street, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        getline(ss, zipStr, ',');
        getline(ss, numberStr, ',');

        Address work;
        work.SetStreet(street);
        work.SetCity(city);
        work.SetState(state);
        work.SetZip(stoi(zipStr));
        work.SetNumber(stoi(numberStr));

        Driver* newDriver = new Driver;
        newDriver->SetDL(stoi(dlStr));
        newDriver->SetAge(stoi(ageStr));
        newDriver->SetExperience(stoi(expStr));
        newDriver->SetWork(work);
        newDriver->SetFrequent(nullptr);
        newDriver->SetTickets(nullptr);

        searchDB.insert(newDriver);
        orderedDB.push(newDriver);
    }

    inFile.close();
    cout << "Data loaded successfully.\n";
}

//display menu and handle user input for various operations on the databases

void displayMenu(SearchDatabase& searchDB, OrderedDatabase& orderedDB, InactiveDatabase& inactiveDB) {
    bool keepRunning = true;

    while (keepRunning) {
        int choice;

        cout << "\nDriver Database Menu\n";
        cout << "1. Insert Driver\n";
        cout << "2. Search Driver\n";
        cout << "3. Retrieve Recent License\n";
        cout << "4. Retrieve Oldest License\n";
        cout << "5. Move Driver to Inactive\n";
        cout << "6. Display Drivers\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertDriver(searchDB, orderedDB);
                break;
            case 2:
                searchDriver(searchDB);
                break;
            case 3:
                retrieveRecent(orderedDB);
                break;
            case 4:
                retrieveOldest(orderedDB);
                break;
            case 5:
                moveInactive(searchDB, orderedDB, inactiveDB);
                break;
            case 6:
                displayDrivers(orderedDB);
                break;
            case 7:
                exitProgram();
                keepRunning = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        if (keepRunning) {
            char again;
            cout << "\nWould you like to perform another action? (Y/N): ";
            cin >> again;

            if (again == 'N' || again == 'n') {
                exitProgram();
                keepRunning = false;
            }
        }
    }
}

//function to insert a new driver into both the search and ordered databases

void insertDriver(SearchDatabase& searchDB, OrderedDatabase& orderedDB) {
    int dlNum, age, exp;
    string street, city, state;
    int zip, number;

    cout << "Enter driver's license number: ";
    cin >> dlNum;

    cout << "Enter driver's age: ";
    cin >> age;

    cout << "Enter years of experience: ";
    cin >> exp;

    cin.ignore();

    cout << "Enter work street: ";
    getline(cin, street);

    cout << "Enter work city: ";
    getline(cin, city);

    cout << "Enter work state: ";
    getline(cin, state);

    cout << "Enter work zip code: ";
    cin >> zip;

    cout << "Enter work street number: ";
    cin >> number;

    Address work;
    work.SetStreet(street);
    work.SetCity(city);
    work.SetState(state);
    work.SetZip(zip);
    work.SetNumber(number);

    Driver* newDriver = new Driver;
    newDriver->SetDL(dlNum);
    newDriver->SetAge(age);
    newDriver->SetExperience(exp);
    newDriver->SetWork(work);
    newDriver->SetFrequent(nullptr);
    newDriver->SetTickets(nullptr);

    searchDB.insert(newDriver);
    orderedDB.push(newDriver);

    cout << "Driver inserted successfully.\n";
}

//function to search for a driver based on county

void searchDriver(SearchDatabase& searchDB) {
    string criteria;

    cin.ignore();
    cout << "Enter search criteria (County): ";
    getline(cin, criteria);

    Driver* target = searchDB.search(criteria);

    if (target != nullptr) {
        displayDriver(target);
    } else {
        cout << "Driver not found.\n";
    }
}

//function to retrieve and display the most recent licenses from the ordered database

void retrieveRecent(OrderedDatabase& orderedDB) {
    int n;
    cout << "Enter number of recent licenses to retrieve: ";
    cin >> n;

    Driver* recentArr = new Driver[n];
    int actualCount = 0;

    for (int i = 0; i < n; i++) {
        try {
            recentArr[i] = orderedDB.popBack();
            actualCount++;
        } catch (const runtime_error& e) {
            cout << "\nNotice: No more drivers left in the database.\n";
            break;
        }
    }

    cout << "\nShowing " << actualCount << " most recent licenses:\n";
    for (int i = 0; i < actualCount; i++) {
        Driver* temp = &recentArr[i];
        displayDriver(temp);
        cout << endl;
    }

    delete[] recentArr;
}

//function to retrieve and display the oldest licenses from the ordered database

void retrieveOldest(OrderedDatabase& orderedDB) {
    int n;
    cout << "Enter number of oldest licenses to retrieve: ";
    cin >> n;

    Driver* oldestArr = new Driver[n];
    int actualCount = 0;

    for (int i = 0; i < n; i++) {
        try {
            oldestArr[i] = orderedDB.popFront();
            actualCount++;
        } catch (const runtime_error& e) {
            cout << "\nNotice: No more drivers left in the database.\n";
            break;
        }
    }

    cout << "\nShowing " << actualCount << " oldest licenses:\n";
    for (int i = 0; i < actualCount; i++) {
        Driver* temp = &oldestArr[i];
        displayDriver(temp);
        cout << endl;
    }

    delete[] oldestArr;
}

//function to move a driver from the search and ordered databases to the inactive database

void moveInactive(SearchDatabase& searchDB, OrderedDatabase& orderedDB, InactiveDatabase& inactiveDB) {
    string criteria;

    cin.ignore();
    cout << "Enter criteria for driver to move to inactive: ";
    getline(cin, criteria);

    Driver* target = searchDB.search(criteria);

    if (target != nullptr) {
        inactiveDB.insert(target);
        searchDB.makeInactive(criteria);
        orderedDB.makeInactive(criteria);
        cout << "Driver moved to inactive database.\n";
    } else {
        cout << "Driver not found.\n";
    }
}

//function to display a specified number of drivers from the ordered database

void displayDrivers(OrderedDatabase& orderedDB) {
    int n;
    cout << "How many entries to display? ";
    cin >> n;

    Node* current = orderedDB.first();
    int count = 0;

    cout << "\nDisplaying " << n << " drivers:\n";

    while (current != nullptr && count < n) {
        displayDriver(&(current->data));
        cout << endl;
        current = current->next;
        count++;
    }
}

//function to exit the program

void exitProgram() {
    cout << "Exiting program...\n";
}


void displayDriver(Driver* driver) {
    if (driver == nullptr) {
        cout << "Driver not found.\n";
        return;
    }

    cout << "DL Number: " << driver->GetDL() << endl;
    cout << "Age: " << driver->GetAge() << endl;
    cout << "Experience: " << driver->GetExperience() << endl;

    Address work = driver->GetWork();
    cout << "Work Street: " << work.GetStreet() << endl;
    cout << "Work City: " << work.GetCity() << endl;
    cout << "Work State: " << work.GetState() << endl;
    cout << "Work Zip: " << work.GetZip() << endl;
    cout << "Work Number: " << work.GetNumber() << endl;
}