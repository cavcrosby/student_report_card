//
// Created by reap2sow1 on 5/21/2019.
//

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

    unsigned int getStudentRollNumber() const;
    const std::string &getFname() const;
    const std::string &getLname() const;
    char getGradePhysics() const;
    char getGradeChemistry() const;
    char getGradeMath() const;
    char getGradeEnglish() const;
    char getGradeBiology() const;
};


#endif //STUDENT_REPORT_CARD_STUDENT_RECORD_H
