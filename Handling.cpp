//
// Created by reap2sow1 on 5/21/2019.
//

#include <iostream>
#include <map>
#include <vector>
#include "Handling.h"

Student_Record create_student_record(){
    std::cout << "Type in the student's first name: ";
    std::string fname {};
    std::cin >> fname; // not concern about a valid first/last name
    std::cout << std::endl;

    std::cout << "Type in the student's last name: ";
    std::string lname {};
    std::cin >> lname;
    std::cout << std::endl;

    auto grade_book {get_grade_book()};
    auto book_it {grade_book.begin()};

    // gets input on grades, validates, then inserts grade into previously created map DS
    std::cout << "For the following subjects, type in the student's letter grade. If the student does not have a grade for the class, insert an n" << std::endl;
    while(book_it != grade_book.end()){
        std::cout << "Enter a grade for " << book_it->first << " : ";
        std::string grade {};
        std::cin >> grade;
        std::cout << std::endl;
        if(!is_grade_valid()){
            std::cout << "!!! Input is not a valid grade! Grades should be A-F, or n. Please try again." << std::endl;
            continue;
        }

        grade_book[book_it->first] = grade.at(0);
        book_it++;
    }

    Student_Record student {fname, lname};

    // TODO SET GRADE VALUES TO OBJECT'S ATTRIBUTES

}

// creates subject keys then to be mapped with a grade in map DS
std::map<const std::string, char> get_grade_book() {
    std::vector<std::string> keys{
            "Physics",
            "Chemistry",
            "Math",
            "English",
            "Biology"};
    std::map<const std::string, char> subject_map{};
    auto key_it = keys.begin();
    while (key_it != keys.end()) {
        subject_map.insert(std::make_pair(*key_it, ' '));
        key_it++;
    }
}