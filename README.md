# University Department Study Monitoring System (Phase B)

An advanced object-oriented C++ program developed for the second phase of the university department study monitoring system, introducing academic hierarchies, course structures, semester logic, grade management, file persistence, and exception handling.

## Key Features

- **Class Inheritance (`Student` & `Professor`):** Specialized `Student` and `Professor` classes inheriting from the base `Person` class to handle academic roles and attributes.
- **Course Management (`Course`):** Courses organized by semesters with teaching units and classification as mandatory or elective.
- **Academic Semesters & Progress:** Secretary assignment of professors per semester, student course registrations, end-of-semester examinations, and graduation evaluations.
- **File I/O & Interactive Menu:** Initial loading and final saving of records via files, alongside a comprehensive interactive menu for management operations, statistics, and transcripts.
- **Exception Handling:** Robust error management using C++ exception handling mechanisms to catch invalid operations.

## Compilation & Execution


g++ -o study_system final.cpp

 ./study_system
