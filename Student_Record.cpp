//
// Created by reap2sow1 on 5/21/2019.
//

#include "Student_Record.h"

unsigned int Student_Record::roll_number{0};

Student_Record::Student_Record(std::string &fname, std::string &lname, unsigned int student_roll_number,
                               char grade_physics, char grade_chemistry, char grade_math, char grade_english,
                               char grade_biology) : fname{fname}, lname{lname}, student_roll_number{student_roll_number},
                               grade_physics{grade_physics}, grade_chemistry{grade_chemistry}, grade_math{grade_math},
                               grade_english{grade_english}, grade_biology{grade_biology}{
    roll_number += 1;
}

unsigned int Student_Record::getStudentRollNumber() const {
    return student_roll_number;
}

const std::string &Student_Record::getFname() const {
    return fname;
}

const std::string &Student_Record::getLname() const {
    return lname;
}

char Student_Record::getGradePhysics() const {
    return grade_physics;
}

char Student_Record::getGradeChemistry() const {
    return grade_chemistry;
}

char Student_Record::getGradeMath() const {
    return grade_math;
}

char Student_Record::getGradeEnglish() const {
    return grade_english;
}

char Student_Record::getGradeBiology() const {
    return grade_biology;
}


