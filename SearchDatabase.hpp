#ifndef SEARCHDATABASE_HPP
#define SEARCHDATABASE_HPP

#include "string"

#include "Driver.hpp"

class SearchDatabase {

    private:
        Driver** data;
        int space;
        int capacity;

    public:
        SearchDatabase() {
            capacity = 100;
            space = 0;

            data = new Driver*[capacity];

            for (int i = 0; i < capacity; i++) {
                data[i] = nullptr;
            }
        }

        ~SearchDatabase() {
            delete[] data;
        }

        void insert(Driver* newDriver) {
            pushBack(newDriver);
        }

        void pushBack(Driver* newDriver) {
            std::string key = std::to_string(newDriver->GetDL());
            int index = hash(key) % capacity;

            if (data[index] == nullptr) {
                data[index] = newDriver;
                space++;
            }
        }

        void pushFront(Driver* newDriver) {
            std::string key = std::to_string(newDriver->GetDL());
            int index = hash(key) % capacity;

            data[index] = newDriver;
        }

        Driver* search(std::string key) {
            int index = hash(key) % capacity;

            if (data[index] != nullptr) {
                if (std::to_string(data[index]->GetDL()) == key) {
                    return data[index];
                }
            }

            return nullptr;
        }

        void makeInactive(std::string key) {
            int index = hash(key) % capacity;

            if (data[index] != nullptr) {
                if (std::to_string(data[index]->GetDL()) == key) {
                    data[index] = nullptr;
                    space--;
                }
            }
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