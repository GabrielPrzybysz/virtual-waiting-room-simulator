#ifndef QUEUE_H
#define QUEUE_H

#include "User.h"

class Queue 
{
public:
    Queue(int size);
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    ~Queue();

    User* dequeue();
    void enqueue(User* user);
    User* peek();
    int size() const;

private:
    User** list_;

    int head_;
    int tail_;

    int count_;
    int capacity_;

    void copyFrom(const Queue& other);
};

#endif