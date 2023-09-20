#include <iostream>
#include "traffic_light.h"

using std::cout;

std::string red_string(std::string str);
std::string yellow_string(std::string str);
std::string green_string(std::string str);
std::string horisontal_tl(traffic_light* tl);
std::string vertical_tl(traffic_light* tl);


void print_road(traffic_light* tl1, traffic_light* tl2, traffic_light* tl3)
{
    cout << "        " << horisontal_tl(tl1) << "\n";
    cout << "= = = ## = = =\n";
    cout << "= = = ## = = =\n";
    cout << horisontal_tl(tl2) +" || " << vertical_tl(tl3)[0] << "\n";
    cout << "      || " << vertical_tl(tl3)[1] << "\n";
    cout << "      || " << vertical_tl(tl3)[2] << "\n";
}



int main(int, char**)
{
    traffic_light* tl1 = new traffic_light();
    traffic_light* tl2 = new traffic_light();
    traffic_light* tl3 = new traffic_light();

    print_road(tl1,tl2,tl3);

    delete tl1;
    delete tl2;
    delete tl3;

    
}


std::string green_string(std::string str)
{
    return "\x1B[32m" + str + "\033[0m";
}

std::string yellow_string(std::string str)
{
    return "\x1B[33m" + str + "\033[0m";
}

std::string red_string(std::string str)
{
    return "\x1B[31m" + str + "\033[0m";
}

std::string horisontal_tl(traffic_light* tl)
{
    switch (tl->get_light())
    {
    case state::stop:
        return red_string("o") + " o o";
        break;

    case state::ready_to_go:
        return red_string("o") + yellow_string(" o") + " o";
        break;

    case state::go:
        return "o o " + green_string("o");
        break;

    default:
        break;
    }
}

std::string vertical_tl(traffic_light* tl)
{
    switch (tl->get_light())
    {
    case state::stop:
        return red_string("o") + "oo";
        break;

    case state::ready_to_go:
        return red_string("o") + yellow_string("o") + "o";
        break;

    case state::go:
        return "oo" + green_string("o");
        break;

    default:
        break;
    }
}
