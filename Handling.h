//
// Created by reap2sow1 on 5/21/2019.
//

#include "Student_Record.h"
#include <vector>

#pragma once
#ifndef STUDENT_REPORT_CARD_HANDLING_H
#define STUDENT_REPORT_CARD_HANDLING_H

Student_Record create_student_record();
void display_all_student_records_info(const std::vector<Student_Record>);
void display_student_info(const std::vector<Student_Record>);
void display_all_student_records_grades(const std::vector<Student_Record>);
void modify_student_grade(const std::vector<Student_Record>);
Student_Record delete_student_record(const std::vector<Student_Record>); // will pop deleted to be stuffed into another DS

#endif //STUDENT_REPORT_CARD_HANDLING_H
