#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <windows.h>
#include <cctype>
#include "Handling.h"
#include "Main_Menu.h"

void print_ruler(){
    std::cout << "0123456789012345678901234567890123456789012345678901234567890123456789" << std::endl;
    std::cout << std::endl;
}

void print_menu(const int total_buffer_width){
//    print_ruler();
    const int space_divider {4};
    std::string title {"===== STUDENT REPORT-CARD MANAGEMENT SYSTEM ====="};

    std::cout << std::setw((total_buffer_width - title.size())/2) << " " << title << std::endl; // we want to have roughly even sides for title
    std::cout << std::endl << std::endl << std::endl;
    std::cout << std::left << std::setw(total_buffer_width/space_divider) << " " << "1. Create Student Record" << std::endl;
    std::cout << std::left << std::setw(total_buffer_width/space_divider) << " " << "2. List All Student Records" << std::endl;
    std::cout << std::left << std::setw(total_buffer_width/space_divider) << " " << "3. List Specific Student's Record" << std::endl;
    std::cout << std::left << std::setw(total_buffer_width/space_divider) << " " << "4. List All Students' Grades In Subjects" << std::endl;
    std::cout << std::left << std::setw(total_buffer_width/space_divider) << " " << "5. Modify A Student's Grade In Record" << std::endl;
    std::cout << std::left << std::setw(total_buffer_width/space_divider) << " " << "6. Delete Student Record" << std::endl;
    std::cout << std::left << std::setw(total_buffer_width/space_divider) << " " << "7. Exit Program..." << std::endl;
    std::cout << std::endl;
    std::cout << std::left << std::setw(total_buffer_width/space_divider) << " " << "Select Your Choice :=> ";
}

void print_success_and_menu(const int total_buffer_width){
    ClearScreen();
    std::string success_message {"########### Successfully completed task! ###########"};
    std::cout << std::setw((total_buffer_width - success_message.size())/2) << " " << success_message << std::endl;
    print_menu(total_buffer_width);
}

std::string get_input(){
    std::string users_input{};
    std::getline(std::cin, users_input);
    return users_input;
}

bool is_valid_input(const std::string &users_input, const int total_buffer_width){
    const int total_num_options {7};
    unsigned int answer_width {users_input.length()};
    size_t value {};
    std::istringstream iss{users_input};
    while(answer_width > 0) {
        bool valid{iss >> value};
        if (!valid || value <= 0 || value > total_num_options) {
            ClearScreen();
            std::string error_msg{"########### Invalid input, please try again ###########"};
            std::cout << std::setw((total_buffer_width - error_msg.size()) / 2) << " " << error_msg << std::endl;
            print_menu(total_buffer_width);
            return false;
        }

        answer_width--;
    }

    return true;
}

bool select_option(const std::string &input, const int total_buffer_width, std::vector<Student_Record> &student_records){
    switch(std::stoi(input)){
        case 1:
            ClearScreen();
            if(!creating_student_object(student_records)){
                std::cout << "Something went wrong..." << std::endl;
                return true;
            }
            print_success_and_menu(total_buffer_width);
            return false;
        case 2:
            // TODO PRINT ALL STUDENT RECORDS OBJECTS FROM A DATA STRUCTURE
            print_success_and_menu(total_buffer_width);
            return false;
        case 3:
            // TODO HOW TO WE MAKE SURE EACH RECORD IS UNIQUE? USE THIS TO FIND SPECFIC STUDENT'S RECORD
            print_success_and_menu(total_buffer_width);
            return false;
        case 4:
            // TODO PRINT ALL STUDENT's GRADES IN ALL SUBJECTS
            print_success_and_menu(total_buffer_width);
            return false;
        case 5:
            // TODO HOW TO WE MAKE SURE EACH RECORD IS UNIQUE? USE THIS TO FIND SPECFIC STUDENT'S RECORD, ASK WHAT SUBJECT AND THEN GRADE, THEN WRITE
            print_success_and_menu(total_buffer_width);
            return false;
        case 6:
            // TODO HOW TO WE MAKE SURE EACH RECORD IS UNIQUE? USE THIS TO FIND SPECFIC STUDENT'S RECORD AND DELETE
            print_success_and_menu(total_buffer_width);
            return false;
        default:
            return true;
    }
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
