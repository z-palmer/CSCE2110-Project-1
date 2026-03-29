#ifndef DRIVER_HPP
#define DRIVER_HPP  
#include <string>
#include <iostream>
using namespace std;

class Date {
    private: 
        int day;
        int month;
        int year;
    public:
        Date() : day(1), month(1), year(2000) {}
        Date(int d, int m, int y) : day(d), month(m), year(y) {}

        bool operator==(const Date& other) const {
            return day == other.day && month == other.month && year == other.year;
        } //compares two dates for equality

        bool operator<(const Date& other) const {
            if (year != other.year) return year < other.year;
            if (month != other.month) return month < other.month;
            return day < other.day;
        } //compares two dates for ordering

        string getDate () const {
            return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
        }//returns the date as a string in the format "day/month/year"
};

class Address { 
    private:
        string street;
        string city;
        string state;
        int zip;
    public:
        Address() {}
        Address(string s, string c, string st, int z) : street(s), city(c), state(st), zip(z) {}

        string getFullAddress() const {
            return street + ", " + city + ", " + state + " " + to_string(zip);
        } //returns the full address as a string
};

class Driver { 
    private: 
        string name;
        int age;
        string licenseNumber;
        Date dob;
        Date issueDate;
        Address address;
        string workCategory;
        string experienceLevel;
        string medicalCondition;

    public:
        Driver() {}
        Driver(string n, int a, string l, Date d, Date i, Address ad, string w, string e, string m) 
            : name(n), age(a), licenseNumber(l), dob(d), issueDate(i), address(ad), workCategory(w), experienceLevel(e), medicalCondition(m) {}

        string getID() const { return licenseNumber; } //returns the driver's license number as a unique identifier
        const Date& getDate() const { return issueDate; } //returns the issuance date of the driver's license
        string getAddress() const { return address.getFullAddress(); } //returns the driver's full address as a string

        void displayInfo() const {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "License Number: " << licenseNumber << endl;
            cout << "Date of Birth: " << dob.getDate() << endl;
            cout << "Issuance Date: " << issueDate.getDate() << endl;
            cout << "Address: " << address.getFullAddress() << endl;
            cout << "Work Category: " << workCategory << endl;
            cout << "Experience Level: " << experienceLevel << endl;
            cout << "Medical Condition: " << medicalCondition << endl;
        } //displays all information about the driver
};


#endif