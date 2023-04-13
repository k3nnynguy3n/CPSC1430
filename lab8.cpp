// Kenny Nguyen
// lab8.cpp

#include <iostream>

// Node struct
struct Node {
    std::string name;
    Node       *next;
};

void create_alaphabet(Node *&head);
void print(Node *&head);
void delete_node(Node *&head);

// Create a linked list of nodes in static and dynamic storage,
// print the linked lists and then deallocates the dynamically allocated list
// Pre:
// Post: Creates a linked list of 26 of nodes, prints them, and then deallocates the list
int main() {

    Node *head       = nullptr;

    Node  d          = {"d", nullptr};
    Node  c          = {"c", &d};
    Node  b          = {"b", &c};
    Node  a          = {"a", &b};

    Node *stack_head = &a;

    std::cout << std::endl;

    print(stack_head);
    std::cout << std::endl;
    create_alaphabet(head);
    print(head);
    std::cout << std::endl;
    delete_node(head);

    std::cout << std::endl;

    return 0;
}

// Creates a linked list of 26 nodes in dynamic storage, which contains an alphabet from a to z in lowercase
// Pre: Node must be passed into the function
// Post: Creates 26 new nodes in dynamic storage
void create_alaphabet(Node *&head) {

    head = nullptr;

    for (char letter = 'z'; letter >= 'a'; letter--) {
        Node *temp = new Node;
        temp->name = letter;
        temp->next = head;
        head       = temp;
    }
}

// Uses a pointer to iterate through each list and prints its content
// Pre: Node must be passed into the function
// Post: Prints the nodes
void print(Node *&head) {

    for (Node *iter = head; iter != nullptr; iter = iter->next) {
        std::cout << iter->name;
    }
}

// Deallocates all the nodes that were dynamically allocated
// Pre: Node must be passed into the function
// Post: Deallocates the nodes using a for loop
void delete_node(Node *&head) {

    Node *current = head;

    while (current != nullptr) {
        Node *temp = current;
        current    = current->next;
        delete temp;
    }
}