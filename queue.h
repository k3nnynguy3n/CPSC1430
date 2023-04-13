#ifndef QUEUE_H
#define QUEUE_H
#include "stack.h"

class Queue {

    private:
    Node *head;
    Node *tail;

    public:
    Queue();
    Queue(Queue const &other);
    ~Queue();
    void operator=(Queue const &other);
    void print();
    void enqueue(int value);
    int  dequeue();
    bool is_empty() const;
};

#endif