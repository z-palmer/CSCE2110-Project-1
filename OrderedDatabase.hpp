#ifndef ORDEREDDATABASE_HPP
#define ORDEREDDATABASE_HPP

#include <iostream>
#include "Driver.hpp"

using namespace std;

// =========================
// NODE STRUCTURE
// =========================
struct Node {
    Driver data;
    Node* next;
    Node* prev;

    Node(Driver d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

// =========================
// ORDERED DATABASE CLASS
// =========================
class OrderedDatabase {
private:
    Node* head;
    Node* tail;

public:

    // =========================
    // CONSTRUCTOR
    // =========================
    OrderedDatabase() {
        head = nullptr;
        tail = nullptr;
    }

    // =========================
    // INSERT DRIVER (push)
    // =========================
    void push(Driver data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // =========================
    // RETURN FIRST NODE
    // =========================
    Node* first() {
        return head;
    }

    // =========================
    // RETURN LAST NODE
    // =========================
    Node* last() {
        return tail;
    }

    // =========================
    // REMOVE OLDEST DRIVER (popFront)
    // =========================
    Driver popFront() {
        if (head == nullptr) {
            throw runtime_error("List is empty");
        }

        Node* temp = head;
        Driver data = temp->data;

        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
        return data;
    }

    // =========================
    // REMOVE MOST RECENT DRIVER (popBack)
    // =========================
    Driver popBack() {
        if (tail == nullptr) {
            throw runtime_error("List is empty");
        }

        Node* temp = tail;
        Driver data = temp->data;

        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
        return data;
    }

    // =========================
    // REMOVE DRIVER BASED ON DATE (makeInactive)
    // =========================
    void makeInactive(Date targetDate) {
        Node* current = head;

        while (current != nullptr) {

            if (current->data.getDate() == targetDate) {

                Node* prevNode = current->prev;
                Node* nextNode = current->next;

                // Fix links
                if (prevNode != nullptr) {
                    prevNode->next = nextNode;
                } else {
                    head = nextNode;
                }

                if (nextNode != nullptr) {
                    nextNode->prev = prevNode;
                } else {
                    tail = prevNode;
                }

                delete current;

                cout << "Driver moved to inactive.\n";
                return;
            }

            current = current->next;
        }

        cout << "Driver not found.\n";
    }
};

#endif