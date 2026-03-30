#ifndef INACTIVEDRIVERDATABASE_HPP
#define INACTIVEDRIVERDATABASE_HPP

#include <string>
#include <iostream>
#include <array>

#include "Driver.hpp"

struct Node {

    Driver driver;
    Node* next = nullptr;

};

class InactiveDatabase {

    private:

        Node** table;

        InactiveDatabase(int size) : capacity(size) {

            table = new Node*[size];

            for (int i = 0; i < size; ++i) {

                table[i] = new Node[1];

            }

        }

        ~InactiveDatabase() {

            for (int i = 0; i < capacity; ++i) {

                delete[] table[i];

            }

            delete[] table;

        }

        int space = 100;

        int capacity = 100;


    public:

        void display(Node driver) {

            std::cout << "DL number: " << driver.driver.GetDL() << std::endl;

            std::cout << "Age: " << driver.driver.GetAge() << std::endl;

            std::cout << "Experience: " << driver.driver.GetExperience() << std::endl;

            Address workArea = driver.driver.GetWork();
            
            std::cout << "Work Area: " << workArea.GetNumber() << " " << workArea.GetStreet() << ", " << workArea.GetCity() << ", " << workArea.GetState() << ", " << workArea.GetZip() << std::endl;

            Address* frequent = driver.driver.GetFrequent();

            int i = 0;

            std::cout << "Frequent Loacations: " << std::endl;

            while(i < 4) {

                std::cout << "Address " << i+1 << ": " << frequent[i].GetNumber() << " " << frequent[i].GetStreet() << ", " << frequent[i].GetCity() << ", " << frequent[i].GetState() << ", " << frequent[i].GetZip() << std::endl;
                ++i;

            }


        }

        void search() {

            int key;

            std::cout << "Enter DL Number: ";
            std::cin >> key;

            int index = hash(key);

            Node indexedDriver = *table[index];

            if(indexedDriver.driver.GetDL() == key) {

                display(indexedDriver);

            }
            else {

                Node currentNode = *table[index];

                while(currentNode.driver.GetDL() != key) {

                    currentNode = *currentNode.next;

                }

                display(currentNode);

            }

        }

    void insert(Driver newDriver) {

        int index = hash(newDriver.GetDL());

        Node newNode = {newDriver, nullptr}; 
        
        if(table[index] == nullptr) {

            table[index] = &newNode;

        }
        else {

            Node* currentNode = table[index];

            while(currentNode->next != nullptr) {

                currentNode = currentNode->next;

            }

           currentNode = &newNode;

        }
        
    }

        int hash(int key) {

            long long square = (long long) key * key;

            int middleDigits = (square / 100) % 100;

            std::string s = std::to_string(square);

            int mid = s.length() / 2;

            std::string res = s.substr(std::max(0, mid - 1), 2); 

            return std::stoi(res) % capacity;

        }


};

#endif