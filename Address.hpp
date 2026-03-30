#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include <string>

class Address {

    private:

        std::string street;

        std::string city;

        std::string state;

        int zipCode;

        int number;

    public:

        std::string GetStreet() {

            return this->street;

        }

        std::string GetCity() {

            return this->city;

        }

        std::string GetState() {

            return this->state;

        }

        int GetNumber() {

            return this->number;

        }

        int GetZip() {

            return this->zipCode;

        }

        void SetStreet(std::string newStreet) {

            this->street = newStreet;

        }

        void SetCity(std::string newCity) {

            this->city = newCity;

        }

        void SetNumber(int newNumber) {

            this->number = newNumber;

        }

        void SetZip(int newZip) {

            this->zipCode = newZip;

        }

        void SetState(std::string newState) {

            this->state = newState;

        }

};

#endif