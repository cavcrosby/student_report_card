#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <windows.h>
#include <cctype>
#include "Handling.h"
#include "Main_Menu.h"

void print_ruler(const int total_buffer_width){
    int ruler_times {total_buffer_width/10};
    for(int i {}; i < ruler_times; i++) {
        std::cout << "0123456789";
    }
    std::cout << std::endl;
}

void print_menu(const int total_buffer_width){
    const int space_divider {4};
    const int title_space_divider {2};
    const std::string title {"===== STUDENT REPORT-CARD MANAGEMENT SYSTEM ====="};
    std::cout << std::setw((total_buffer_width - title.size())/title_space_divider) << " " << title << std::endl; // we want to have roughly even sides for title
    std::cout << std::endl << std::endl << std::endl;
    std::cout << std::setw(total_buffer_width/space_divider) << " " << "1. Create Student Record" << std::endl;
    std::cout << std::setw(total_buffer_width/space_divider) << " " << "2. List All Student Records" << std::endl;
    std::cout << std::setw(total_buffer_width/space_divider) << " " << "3. List Specific Student's Record" << std::endl;
    std::cout << std::setw(total_buffer_width/space_divider) << " " << "4. List All Students' Grades In Subjects" << std::endl;
    std::cout << std::setw(total_buffer_width/space_divider) << " " << "5. Modify A Student's Grade In Record" << std::endl;
    std::cout << std::setw(total_buffer_width/space_divider) << " " << "6. Delete Student Record" << std::endl;
    std::cout << std::setw(total_buffer_width/space_divider) << " " << "7. Exit Program..." << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(total_buffer_width/space_divider) << " " << "Select Your Choice :=> ";
}

std::string get_input(){
    std::string users_input{};
    std::getline(std::cin, users_input);
    return users_input;
}

bool is_valid_input(const std::string &users_input, const int total_buffer_width){
    if(users_input.empty()){
        display_message_and_menu("########### No input was entered! Please try again ###########", total_buffer_width);
        return false;
    }
    const int total_num_options {7};
    unsigned int answer_width {users_input.length()};
    size_t value {};
    std::istringstream iss{users_input};
    while(answer_width > 0) {
        bool valid{iss >> value};
        if (!valid || value <= 0 || value > total_num_options) {
            display_message_and_menu("########### Invalid input, please try again ###########", total_buffer_width);
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
                std::cout << "Something went wrong..." << std::endl; // TODO FIX ERROR HANDLING OR IMPROVE IT?
                return true;
            }
            print_success_and_menu(total_buffer_width);
            return false;
        case 2:
            ClearScreen();
            if(!display_student_records(student_records, total_buffer_width)){ return false;}
            print_success_and_menu(total_buffer_width);
            return false;
        case 3: {
            std::string student_record_number{student_record_number_input()};
            if (!display_student_records(student_records, total_buffer_width, true, student_record_number)) { return false;}
            print_success_and_menu(total_buffer_width);
            return false;
        }
        case 4:
            ClearScreen();
            if(!display_student_records(student_records, total_buffer_width, false)){ return false;}
            print_success_and_menu(total_buffer_width);
            return false;
        case 5: {
            std::string student_record_number{student_record_number_input()};
            if(!modify_student_grade(student_records, total_buffer_width, student_record_number)){ return false;}
            print_success_and_menu(total_buffer_width);
            return false;
        }
        case 6:
            // TODO HOW TO WE MAKE SURE EACH RECORD IS UNIQUE? USE THIS TO FIND SPECFIC STUDENT'S RECORD AND DELETE
            print_success_and_menu(total_buffer_width);
            return false;
        default:
            return true;
    }
}

std::string student_record_number_input(){
    ClearScreen();
    std::string student_record_number{};
    std::cout << "Enter the student's record number: ";
    std::getline(std::cin, student_record_number);
    ClearScreen();
    return student_record_number;
}

