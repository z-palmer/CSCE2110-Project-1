#ifndef INACTIVEDRIVERDATABASE_HPP
#define INACTIVEDRIVERDATABASE_HPP

#include "string"

#include "Driver.hpp"

class InactiveDatabase {

    private:

        Driver* data;

        int space;

        int capacity;


    public:

        Driver* search() {



        }

        void insert(Driver newDriver) {



        }

        int hash(std::string key) {

            int A = 1;
            int B = 0;

            int i = 0;

            while(key[i] != '\0') {

                A += key[i] % 65521;
                B += A % 65521;
                ++i;

            }

            return (B << 16 | A);

        }


};

#endif