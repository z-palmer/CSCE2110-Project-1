#ifndef ORDEREDDATABASE_HPP
#define ORDEREDDATABASE_HPP

#include "Driver.hpp"

using namespace std;

// =========================
// NODE STRUCTURE
// =========================
struct OrderedNode {
    Driver* data;
    OrderedNode* next;
    OrderedNode* prev;

    OrderedNode(Driver* d) {
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
    OrderedNode* head;
    OrderedNode* tail;

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
    void push(Driver* data) {
        OrderedNode* newNode = new OrderedNode(data);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // =========================
    // RETURN FIRST NODE
    // =========================
    OrderedNode* first() {
        return head;
    }


    // =========================
    // REMOVE OLDEST DRIVER (popFront)
    // =========================
    Driver* popFront() {
        if (head == nullptr) {
           return nullptr; // List is empty
        }

        OrderedNode* temp = head;
        Driver* d = temp->data;

        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
        return d;
    }

    // =========================
    // REMOVE MOST RECENT DRIVER (popBack)
    // =========================
    Driver* popBack() {
        if (tail == nullptr) {
            return nullptr; // List is empty
        }

        OrderedNode* temp = tail;
        Driver* d = temp->data;

        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
        return d;
    }

    void displayRecent(int n) {
        OrderedNode* current = tail;
        int count = 0;

        while (current != nullptr && count < n) {
            current->data->display();
            current = current->prev;
            count++;
        }
    }

    void displayOldest(int n) {
        OrderedNode* current = head;
        int count = 0;

        while (current != nullptr && count < n) {
            current->data->display();
            current = current->next;
            count++;
        }
    }

};

#endif