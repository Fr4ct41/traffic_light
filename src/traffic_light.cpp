#include "traffic_light.h"
using std::string;

void traffic_light::set_light(state light_color)
{
    this->light = light_color;
}

state traffic_light::get_light()
{
    return this->light;
}