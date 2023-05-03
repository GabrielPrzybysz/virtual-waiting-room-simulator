#include <iostream>
#include "Queue.h"

int main() 
{
    Queue q(5);

    User* u1 = new User("user1", User::State::WAITING, 3.0);
    User* u2 = new User("user2", User::State::IN_SAFE_ZONE, 2.0);
    User* u3 = new User("user3", User::State::FINISHED, 1.0);

    q.enqueue(u1);
    q.enqueue(u2);
    q.enqueue(u3);

    std::cout << "Size of queue: " << q.size() << std::endl;

    User* peeked = q.peek();
    std::cout << "Peeked user: " << peeked->id << std::endl;

    User* dequeued = q.dequeue();
    std::cout << "Dequeued user: " << dequeued->id << std::endl;

    std::cout << "Size of queue: " << q.size() << std::endl;

    q.enqueue(u1);
    q.enqueue(u2);
    q.enqueue(u3);

    std::cout << "Size of queue: " << q.size() << std::endl;

    User* dequeued2 = q.dequeue();
    std::cout << "Dequeued user: " << dequeued2->id << std::endl;

    std::cout << "Size of queue: " << q.size() << std::endl;

    getchar();

    return 0;
}