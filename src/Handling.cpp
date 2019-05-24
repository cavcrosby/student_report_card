#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <cctype>
#include <algorithm>
#include <Main_Menu.h>
#include "Handling.h"

bool creating_student_object(std::vector<Student_Record> &student_records) {
    bool done{false};
    std::vector<char> valid_grades{'A', 'B', 'C', 'D', 'F', 'N'};
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

    auto grade_book{get_grade_book()};
    auto book_it{grade_book.begin()};

    // gets input on grades, validates, then inserts grade into previously created map DS
    std::cout
            << "For the following subjects, type in the student's letter grade (A-D, or F). If the student does not have a grade for the class, insert an N"
            << std::endl;
    while (book_it != grade_book.end()) {
        std::cout << "Enter a grade for " << book_it->first << " : ";
        std::string grade{};
        std::getline(std::cin, grade);
        if (grade.empty() || !is_input_grade_valid(grade, valid_grades)) {
            std::cout << "!!! Input is not a valid grade! Grades should be A-D, F, or N. Please try again."
                      << std::endl;
            continue;
        }

        grade_book[book_it->first] = std::toupper(grade.at(0));
        book_it++;
    }

    student_records.emplace_back(fname, lname, grade_book);
    return true;
}

// creates subject keys then to be mapped with a grade in map DS
std::map<const std::string, char> get_grade_book() {
    std::vector<std::string> keys{
            "Physics",
            "Chemistry",
            "Math",
            "English",
            "Biology"};
    std::map<const std::string, char> subject_and_grades{};
    auto key_it = keys.begin();
    while (key_it != keys.end()) {
        subject_and_grades.insert(std::make_pair(*key_it, NULL)); // use null or not?
        key_it++;
    }

    return subject_and_grades;
}

bool is_input_grade_valid(const std::string &grade, const std::vector<char> &valid_grades) {
    char input{grade.at(0)};
    return (std::isalpha(input) && grade.size() == 1 &&
            (std::find(valid_grades.begin(), valid_grades.end(), std::toupper(input)) != valid_grades.end()));
}

bool display(const std::vector<Student_Record> &vec, const int total_buffer_width, bool with_roll_number,
        std::string particular_student){
    if(vec.empty()){
        std::string message {"########### There are no student records to print... ###########"};
        std::cout << std::setw((total_buffer_width - message.size())/2) << " " << message << std::endl;
        return false;
    }
    std::vector<Student_Record> iterate_over {vec};
    const int title_space_divider {3};
    int space_between_sub_grade {12};

    if(particular_student != "All") {
        auto found_it {std::find(vec.begin(), vec.end(), particular_student)};
        if (found_it == vec.end()){
            std::string message {"########### Could not find student, please make sure you have entered in the right roll number ###########"};
            std::cout << std::setw((total_buffer_width - message.size())/2) << " " << message << std::endl;
            return false;
        }
        iterate_over.clear();
        iterate_over.push_back(*found_it);
    }

    auto it{iterate_over.begin()};
    while (it != iterate_over.end()) { // we have a record of a student
        std::string title{"===== " + it->get_fname() + " " + it->get_lname() + "'s REPORT CARD ===== "};
        unsigned int subject_label_start{((total_buffer_width - title.size())/title_space_divider)};

        std::cout << std::setw(subject_label_start) << " " << title << std::endl;
        std::cout << std::setw(subject_label_start) << " " << ((with_roll_number) ? ("Roll #: " + std::to_string(it->get_student_roll_number())) : std::string("")) << std::endl; // display will be the same, just with or without roll number
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