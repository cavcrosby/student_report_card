#include <string>
#include <sstream>
#include <windows.h>
#include <vector>
#include "Student_Record.h"

#pragma once
#ifndef STUDENT_REPORT_CARD_MAIN_MENU_H
#define STUDENT_REPORT_CARD_MAIN_MENU_H

void print_ruler();
void print_menu(const int total_buffer_width);
std::string get_input();
bool is_valid_input(const std::string &users_input, const int total_buffer_width);
bool select_option(const std::string &input, const int total_buffer_width, std::vector<Student_Record> &student_records);
std::string student_record_number_input();

#endif //STUDENT_REPORT_CARD_MAIN_MENU_H
