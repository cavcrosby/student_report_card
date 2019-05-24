#include <iostream>
#include <map>
#include <vector>
#include <cctype>
#include <algorithm>
#include "Handling.h"

std::map<const std::string, char> getting_student_and_grade_info(){
    std::vector<char> valid_grades {'A', 'B', 'C', 'D', 'F'};
    std::cout << "Type in the student's first name: ";
    std::string fname {};
    std::cin >> fname; // not concern about a valid first/last name

    std::cout << "Type in the student's last name: ";
    std::string lname {};
    std::cin >> lname;
    std::cout << std::endl;

    auto grade_book {get_grade_book()};
    auto book_it {grade_book.begin()};

    // gets input on grades, validates, then inserts grade into previously created map DS
    std::cout << "For the following subjects, type in the student's letter grade (A-D, or F). If the student does not have a grade for the class, insert an n" << std::endl;
    while(book_it != grade_book.end()){
        std::cout << "Enter a grade for " << book_it->first << " : ";
        std::string grade {};
        std::cin >> grade;
        if(!is_grade_valid(grade, valid_grades)){
            std::cout << "!!! Input is not a valid grade! Grades should be A-D, F, or n. Please try again." << std::endl;
            continue;
        }

        grade_book[book_it->first] = grade.at(0);
        book_it++;
    }

    return grade_book;
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

bool is_grade_valid(const std::string &grade, const std::vector<char> &valid_grades){
    char input {grade.at(0)};
    return (std::isalpha(input) && grade.size() == 1 && (std::find(valid_grades.begin(), valid_grades.end(), input) != valid_grades.end()));
}