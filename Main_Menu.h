//
// Created by reap2sow1 on 5/16/2019.
//

#include <string>
#include <sstream>

#pragma once
#ifndef STUDENT_REPORT_CARD_MAIN_MENU_H
#define STUDENT_REPORT_CARD_MAIN_MENU_H


const int total_width {70};
const int space_divider {4};
const int total_num_options {7};

void print_ruler();
void print_menu();
std::string get_input();
bool is_valid_input(const std::string &users_input);
void ClearScreen();


#endif //STUDENT_REPORT_CARD_MAIN_MENU_H
