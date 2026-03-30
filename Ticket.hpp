#ifndef TICKET_HPP
#define TICKET_HPP

#include "Driver.hpp"
#include "Date.hpp"

#include <string>

class Ticket{

    private:

        Driver* driver;

        Date dateIssued;

        std::string charge;

    public:

        Driver* GetDriver() {

            return this->driver;

        }

        Date GetDate() {

            return this->dateIssued;

        }

        std::string GetCharge() {

            return this->charge;

        }

        void SetDriver(Driver* newDriver) {

            this->driver = newDriver;

        }

        void SetDate(Date newDate) {

            this->dateIssued = newDate;

        }

        void SetCharge(std::string newCharge) {

            this->charge = newCharge;

        }

};

#endif