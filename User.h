#ifndef USER_H
#define USER_H

#include <string>

class User 
{
public:
    enum class State { FINISHED, WAITING, IN_SAFE_ZONE };

    std::string id;
    State state;
    float safe_zone_timer;

    User(const std::string& id, State state, float timer)
        : id(id), state(state), safe_zone_timer(timer) {}
};

#endif