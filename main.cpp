#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <windows.h>
#include "Main_Menu.h"

int main() {
    bool done {false};
    print_menu();
    do{
        size_t value {};
        std::string users_input{};
        std::getline(std::cin, users_input);
        std::istringstream iss{users_input};
        bool valid_input {iss >> value};

        // validating for both bad input and out of range input
        if(!valid_input || value <= 0 || value > total_num_options){
            ClearScreen();
            std::string error_msg {"########### Invalid input, please try again ###########"};
            std::cout << std::setw((total_width - error_msg.size())/2) << " " << error_msg << std::endl;
            print_menu();
            continue;
        }

        // TODO ADD OTHER OPTIONS' FUNCTIONALITY...

        done = true;
    } while (!done);

    return 0;
}