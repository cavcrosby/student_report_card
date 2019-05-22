#ifndef STUDENT_REPORT_CARD_STUDENT_RECORD_H
#define STUDENT_REPORT_CARD_STUDENT_RECORD_H

#pragma once


#include <string>

class Student_Record {
private:
    static unsigned int roll_number;
    unsigned int student_roll_number;
    std::string fname;
    std::string lname;
    char grade_physics;
    char grade_chemistry;
    char grade_math;
    char grade_english;
    char grade_biology;
public:
    Student_Record(std::string &fname,
            std::string &lname,
            unsigned int student_roll_number = roll_number,
            char grade_physics = 'X',
            char grade_chemistry = 'X',
            char grade_math = 'X',
            char grade_english = 'X',
            char grade_biology = 'X');

    unsigned int get_student_roll_number() const;
    const std::string &get_fname() const;
    const std::string &get_lname() const;
    char get_grade_physics() const;
    char get_grade_chemistry() const;
    char get_grade_math() const;
    char get_grade_english() const;
    char get_grade_biology() const;
};


#endif //STUDENT_REPORT_CARD_STUDENT_RECORD_H
