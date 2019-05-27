#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <list>
#include <windows.h>
#include "Main_Menu.h"
#include "Handling.h"

int main() {
    std::list<Student_Record> student_records{};
    const int total_buffer_width {120}; // 120 is the default for cmd, might look into other default terminal widths
    bool done {false};
    std::string exit_key {};
    print_menu(total_buffer_width);

    do{
        std::string input {get_input()};
        if(!is_valid_input(input, total_buffer_width))
            continue;

        done = select_option(input, total_buffer_width, student_records);

    } while (!done);

    ClearScreen();
    std::cout << "Thank you for using my program!" << std::endl;
    std::cout << "Comments can be emailed to: crosbyco3@gmail.com" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter any key to exit..." << std::endl;
    std::getline(std::cin, exit_key);
    return 0;
}