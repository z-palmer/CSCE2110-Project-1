#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include <string>
using namespace std;

class Address {

    private:

        string street;

        string city;

        string state;

        string country;

        int zipCode;

    public:

        Address () {}

        Address(string s, string c, string st, string co, int z) {
            street = s;
            city = c;
            state = st;
            country = co;
            zipCode = z;
        }


        string getStreet() const {

            return this->street;

        }

        string getCity() const {

            return this->city;

        }

        string getState() const {

            return this->state;

        }

        string getCountry() const {

            return this->country;

        }

        int getZip() const {

            return this->zipCode;

        }

};

#endif