#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "Date.hpp"
#include "Address.hpp"
#include "Ticket.hpp"
#include <string>
#include <iostream>
using namespace std;

class Driver {

private:
    string name;
    int dlNumber;
    int age;
    int experience;
    string workType;
    string medicalCondition;
    Date dob;
    Date licenseDate;
    Address workArea;
    Ticket* ticket;

public:
    // Default constructor
    Driver() {
        ticket = nullptr;
    }

    // Constructor with all fields
    Driver(string n, int dl, int a, int exp, string work, string medical,
           Date dob_, Date licDate, Address wa) 
        : name(n), dlNumber(dl), age(a), experience(exp), workType(work),
          medicalCondition(medical), dob(dob_), licenseDate(licDate), workArea(wa) {
        ticket = nullptr;
    }

    // Display driver info
    void display() const {
        cout << "Name: " << name << endl;
        cout << "DL Number: " << dlNumber << endl;
        cout << "Age: " << age << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Work Type: " << workType << endl;
        cout << "Medical Condition: " << medicalCondition << endl;
        cout << "DOB: " << dob.getDay() << "/" << dob.getMonth() << "/" << dob.getYear() << endl;
        cout << "License Date: " << licenseDate.getDay() << "/" 
             << licenseDate.getMonth() << "/" << licenseDate.getYear() << endl;
        cout << "Work Area: " << workArea.getStreet() << ", " << workArea.getCity() 
             << ", " << workArea.getState() << ", " << workArea.getCountry() 
             << " " << workArea.getZip() << endl;
    }

    int getDl() const { return dlNumber; }
    Date getLicenseDate() const { return licenseDate; }
};

class SeniorDriver : public Driver {
public:
    SeniorDriver(string n, int dl, int a, int exp, string work, string medical,
                 Date dob_, Date licDate, Address wa)
        : Driver(n, dl, a, exp, work, medical, dob_, licDate, wa) {}
};
#endif