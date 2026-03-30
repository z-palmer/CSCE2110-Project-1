#ifndef TICKET_HPP
#define TICKET_HPP


#include "Date.hpp"
#include "Address.hpp"
#include <string>
using namespace std;

class Ticket{

    private:

        Date issueDate;

        Address location;

        string charge;

    public:

        Ticket() {} 

        Ticket(Date d, Address a, string c) {
            issueDate = d;
            location = a;
            charge = c;
        }

        void display() {
            cout << "Issue Date: " << issueDate.getDay() << "/" << issueDate.getMonth() << "/" << issueDate.getYear() << endl;
            cout << "Location: " << location.getStreet() << ", " << location.getCity() << ", " << location.getState() << ", " << location.getCountry() << " " << location.getZip() << endl;
            cout << "Charge: " << charge << endl;
        }
};

#endif