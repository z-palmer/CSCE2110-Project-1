#ifndef SEARCHDATABASE_HPP
#define SEARCHDATABASE_HPP

#include "string"

#include "Driver.hpp"

class SearchDatabase {

    private:

        Driver* data;

        int space;

        int capacity;

    public:

        void insert() {}

        void pushBack() {}

        void pushFront() {}

        Driver* search() {}

        void makeInactive() {}

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