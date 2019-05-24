#include "Student_Record.h"
#include <vector>
#include <map>

#pragma once
#ifndef STUDENT_REPORT_CARD_HANDLING_H
#define STUDENT_REPORT_CARD_HANDLING_H

std::map<const std::string, char> getting_student_and_grade_info();
std::map<const std::string, char> get_grade_book();
bool is_grade_valid(const std::string &grade, const std::vector<char> &valid_grades);
Student_Record creating_student_object(const std::map<const std::string, char> &grade_book);
void display_all_student_records_info(const std::vector<Student_Record>);
void display_student_info(const std::vector<Student_Record>);
void display_all_student_records_grades(const std::vector<Student_Record>);
void modify_student_grade(const std::vector<Student_Record>);
Student_Record delete_student_record(const std::vector<Student_Record>); // will pop deleted to be stuffed into another DS

#endif //STUDENT_REPORT_CARD_HANDLING_H
