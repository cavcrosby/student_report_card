//
// Created by reap2sow1 on 5/16/2019.
//

#include "Main_Menu.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <windows.h>

void print_ruler(){
    std::cout << "0123456789012345678901234567890123456789012345678901234567890123456789" << std::endl;
    std::cout << std::endl;
}

void print_menu(){
//    print_ruler();
    std::string title {"===== STUDENT REPORT-CARD MANAGEMENT SYSTEM ====="};

    std::cout << std::setw((total_width - title.size())/2) << " " << title << std::endl; // we want to have roughly even sides for title
    std::cout << std::endl << std::endl << std::endl;
    std::cout << std::left << std::setw(total_width/space_divider) << " " << "1. Create Student Record" << std::endl;
    std::cout << std::left << std::setw(total_width/space_divider) << " " << "2. List All Student Records" << std::endl;
    std::cout << std::left << std::setw(total_width/space_divider) << " " << "3. List Specific Student's Record" << std::endl;
    std::cout << std::left << std::setw(total_width/space_divider) << " " << "4. List All Students' Grades In Subjects" << std::endl;
    std::cout << std::left << std::setw(total_width/space_divider) << " " << "5. Modify A Student's Grade In Record" << std::endl;
    std::cout << std::left << std::setw(total_width/space_divider) << " " << "6. Delete Student Record" << std::endl;
    std::cout << std::left << std::setw(total_width/space_divider) << " " << "7. Exit Program..." << std::endl;
    std::cout << std::endl;
    std::cout << std::left << std::setw(total_width/space_divider) << " " << "Select Your Choice :=> ";
}

std::string get_input(){
    std::string users_input{};
    std::getline(std::cin, users_input);
    return users_input;
}

bool is_valid_input(const std::string &users_input){
    size_t value {};
    std::istringstream iss{users_input};
    bool valid_input {iss >> value};
    if(!valid_input || value <= 0 || value > total_num_options){
        ClearScreen();
        std::string error_msg {"########### Invalid input, please try again ###########"};
        std::cout << std::setw((total_width - error_msg.size())/2) << " " << error_msg << std::endl;
        print_menu();
        return false;
    }

    return true;
}

// credit to http://www.cplusplus.com/articles/4z18T05o/#Windows for API code
void ClearScreen()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
            hStdOut,
            (TCHAR) ' ',
            cellCount,
            homeCoords,
            &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
            hStdOut,
            csbi.wAttributes,
            cellCount,
            homeCoords,
            &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition( hStdOut, homeCoords );
}
