#include <iostream>
#include <string>
  
#include <unistd.h>
using std::cout;

std::string red_string(std::string);
std::string yellow_string(std::string);
std::string green_string(std::string);


int main(int argc, char ** argv){
    
    cout << red_string("o");
    cout << "o";
    cout << "o";
    
    sleep(5);

    system("cls");
    cout << red_string("o");
    cout << yellow_string("o");
    cout << "o";

    sleep(3);

    system("cls");
    cout << "o";
    cout << "o";
    cout << green_string("o");

    sleep(10);

    // blink green light 2 times
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            system("cls");

            cout << "o";
            cout << "o";

            if (j % 2 == 0)
            {
                cout << "o";
            }

            else
            {
                cout << green_string("o");
            }

            sleep(1);
        }
    }

    system("cls");
    cout << "o";
    cout << yellow_string("o");
    cout << "o";
    
    sleep(1);

    system("cls");
    cout << red_string("o");
    cout << "o";
    cout << "o";
    
    std::cin;
    return 0;
}



std::string red_string(std::string str)
{
    return "\x1B[31m" + str + "\033[0m";
}

std::string yellow_string(std::string str)
{
    return "\x1B[33m" + str + "\033[0m";
}

std::string green_string(std::string str)
{
    return "\x1B[32m" + str + "\033[0m";
}