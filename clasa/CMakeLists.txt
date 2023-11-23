add_library(Clasa STATIC Clasa.cpp student/Student.cpp teacher/Teacher.cpp)

target_include_directories(Clasa PUBLIC "student/" "teacher/")
