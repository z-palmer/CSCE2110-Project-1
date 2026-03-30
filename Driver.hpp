#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "Address.hpp"
#include "Ticket.hpp"

class Driver {

    private:

        int dlNumber;

        int age;

        int experience;

        Address* frequentLocations;

        Address workArea;

        Ticket* tickets;

    public:

        int GetDL() {

            return this->dlNumber;

        }

        int GetAge() {

            return this->age;

        }

        int GetExperience() {

            return this->experience;

        }

        Ticket* GetTickets() {

            return this->tickets;

        }

        Address GetWork() {

            return this->workArea;

        }

        Address* GetFrequent() {

            return this->frequentLocations;

        }

        void SetDL(int newDL) {

            this->dlNumber = newDL;

        }

        void SetAge(int newAge) {

            this->age = newAge;

        }

        void SetExperience(int newExp) {

            this->experience = newExp;

        }

        void SetFrequent(Address* newFrequent) {

            this->frequentLocations = newFrequent;

        }

        void SetWork(Address newWork) {

            this->workArea = newWork;

        }

        void SetTickets(Ticket* newTickets) {

            this->tickets = newTickets;

        }

};

#endif