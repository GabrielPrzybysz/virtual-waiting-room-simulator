#include "Queue.h"
#include "User.h"

#include <stdexcept>

Queue::Queue(int size)
    : list_(new User*[size]), head_(0), tail_(0), count_(0), capacity_(size)
{
}

Queue::Queue(const Queue& other)
    : list_(new User*[other.capacity_]), head_(other.head_), tail_(other.tail_),
      count_(other.count_), capacity_(other.capacity_)
{
    copyFrom(other);
}

Queue& Queue::operator=(const Queue& other)
{
    if (this != &other) {
        delete[] list_;
        list_ = new User*[other.capacity_];
        head_ = other.head_;
        tail_ = other.tail_;
        count_ = other.count_;
        capacity_ = other.capacity_;
        copyFrom(other);
    }
    return *this;
}

Queue::~Queue()
{
    for (int i = 0; i < count_; i++) {
        delete list_[(head_ + i) % capacity_];
    }
    delete[] list_;
}

User* Queue::dequeue()
{
    if (count_ == 0) {
        throw std::out_of_range("Queue is empty");
    }
    User* user = list_[head_];
    head_ = (head_ + 1) % capacity_;
    count_--;
    return user;
}

void Queue::enqueue(User* user)
{
    if (count_ == capacity_) {
        throw std::out_of_range("Queue is full");
    }
    list_[tail_] = user;
    tail_ = (tail_ + 1) % capacity_;
    count_++;
}

User* Queue::peek()
{
    if (count_ == 0) {
        throw std::out_of_range("Queue is empty");
    }
    return list_[head_];
}

int Queue::size() const
{
    return count_;
}

void Queue::copyFrom(const Queue& other)
{
    for (int i = 0; i < other.count_; i++) {
        list_[(head_ + i) % capacity_] = new User(*other.list_[(other.head_ + i) % other.capacity_]);
    }
}