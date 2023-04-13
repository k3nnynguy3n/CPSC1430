#include "queue.h"
#include <iostream>
#include <ostream>
#include <stdexcept>

// Initializes the constructing instance to have no elements
// Pre: None
// Post: Sets the head and the tail of the linked list to  nullptr
Queue::Queue() {

    head = nullptr; // Initializes the head and the tail to nullptr
    tail = nullptr;
}

// Initializes the constructing instance with an independent copy of the inputs elements
// Pre: A linked list of type Queue must be passed into the method
// Post: Creates a copy of the passed in object
Queue::Queue(Queue const &other) {

    head          = nullptr;
    Node *current = other.head;
    while (current != nullptr) {
        enqueue(current->num);
        current = current->next;
    }
}

// Frees all dynamic memory used by the destructing instance
// Pre: There must be a dynamic allocated linked list
// Post: Deletes all memory of the object created
Queue::~Queue() {

    Node *iter = head;
    while (iter != nullptr) {
        dequeue();
    }
}

// Overwrites the contents of the instance with an independent copy of the inputs elements
// Pre: A list of a stack must be passed in
// Post: Overwrites the stack and then creates a copy of stack
void Queue::operator=(Queue const &other) {

    Node *iter = head;
    if (this != &other) {
        // Clear existing queue
        while (iter != nullptr) {
            dequeue();
        }
        // Copy elements from other
        Node *current = other.head;
        while (current != nullptr) {
            enqueue(current->num);
            current = current->next;
        }
    }
}

// Adds the input value to the instances collection of elements
// Pre: A value of type int needs to be passed into the method
// Post: Adds the value of type int to the head of the queue
void Queue::enqueue(int value) {

    Node *add = new Node; // Creates new node
    add->num  = value;    // Inserts passed in value into the node
    add->next = head;     // Sets the new node to head
    head      = add;
}

// Removes and returns whichever element in the instances collection which was least recently added
// Pre: There must be a linked list to remove from
// Post: Removes the element from the tail of the linked list
int Queue::dequeue() {

    if (head == nullptr) { // Checks if the head is empty, if so error
        throw std::runtime_error("There are no elements to remove");
    }

    int value;
    if (head->next == nullptr) { // If the node after the head is equal to nullptr
        value = head->num;       // Saves the value
        delete head;
        head = nullptr; // Sets head and tail to nullptr because there is only one value in the queue
        tail = nullptr;
    } else { // executes if there is more than one node in the queue
        Node *second_to_last = head;
        while (second_to_last->next->next != nullptr) { // Traverses until the second to last node is found
            second_to_last = second_to_last->next;
        }
        Node *last = second_to_last->next;
        value      = last->num; // Saves the value of the last node
        delete last;
        second_to_last->next = nullptr;        // Sets the second to last node to nullptr
        tail                 = second_to_last; // Sets the tail to the second to last node which is the new tail
    }

    return value;
}

// Prints the linked list
// Pre: There must be a present list to print
// Post: Prints the elements of the list
void Queue::print() {

    Node *current = head; // Iterates through the queue and prints each node in the queue
    while (current != nullptr) {
        std::cout << current->num << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Checks and returns true if the queue is empty or not
// Pre: Must be a queue to check
// Post: Returns true if the head and tail is nullptr
bool Queue::is_empty() const {
    return (head == nullptr && tail == nullptr);
}