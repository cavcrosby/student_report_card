cmake_minimum_required(VERSION 3.3.14)
project(student_report_card)

set(CMAKE_CXX_STANDARD 14)

add_executable(student_report_card_debug src/main.cpp src/Main_Menu.cpp includes/Main_Menu.h src/Student_Record.cpp includes/Student_Record.h src/Handling.cpp includes/Handling.h)
add_executable(student_report_card src/main.cpp src/Main_Menu.cpp includes/Main_Menu.h src/Student_Record.cpp includes/Student_Record.h src/Handling.cpp includes/Handling.h)
include_directories(includes)
include_directories(src)