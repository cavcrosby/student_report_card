#include "Student_Record.h"
#include <vector>
#include <map>

#pragma once
#ifndef STUDENT_REPORT_CARD_HANDLING_H
#define STUDENT_REPORT_CARD_HANDLING_H

bool creating_student_object(std::vector<Student_Record> &student_records);
std::map<const std::string, char> get_grade_book();
bool is_grade_valid(const std::string &grade, const std::vector<char> &valid_grades);
void display_all_student_records_info(const std::vector<Student_Record> &vec);
void display_student_info(const std::vector<Student_Record> &vec);
void display_all_student_records_grades(const std::vector<Student_Record> &vec);
void modify_student_grade(const std::vector<Student_Record> &vec);
Student_Record delete_student_record(const std::vector<Student_Record> &vec); // will pop deleted to be stuffed into another DS

#endif //STUDENT_REPORT_CARD_HANDLING_H
