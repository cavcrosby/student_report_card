#pragma once
#ifndef STUDENT_REPORT_CARD_HANDLING_H
#define STUDENT_REPORT_CARD_HANDLING_H

#include <list>
#include <map>
#include <string>
#include <sstream>
#include <windows.h>
#include "Student_Record.h"
#include "Main_Menu.h"

bool creating_student_object(std::list<Student_Record> &student_records);
std::map<const std::string, char> create_grade_book();
bool is_input_grade_valid(const std::string &grade, const std::list<char> &valid_grades);
bool is_student_records_empty_or_we_cannot_find_student(const std::list<Student_Record> &student_records, const int total_buffer_width,
                                                  const std::string &particular_student);
bool display_student_records(const std::list<Student_Record> &student_records, const int total_buffer_width,
                             bool with_roll_number = true, std::string particular_student = "All");
void display_message_and_menu(const std::string &message, const int total_buffer_width,
                              bool with_menu_and_clear_screen = true);
void print_success_and_menu(const int total_buffer_width);
void ClearScreen();
bool delete_student_record(std::list<Student_Record> &student_records, const int total_buffer_width, const std::string &particular_student); // will pop deleted to be stuffed into another DS
bool modify_student_grade(std::list<Student_Record> &student_records, const int total_buffer_width,
                          const std::string &particular_student);

#endif //STUDENT_REPORT_CARD_HANDLING_H
