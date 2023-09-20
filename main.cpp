#include <iostream>
#include <unistd.h>
#include "traffic_light.h"

using std::cout;

#ifdef _WIN32

void clear()
{
    system("cls");
}

#else

void clear()
{
    system("clear");
}

#endif

std::string red_string(std::string str);
std::string yellow_string(std::string str);
std::string green_string(std::string str);
std::string horisontal_tl(traffic_light* tl);
std::string vertical_tl(traffic_light* tl, int position);




void print_road(traffic_light* tl1, traffic_light* tl2, traffic_light* tl3)
{
    clear();
    cout << "        " << horisontal_tl(tl1) << "\n";
    cout << "= = = ## = = =\n";
    cout << "= = = ## = = =\n";
    cout << horisontal_tl(tl2) +" || " << vertical_tl(tl3,1) << "\n";
    cout << "      || " << vertical_tl(tl3,2) << "\n";
    cout << "      || " << vertical_tl(tl3,3) << "\n";
}



int main(int, char**)
{   
    
    traffic_light* tl1 = new traffic_light();
    traffic_light* tl2 = new traffic_light();
    traffic_light* tl3 = new traffic_light();
    
    // the first traffic light logic

    print_road(tl1,tl2,tl3);
    sleep(2);

    tl1->set_light(state::ready_to_go);
    print_road(tl1,tl2,tl3);
    sleep(1);

    tl1->set_light(state::go);
    print_road(tl1,tl2,tl3);
    sleep(5);

    tl1->set_light(state::ready_to_stop);
    print_road(tl1,tl2,tl3);
    sleep(1);

    tl1->set_light(state::stop);
    print_road(tl1,tl2,tl3);
    sleep(1);

    //second traffic light ligic

    tl2->set_light(state::ready_to_go);
    print_road(tl1,tl2,tl3);
    sleep(1);

    tl2->set_light(state::go);
    print_road(tl1,tl2,tl3);
    sleep(5);

    tl2->set_light(state::ready_to_stop);
    print_road(tl1,tl2,tl3);
    sleep(1);

    tl2->set_light(state::stop);
    print_road(tl1,tl2,tl3);
    sleep(1);

    //third traffic light ligic

    tl3->set_light(state::ready_to_go);
    print_road(tl1,tl2,tl3);
    sleep(1);

    tl3->set_light(state::go);
    print_road(tl1,tl2,tl3);
    sleep(5);

    tl3->set_light(state::ready_to_stop);
    print_road(tl1,tl2,tl3);
    sleep(1);

    tl3->set_light(state::stop);
    print_road(tl1,tl2,tl3);
    sleep(1);

    
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

    case state::ready_to_stop:
        return "o" + yellow_string(" o") + " o";
    default:
        break;
    }
}

std::string vertical_tl(traffic_light* tl, int position)
{
    std::string first_light = "o";
    std::string second_light = "o";
    std::string third_light = "o";


    switch (tl->get_light())
    {
    case state::stop:
        first_light = red_string(first_light);
        break;

    case state::ready_to_go:
        first_light = red_string(first_light);
        second_light = yellow_string(second_light);
        break;

    case state::go:
        third_light = green_string(third_light);
        break;
    
    case state::ready_to_stop:
        second_light = yellow_string(second_light);

    default:
        break;
    }

    if (position == 1)
    {
        return first_light;
    }

    if (position == 2)
    {
        return second_light;
    }
    
    if (position == 3)
    {
        return third_light;
    }
    
}

