#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "SearchDatabase.hpp"
#include "OrderedDatabase.hpp"
#include "InactiveDriverDatabase.hpp"

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

    getline(inFile, line);

    while (getline(inFile, line)) {
        stringstream ss(line);

        string name, street, city, state, county;
        string dobMonthStr, dobDayStr, dobYearStr;
        string dlNumStr, expStr;

        getline(ss, name, ',');
        getline(ss, street, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        getline(ss, county, ',');
        getline(ss, dobMonthStr, ',');
        getline(ss, dobDayStr, ',');
        getline(ss, dobYearStr, ',');
        getline(ss, dlNumStr, ',');
        getline(ss, expStr, ',');

        int dobMonth = stoi(dobMonthStr);
        int dobDay = stoi(dobDayStr);
        int dobYear = stoi(dobYearStr);
        int dlNum = stoi(dlNumStr);
        int exp = stoi(expStr);

        Address* addr = new Address(street, city, state, county);
        Date* dob = new Date(dobMonth, dobDay, dobYear);

        Driver* newDriver = new Driver(name, addr, dob, dlNum, exp);

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
    string name, street, city, state, county;
    int month, day, year;
    int dlNum, exp;

    cin.ignore();

    cout << "Enter driver name: ";
    getline(cin, name);

    cout << "Enter street: ";
    getline(cin, street);

    cout << "Enter city: ";
    getline(cin, city);

    cout << "Enter state: ";
    getline(cin, state);

    cout << "Enter county: ";
    getline(cin, county);

    cout << "Enter birth month: ";
    cin >> month;

    cout << "Enter birth day: ";
    cin >> day;

    cout << "Enter birth year: ";
    cin >> year;

    cout << "Enter license number: ";
    cin >> dlNum;

    cout << "Enter years of driving experience: ";
    cin >> exp;

    Address* addr = new Address(street, city, state, county);
    Date* dob = new Date(month, day, year);
    Driver* newDriver = new Driver(name, addr, dob, dlNum, exp);

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
        target->display();
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
        recentArr[i].display();
        cout << "--------------------------\n";
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
        oldestArr[i].display();
        cout << "--------------------------\n";
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
        current->data->display();
        cout << "--------------------------\n";
        current = current->next;
        count++;
    }
}

//function to exit the program

void exitProgram() {
    cout << "Exiting program...\n";
}