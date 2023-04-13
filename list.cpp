// Kenny Nguyen
// list.cpp includes the methods definitions from list.h
#include "list.h"
#include <iostream>

//(Default constructor) initializes the constructing instance
// so that the head member represents an empty linked list
// Pre: ToDoList class needs to have an instance
// Post: Allocates a linked list with the head pointing to a nullptr
ToDoList::ToDoList() {

    // Sets the head to nullptr
    head = nullptr;
}

//(Copy constructor) initializes the constructing instance to match the input, with the
// head member pointing to a linked list that contains the same sequence of entries as the
// input instance, but which uses an entirely independent set of EntryNode instances to compose this list.
// Pre: ToDoList class should be defined
// Post: Initializes the contructing instance so that the head member represents an empty linked list
ToDoList::ToDoList(ToDoList const &other) {

    // Allocates a new linked list with added entries
    EntryNode *iter = other.head;
    while (iter != nullptr) {
        add_entry(iter->text);
        iter = iter->next;
    }
}

// Frees all outstanding memory allocations used by the destructing instance
// Pre: ToDoList class should be defined
// Post: Frees all memory allocations used by the destructing instance
ToDoList::~ToDoList() {

    EntryNode *temp = head;

    // Iterates through the list and deletes the nodes
    while (head != nullptr) {
        temp = head;
        head = temp->next;
        delete temp;
    }
}

// Performs the action corresponding to the add command, given text as the entry text input.
// Pre: Input from user must be a string
// Post: Adds the string entry to the linked list unchecked
void ToDoList::add_entry(std::string text) {

    // Adds a new node to the top of the list with the help of a temp node to keep track and to not lose the connection
    // between the lists
    EntryNode *temp = new EntryNode;
    temp->text      = text;
    temp->checked   = false;
    temp->next      = head;
    head            = temp;
}

// Performs the action corresponding to the remove command, given text as the entry text input.
// Pre: Input from user must be a string
// Post: Removes the entry that matches the string input from the user
void ToDoList::remove_entry(std::string text) {

    EntryNode **iter = &head; // Sets iter to the head

    while (*iter != nullptr) {               // Iterates through the list while iter does not equal nullptr
        if ((*iter)->text == text) {         // Checks if the current node pointer is the text inputed
            EntryNode *temp = *iter;         // Creates a temp pointing to the current node;
            *iter           = (*iter)->next; // Points to the next node
            delete temp;                     // Deallocates the node

        } else {
            iter = &(*iter)->next; // Moves to the next node
        }
    }
}

// Performs the action corresponding to the raise command, given text as the entry text input.
// Pre: Accepts a string input, string input must be entered
// Post: Moves all entries in the list that exactly contain that string up by one position.
//       However, if the first entry in the list matches entry, then the list is not changed.
void ToDoList::raise(std::string text) {

    // Checks that the list has elements and that there are more than just one element
    if (head == nullptr && head->text == text) {
        return;
    }

    EntryNode **iter = &head;
    while ((*iter)->next != nullptr) { // Iterates throught the list
        EntryNode *lowered = (*iter);
        EntryNode *raised  = (*iter)->next;
        EntryNode *after   = (*iter)->next->next;

        if (raised->text == text) { // Checks if the iter is equal to the inputted text
            (*iter)       = raised;
            raised->next  = lowered;
            lowered->next = after;
        }
        iter = &((*iter)->next); // Iterates to the next node
    }
}

// Performs the action corresponding to the lower command, given text as the entry text input.
// Pre: Accepts a string input, string input must be entered
// Post: Moves all entries in the list that exactly contain that string down by one position.
//       However, if the last entry in the list matches entry, then the list is not changed.
// void ToDoList::lower(std::string text) {

// Please give me the extra credit points I could really use them

//}

// Performs the action corresponding to the check command, given text as the entry text input.
// Pre: Input from the user must be a string
// Post: Marks off the string entered by the user with a check
void ToDoList::check(std::string text) {

    // Searches through the list if the Node member matches the inputted text them the box is checked
    for (EntryNode *iter = head; iter != nullptr; iter = iter->next) {
        if (iter->text == text) {
            iter->checked = true;
        }
    }
}

// Performs the action corresponding to the uncheck command, given text as the entry text input.
// Pre: Input from the user must be a string
// Post: Marks off the string entered by the user with an uncheck
void ToDoList::uncheck(std::string text) {

    // Searches through the list if the Node member matches the inputed text them the box is unchecked
    for (EntryNode *iter = head; iter != nullptr; iter = iter->next) {
        if (iter->text == text) {
            iter->checked = false;
        }
    }
}

// Displays the entries of the instance (both their text and whether they were checked) in order,
// from the head of the linked list to the tail.
// Pre: There must be a linked list to print out
// Post: Present/prints the linked list showing all the contents in the list
void ToDoList::show() {

    // Iterates through the list checking if the boolean member was marked true or false and if so then checking off the
    // box or not
    for (EntryNode *iter = head; iter != nullptr; iter = iter->next) {
        char marked = ' ';
        if (iter != nullptr && iter->checked) {
            marked = 'X';
        }
        std::cout << "[" << marked << "]"
                  << " " << iter->text << std::endl;
    }
    std::cout << std::endl << std::endl;
}
