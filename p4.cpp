// Kenny Nguyen
// Implementation of P4.CPP, the To Do List editor. This program allows the user to add, remove
// check, uncheck, raise, lower, elements of the list to help the user stay organized

#include "list.h"
#include <iostream>

// A program that allows its user to add, remove, edit, and check off elements on a to-do list.
// Pre: Program must be able to compile
// Post: The program allos the user to interactively manipulate the to do list until the user chooses to quit
int main() {

    int const ZERO  = 0;
    int const THREE = 3;
    bool      run   = true;

    ToDoList *list  = new ToDoList();

    while (run) {

        std::cout << std::endl;
        list->show();

        std::string input;
        std::getline(std::cin, input);

        // Checks the first char to see if it is a valid command and checks for the space
        if (input.size() == ZERO) {
            std::cout << "Nothing was entered, try again" << std::endl << std::endl;

        } else if (input == "Q") {
            delete list;
            return 0;

        } else if (input.size() < THREE) {
            std::cout << "No input found, try again" << std::endl << std::endl;

        } else if (input[1] != ' ') {
            std::cout << "Invalid input, try again" << std::endl << std::endl;

        } else {

            // Sets everything after the first two chars to a new string called text
            std::string text = input.substr(2);

            // Checks text and the case enter by the user to execute what the user would like
            switch (input[0]) {

            case '+': {
                list->add_entry(text);
                break;
            }

            case '>': {
                list->check(text);
                break;
            }

            case '<': {
                list->uncheck(text);
                break;
            }

            case '-': {
                list->remove_entry(text);
                break;
            }

            case '^': {
                list->raise(text);
                break;
            }

                // case 'v': {
                // list.lower(text);
                // break;
                //}
            }
        }
    }
    return 0;
}
