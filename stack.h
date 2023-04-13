#ifndef STACK_H
#define STACK_H

struct Node {

    int   num;
    Node *next;
};

class Stack {

    private:
    Node *head;

    public:
    Stack();
    Stack(Stack const &other);
    ~Stack();
    void operator=(Stack const &other);
    void push(int value);
    int  pop();
    bool is_empty() const;
};

#endif