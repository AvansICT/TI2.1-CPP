#include <iostream>
#include "LinkedList.hpp"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    node_t* current = head;
    while (current) {
        node_t* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void LinkedList::append(int value) {
    node_t* newNode = new node_t{ value, nullptr };

    if (!head) {
        head = newNode;
    }
    else {
        node_t* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::insertFront(int value) {
    node_t* newNode = new node_t{ value, head };
    head = newNode;
}

void LinkedList::remove(int value) {
    if (!head) return;

    // Speciaal geval: eerste node verwijderen
    if (head->val == value) {
        node_t* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Zoek verder in de lijst
    node_t* current = head;
    while (current->next && current->next->val != value) {
        current = current->next;
    }

    // Als gevonden: verwijderen
    if (current->next) {
        node_t* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

void LinkedList::insertAt(int index, int value) {
    if (index < 0) return; // negatieve index niet toegestaan
    // TODO
}


void LinkedList::print() const {
    node_t* temp = head;
    while (temp) {
        std::cout << temp->val << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}