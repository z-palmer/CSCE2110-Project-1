#ifndef SEARCHDATABASE_HPP
#define SEARCHDATABASE_HPP

#include "Driver.hpp"

class SearchDatabase {

    private:
        struct Node {
            Driver* driver;
            Node* next;
        };

        Node** table;
        int capacity;

    public:

        SearchDatabase(int size = 100) {
            capacity = size;
            table = new Node*[capacity];
            for (int i = 0; i < capacity; ++i) {
                table[i] = nullptr;
            }
        }

        int hash(int key) {
            return key % capacity;
        }

        void insert(Driver* driver) {
            int index = hash(driver->getDl());
            Node* newNode = new Node;
            newNode->driver = driver;
            newNode->next = table[index];

            table[index] = newNode;
        }

        Driver* search(int dl) {
            int index = hash(dl);
            Node* current = table[index];
            while (current != nullptr) {
                if (current->driver->getDl() == dl) {
                    return current->driver;
                }
                current = current->next;
            }
            return nullptr; // Not found
        }

        void remove (int dl) {
            int index = hash(dl);
            Node* current = table[index];
            Node* prev = nullptr;

            while (current != nullptr) {
                if (current->driver->getDl() == dl) {
                    if (prev == nullptr) {
                        table[index] = current->next;
                    } else {
                        prev->next = current->next;
                    }
                    delete current;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }
};

#endif