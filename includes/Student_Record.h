#ifndef STUDENT_REPORT_CARD_STUDENT_RECORD_H
#define STUDENT_REPORT_CARD_STUDENT_RECORD_H

#pragma once


#include <string>
#include <map>

class Student_Record {
private:
    static unsigned int roll_number;
    unsigned int student_roll_number;
    std::map<const std::string, char> student_subjects_grade;
    std::string fname;
    std::string lname;
public:
    Student_Record(std::string &fname,
            std::string &lname,
            std::map<const std::string, char> &student_subjects_grade,
            unsigned int student_roll_number = roll_number
    );

    unsigned int get_student_roll_number() const;
    const std::string &get_fname() const;
    const std::string &get_lname() const;
    const std::map<const std::string, char> &get_grade_book() const;
};


#endif //STUDENT_REPORT_CARD_STUDENT_RECORD_H
