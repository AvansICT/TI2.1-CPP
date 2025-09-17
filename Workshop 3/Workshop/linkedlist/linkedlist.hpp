#ifndef _LINKEDLIST_HPP_
#define _LINKEDLIST_HPP_

typedef struct node {
    int val;
    struct node* next;
} node_t;

class LinkedList {
private:
    node_t* head;

public:
    LinkedList();                  // Constructor
    ~LinkedList();                 // Destructor

    void append(int value);        // Voeg element toe aan einde
    void insertFront(int value);   // Voeg element toe aan begin
    void insertAt(int index, int value); // Voeg element toe op bepaalde index
    void remove(int value);        // Verwijder element
    void print() const;            // Print lijst
};

#endif
