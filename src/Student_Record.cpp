#include "Student_Record.h"

unsigned int Student_Record::roll_number{0};

Student_Record::Student_Record(std::string &fname, std::string &lname, unsigned int student_roll_number,
                               char grade_physics, char grade_chemistry, char grade_math, char grade_english,
                               char grade_biology) : fname{fname}, lname{lname}, student_roll_number{student_roll_number},
                               grade_physics{grade_physics}, grade_chemistry{grade_chemistry}, grade_math{grade_math},
                               grade_english{grade_english}, grade_biology{grade_biology}{
    roll_number += 1;
}

unsigned int Student_Record::get_student_roll_number() const {
    return student_roll_number;
}

const std::string &Student_Record::get_fname() const {
    return fname;
}

const std::string &Student_Record::get_lname() const {
    return lname;
}

char Student_Record::get_grade_physics() const {
    return grade_physics;
}

char Student_Record::get_grade_chemistry() const {
    return grade_chemistry;
}

char Student_Record::get_grade_math() const {
    return grade_math;
}

char Student_Record::get_grade_english() const {
    return grade_english;
}

char Student_Record::get_grade_biology() const {
    return grade_biology;
}


