#include <iostream>
#include "User.h"

std::string stateToString(User::State state) 
{
    switch (state) {
        case User::State::FINISHED:
            return "FINISHED";
        case User::State::WAITING:
            return "WAITING";
        case User::State::IN_SAFE_ZONE:
            return "IN_SAFE_ZONE";
        default:
            return "UNKNOWN";
    }
}


int main() {

    User* user = new User("gabriel", User::State::WAITING, 1000);

    user->state = User::State::FINISHED;

    std::cout << "O id da minha_instancia é: " << user->id << std::endl;
    std::cout << "O state da minha_instancia é: " << stateToString(user->state)  << std::endl;
    std::cout << "A altura da minha_instancia é: " << user->safe_zone_timer << std::endl;

    delete user;

    return 0;
}