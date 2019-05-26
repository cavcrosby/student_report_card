#include "Student_Record.h"

unsigned int Student_Record::roll_number{0};

Student_Record::Student_Record(std::string &fname, std::string &lname, std::map<const std::string, char> &student_subjects_grade, unsigned int student_roll_number)
                               : fname{fname}, lname{lname}, student_subjects_grade{student_subjects_grade}, student_roll_number{student_roll_number}{
    roll_number += 1;
}

bool Student_Record::operator==(const std::string &student_roll_number) const {
    return (std::to_string(this->get_student_roll_number()) == student_roll_number); // not this->student_roll_number rhs
}

unsigned int Student_Record::get_student_roll_number() const {
    return student_roll_number;
}

std::string &Student_Record::get_fname(){
    return fname;
}

std::string &Student_Record::get_lname(){
    return lname;
}

std::map<const std::string, char> &Student_Record::get_grade_book(){
    return student_subjects_grade;
}



