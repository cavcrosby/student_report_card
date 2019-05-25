#include "Student_Record.h"
#include "Main_Menu.h"
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <windows.h>

#pragma once
#ifndef STUDENT_REPORT_CARD_HANDLING_H
#define STUDENT_REPORT_CARD_HANDLING_H

bool creating_student_object(std::vector<Student_Record> &student_records);
std::map<const std::string, char> create_grade_book();
bool is_input_grade_valid(const std::string &grade, const std::vector<char> &valid_grades);
bool display_student_records(const std::vector<Student_Record> &vec, const int total_buffer_width,
                             bool with_roll_number = true, std::string particular_student = "All");
bool modify_student_grade(const std::vector<Student_Record> &vec, const int total_buffer_width,
        const std::string &particular_student);
Student_Record delete_student_record(const std::vector<Student_Record> &vec); // will pop deleted to be stuffed into another DS
void ClearScreen();
void display_message_and_menu(const std::string &message, const int total_buffer_width,
                              bool with_menu_and_clear_screen = true);

#endif //STUDENT_REPORT_CARD_HANDLING_H
