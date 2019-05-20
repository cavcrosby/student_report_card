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
        std::string input {get_input()};
        if(!is_valid_input(input))
            continue;
        
        // TODO ADD OTHER OPTIONS' FUNCTIONALITY...
        done = true;
    } while (!done);

    return 0;
}