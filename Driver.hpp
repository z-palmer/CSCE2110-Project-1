#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "Date.hpp"
#include "Address.hpp"
#include "Ticket.hpp"
#include <string>
#include <iostream>
using namespace std;

// ================= BASE DRIVER =================
class Driver {
protected:
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
    Driver() { ticket = nullptr; }

    // Full constructor
    Driver(string n, int dl, int a, int exp, string work, string medical,
           Date dob_, Date licDate, Address wa)
        : name(n), dlNumber(dl), age(a), experience(exp),
          workType(work), medicalCondition(medical),
          dob(dob_), licenseDate(licDate), workArea(wa) {
        ticket = nullptr;
    }

    virtual ~Driver() { if(ticket) delete ticket; }

    // Display driver info
    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "DL Number: " << dlNumber << endl;
        cout << "Age: " << age << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Work Type: " << workType << endl;
        cout << "Medical Condition: " << medicalCondition << endl;
        cout << "DOB: " << dob.getDay() << "/" << dob.getMonth() 
             << "/" << dob.getYear() << endl;
        cout << "License Date: " << licenseDate.getDay() << "/" 
             << licenseDate.getMonth() << "/" << licenseDate.getYear() << endl;
        cout << "Work Area: " << workArea.getStreet() << ", " 
             << workArea.getCity() << ", " << workArea.getState() 
             << ", " << workArea.getCountry() << " " << workArea.getZip() << endl;
    }

    // Getters
    int getDL() const { return dlNumber; }
    int getAge() const { return age; }
    int getExperience() const { return experience; }
    string getWorkType() const { return workType; }
    string getMedicalCondition() const { return medicalCondition; }
    Date getLicenseDate() const { return licenseDate; }
};

// ================= AGE-BASED CLASSES =================
class YouthDriver : public Driver {
public:
    YouthDriver(string n, int dl, int a, int exp, string work, string medical,
                Date dob_, Date licDate, Address wa)
        : Driver(n, dl, a, exp, work, medical, dob_, licDate, wa) {}

    void display() const override {
        cout << "--- Youth Driver ---" << endl;
        Driver::display();
    }
};

class MiddleAgedDriver : public Driver {
public:
    MiddleAgedDriver(string n, int dl, int a, int exp, string work, string medical,
                     Date dob_, Date licDate, Address wa)
        : Driver(n, dl, a, exp, work, medical, dob_, licDate, wa) {}

    void display() const override {
        cout << "--- Middle-Aged Driver ---" << endl;
        Driver::display();
    }
};

class SeniorDriver : public Driver {
public:
    SeniorDriver(string n, int dl, int a, int exp, string work, string medical,
                 Date dob_, Date licDate, Address wa)
        : Driver(n, dl, a, exp, work, medical, dob_, licDate, wa) {}

    void display() const override {
        cout << "--- Senior Driver ---" << endl;
        Driver::display();
    }
};

// ================= WORK-BASED CLASSES =================
class StudentDriver : public Driver {
public:
    StudentDriver(string n, int dl, int a, int exp, string medical,
                  Date dob_, Date licDate, Address wa)
        : Driver(n, dl, a, exp, "Student", medical, dob_, licDate, wa) {}
};

class GovEmployeeDriver : public Driver {
public:
    GovEmployeeDriver(string n, int dl, int a, int exp, string medical,
                       Date dob_, Date licDate, Address wa)
        : Driver(n, dl, a, exp, "Government Employee", medical, dob_, licDate, wa) {}
};

class SelfEmployedDriver : public Driver {
public:
    SelfEmployedDriver(string n, int dl, int a, int exp, string medical,
                       Date dob_, Date licDate, Address wa)
        : Driver(n, dl, a, exp, "Self-Employed", medical, dob_, licDate, wa) {}
};

class BusinessOwnerDriver : public Driver {
public:
    BusinessOwnerDriver(string n, int dl, int a, int exp, string medical,
                        Date dob_, Date licDate, Address wa)
        : Driver(n, dl, a, exp, "Business Owner", medical, dob_, licDate, wa) {}
};

class PrivateSectorDriver : public Driver {
public:
    PrivateSectorDriver(string n, int dl, int a, int exp, string medical,
                        Date dob_, Date licDate, Address wa)
        : Driver(n, dl, a, exp, "Private Sector Employee", medical, dob_, licDate, wa) {}
};

// ================= EXPERIENCE-BASED CLASSES =================
class NewDriver : public Driver {
public:
    NewDriver(string n, int dl, int a, Date dob_, Date licDate, Address wa, string work, string medical)
        : Driver(n, dl, a, 0, work, medical, dob_, licDate, wa) {}
};

class ModerateDriver : public Driver {
public:
    ModerateDriver(string n, int dl, int a, int exp, Date dob_, Date licDate, Address wa, string work, string medical)
        : Driver(n, dl, a, exp, work, medical, dob_, licDate, wa) {}
};

class ExperiencedDriver : public Driver {
public:
    ExperiencedDriver(string n, int dl, int a, int exp, Date dob_, Date licDate, Address wa, string work, string medical)
        : Driver(n, dl, a, exp, work, medical, dob_, licDate, wa) {}
};

// ================= MEDICAL CONDITION CLASSES =================
class FitDriver : public Driver {
public:
    FitDriver(string n, int dl, int a, int exp, string work,
              Date dob_, Date licDate, Address wa)
        : Driver(n, dl, a, exp, work, "Fit", dob_, licDate, wa) {}
};

class VisionImpairedDriver : public Driver {
public:
    VisionImpairedDriver(string n, int dl, int a, int exp, string work,
                         Date dob_, Date licDate, Address wa)
        : Driver(n, dl, a, exp, work, "Vision Impaired", dob_, licDate, wa) {}
};

class UpperExtremityImpairedDriver : public Driver {
public:
    UpperExtremityImpairedDriver(string n, int dl, int a, int exp, string work,
                                 Date dob_, Date licDate, Address wa)
        : Driver(n, dl, a, exp, work, "Upper Extremity Impairment", dob_, licDate, wa) {}
};

class LocomotorDisabledDriver : public Driver {
public:
    LocomotorDisabledDriver(string n, int dl, int a, int exp, string work,
                            Date dob_, Date licDate, Address wa)
        : Driver(n, dl, a, exp, work, "Locomotor Disability", dob_, licDate, wa) {}
};

#endif