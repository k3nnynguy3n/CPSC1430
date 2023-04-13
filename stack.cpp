#include "stack.h"
#include <iostream>
#include <stack>
#include <stdexcept>

// Default constructor, initializes the constructing instance to have no elements
// Pre: None
// Post: Creates an empty stack
Stack::Stack() {

    head = nullptr;
}

// Copy constructor, intializes the constructing instance with an independent copy of the inputs elements
// Pre: A stack must exist
// Post: Makes a copy of the list passed into the method
Stack::Stack(Stack const &other) {

    head  = nullptr;
    *this = other;
}

// Deconstructor, frees all dynamic memory used by the destructing instance
// Pre: An object of stack must exist
// Post: All allocated memory in the list is deallocated and deleted
Stack::~Stack() {

    Node *current = head;
    while (current != nullptr) {
        Node *temp = current;
        current    = current->next;
        delete temp;
    }
}

// Assignment operator for Stack, overwrites the contents of the instance with an indeprendent copy
// of the input's elements
// Pre: A list of type Stack must be passed in
// Post: Overwrites the stack and then creates a copy of stack
void Stack::operator=(Stack const &other) {

    while (head != nullptr) {
        pop();
    }

    Node *current  = other.head;
    Node *previous = nullptr;
    while (current != nullptr) {
        Node *temp = new Node;
        if (previous == nullptr) {
            head = temp;
        } else {
            previous->next = temp;
        }
        previous  = temp;
        current   = current->next;
        temp->num = current->num;
    }
}

// Adds the input value to the instance's collection of elements
// Pre: A value of type int must be inputted and passed in
// Post: Adds value to the top of the stack
void Stack::push(int value) {

    Node *temp = new Node;
    temp->num  = value;
    temp->next = head;
    head       = temp;
}

// Removes and returns whichever element in the instances collection which was most recently added
// Pre: There must be a linked list to with elements to be removed from
// Post: Removes and returns the top element
int Stack::pop() {

    if (head == nullptr) {
        throw std::runtime_error("There are no elements to remove");
    }

    int   value = head->num;
    Node *temp  = head;
    head        = head->next;
    delete temp;
    return value;
}

// Checks if the stack is empty
// Must be a stack to check if it is empty
// Returns the true if the head is nullptr
bool Stack::is_empty() const {
    return head == nullptr;
}