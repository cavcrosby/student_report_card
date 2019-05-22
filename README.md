# student_report_card

**student_report_card** is a terminal based application, used to write and manage report card files of students.

# Building

1. CMake (https://cmake.org/)
2. With the project being small in scope. Any build tool can be used, I will write if otherwise.

## Usage/Description

Currently, **_main_automationscript.py_** (main script refers to this script) does all the heavy lifting, while as answer_db_questions.py is used for interfacing with the database file created from main_automationscript.

The main script realies on a headless chrome driver. Iterating over each page, grabbing the jobs that can be applied to, sorts them into the jobs that can be applied via Indeed resume, tries to apply to each job, once trying to apply for each job that can be applied to via Indeed resume the script goes to the next page and repeats.

The **_answer_db_questions.py_** is used to answer questions pulled by the main script, otherwise job(s) may not be applied to unless all questions can are filled out by the script and/or job(s) have no supplemental questions asked.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Anything there are any suggestions on what I can add to this page, also do let me know.

## License

See LICENSE.
