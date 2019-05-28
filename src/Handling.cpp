#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <list>
#include <cctype>
#include <algorithm>
#include <windows.h>
#include "Main_Menu.h"
#include "Handling.h"

bool create_student_object(std::list<Student_Record> &student_records) {
    bool done{false};
    std::list<char> valid_grades{'A', 'B', 'C', 'D', 'F', 'N'};
    std::string fname{};
    std::string lname{};
    while(!done){
        std::cout << "Type in the student's first name: ";
        std::getline(std::cin, fname);
        std::cout << "Type in the student's last name: ";
        std::getline(std::cin, lname);
        std::cout << std::endl;
        if(lname.empty() || fname.empty()){
            ClearScreen();
            std::cout << "!!! Both first and last name should not be empty, please try again." << std::endl;
            continue;
        }
        done = true;
    }
    auto grade_book{create_grade_book()};
    auto grade_book_it{grade_book.begin()};
    // gets input on grades, validates, then inserts grade into previously created map DS
    std::cout
            << "For the following subjects, type in the student's letter grade (A-D, or F). If the student does not have a grade for the class, insert an N"
            << std::endl;
    while (grade_book_it != grade_book.end()) {
        std::cout << "Enter a grade for " << grade_book_it->first << " : ";
        std::string grade{};
        std::getline(std::cin, grade);
        if (grade.empty() || !is_input_grade_valid(grade, valid_grades)) {
            std::cout << "!!! Input is not a valid grade! Grades should be A-D, F, or N. Please try again."
                      << std::endl;
            continue;
        }
        grade_book[grade_book_it->first] = std::toupper(grade.at(0));
        grade_book_it++;
    }
    student_records.emplace_back(fname, lname, grade_book);
    return true;
}

std::map<const std::string, char> create_grade_book() {
    std::list<std::string> subjects{
            "Physics",
            "Chemistry",
            "Math",
            "English",
            "Biology"};
    std::map<const std::string, char> grade_book{};
    auto subject_it = subjects.begin();
    while (subject_it != subjects.end()) {
        grade_book.insert(std::make_pair(*subject_it, NULL)); // null can be another value
        subject_it++;
    }
    return grade_book;
}

bool is_input_grade_valid(const std::string &grade, const std::list<char> &valid_grades) {
    // Valid grade input should be a single character that is a letter and found to be a valid character in valid_grades (non-case sensitive)
    char input{grade.at(0)};
    return (std::isalpha(input) && grade.size() == 1 &&
            (std::find(valid_grades.begin(), valid_grades.end(), std::toupper(input)) != valid_grades.end()));
}

bool is_student_records_empty_or_we_cannot_find_student(const std::list<Student_Record> &student_records, const int total_buffer_width,
        const std::string &particular_student){
    if (student_records.empty()) {
        display_message_and_menu("########### There are no student records to modify/delete... ###########",
                                 total_buffer_width);
        return true;
    }
    auto found_it{std::find(student_records.begin(), student_records.end(), particular_student)};
    if (found_it == student_records.end()) {
        display_message_and_menu(
                "########### Could not find student record, please make sure you have entered in the right roll number ###########",
                total_buffer_width);
        return true;
    }

    return false;
}

bool display_student_records(const std::list<Student_Record> &student_records, const int total_buffer_width,
                             bool with_roll_number,
                             std::string particular_student){
    if(student_records.empty()){
        display_message_and_menu("########### There are no student records to print... ###########", total_buffer_width);
        return false;
    }
    // Depending on the parameters, you can print student records w/wo student roll number, or a single student's grade can be printed out
    std::list<Student_Record> iterate_over {student_records};
    const int title_space_divider {3};
    const int space_between_sub_grade {12};
    if(particular_student != "All") {
        auto found_it {std::find(student_records.begin(), student_records.end(), particular_student)};
        if (found_it == student_records.end()){
            display_message_and_menu(
                    "########### Could not find student record, please make sure you have entered in the right roll number ###########",
                    total_buffer_width);
            return false;
        }
        iterate_over.clear();
        iterate_over.push_back(*found_it);
    }
    auto it{iterate_over.begin()};
    while (it != iterate_over.end()) { // we have a record of a student
        std::string title{"===== " + it->get_fname() + " " + it->get_lname() + "'s REPORT CARD ===== "};
        unsigned int space_for_title{((total_buffer_width - title.size())/title_space_divider)};

        std::cout << std::setw(space_for_title) << " " << title << std::endl;
        std::cout << std::setw(space_for_title) << " " << ((with_roll_number) ? ("Roll #: " + std::to_string(it->get_student_roll_number())) : std::string("")) << std::endl; // display_message_and_menu will be the same, just with or without roll number
        const std::map<const std::string, char> &grade_book {it->get_grade_book()};
        for(auto &subject: grade_book) { // here is where we go through their grade book
            std::cout << std::left << std::setw(space_between_sub_grade) << subject.first  << subject.second << std::endl;
        }

        it++;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Enter any key to go back to the main menu..." << std::endl;
    getline(std::cin, particular_student);
    return true;
}

void display_message_and_menu(const std::string &message, const int total_buffer_width, bool with_menu_and_clear_screen){
    if(with_menu_and_clear_screen)
        ClearScreen();
    std::cout << std::setw((total_buffer_width - message.size()) / 2) << " " << message << std::endl;
    if(with_menu_and_clear_screen)
        print_menu(total_buffer_width);
}

void print_success_and_menu(const int total_buffer_width){
    display_message_and_menu("########### Successfully completed task! ###########", total_buffer_width);
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

bool delete_student_record(std::list<Student_Record> &student_records, const int total_buffer_width, const std::string &particular_student){
    if (is_student_records_empty_or_we_cannot_find_student(student_records, total_buffer_width, particular_student)) {
        return false;
    }
    auto found_it{std::find(student_records.begin(), student_records.end(), particular_student)};
    student_records.erase(found_it);
    return true;
}

bool modify_student_grade(std::list<Student_Record> &student_records, const int total_buffer_width,
                          const std::string &particular_student) {
    std::list<char> valid_grades{'A', 'B', 'C', 'D', 'F', 'N'};
    if (is_student_records_empty_or_we_cannot_find_student(student_records, total_buffer_width, particular_student)) {
        return false;
    }
    auto found_it{std::find(student_records.begin(), student_records.end(), particular_student)};
    auto &grade_book{found_it->get_grade_book()};
    bool done{false};
    std::string subject{};
    while (!done) {
        std::cout << "Enter the subject whose student's grade you wish to change: ";
        std::getline(std::cin, subject);
        if (grade_book.find(subject) == grade_book.end()) {
            std::cout << "!!! Student is not taking the entered subject, please try again..." << std::endl;
            continue;
        }
        done = true;
    }
    done = false;
    std::string grade{};
    while (!done) {
        std::cout << "Enter a grade for " << subject << " : ";
        std::getline(std::cin, grade);
        if (grade.empty() || !is_input_grade_valid(grade, valid_grades)) {
            std::cout << "!!! Input is not a valid grade! Grades should be A-D, F, or N. Please try again."
                      << std::endl;
            continue;
        }
        grade_book[subject] = std::toupper(grade.at(0));
        done = true;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Enter any key to go back to the main menu..." << std::endl;
    getline(std::cin, subject);
    return true;
}
