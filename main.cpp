#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <windows.h>
#include "Main_Menu.h"

int main() {
    const int total_buffer_width {120}; // 120 is the default for cmd, might look into other default terminal widths
    bool done {false};
    char exit_char {};
    print_menu(total_buffer_width);

    do{
        std::string input {get_input()};
        if(!is_valid_input(input, total_buffer_width))
            continue;

        done = select_option(input, total_buffer_width);

    } while (!done);

    ClearScreen();
    std::cout << "Thank you for using my program!" << std::endl;
    std::cout << "Comments can be emailed to: <recipient>@<email>.com" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter any key to exit..." << std::endl;
    std::cin >> exit_char;

    return 0;
}