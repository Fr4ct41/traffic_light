#pragma once
#include <string>

enum class state {stop, ready_to_go, go, ready_to_stop};

class traffic_light
{

private:
    state light = state::stop;
public:
    void set_light(state light);
    state get_light();
};



