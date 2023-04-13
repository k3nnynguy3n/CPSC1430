#include "queue.h"
#include <iostream>

int main() {

    Queue my_queue;
    int   choice = -1;
    int   value;

    while (choice != 0) {

        std::cout << std::endl << std::endl << "Enter 1 to enqueue, 2 to dequeue, 0 to exit: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to enqueue: ";
            std::cin >> value;
            my_queue.enqueue(value);
            std::cout << "Queue: ";
            my_queue.print();
            break;
        case 2:
            try {
                value = my_queue.dequeue();
                std::cout << "Dequeued value: " << value << std::endl;
                std::cout << "Queue: ";
                my_queue.print();
            } catch (std::runtime_error const &e) {
                throw e;
            }
            break;
        case 0:
            std::cout << "Exiting program" << std::endl;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }
    return 0;
}