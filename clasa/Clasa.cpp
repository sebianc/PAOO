#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Student.cpp"
#include "Teacher.cpp"

using namespace student;
using namespace teacher;

namespace clasa{
    template<typename studentName, typename studentAge, typename studentGrades, typename teacherName, typename teacherClass>
    class Clasa{
        private:
            std::unique_ptr<Teacher<teacherName, teacherClass>> classTeacher;
            std::vector<std::shared_ptr<Student<studentName, studentAge, studentGrades>>> classStudents;
            std::string className;
        public:
            //constructor default
            Clasa(){
                std::cout<<"o clasa a fost creata\n";
            }
            //constructor cu param
            Clasa(std::string name): className(name){
                std::cout<<"clasa "<<className<<" a fost creata\n";
            }
            //destructor
            ~Clasa(){
                std::cout<<"clasa "<<className<<" a fost distrusa\n";
            }
            //setam profesorul care e unic pt clasa pe care o preda. conventie: un profesor nu poate sa predea la mai multe clase, dar mai multi elevi pot fii la mai multe clase
            void addProfesor(std::unique_ptr<Teacher<teacherName, teacherClass>> tchrToBeAdded){
                classTeacher = std::move(tchrToBeAdded);
                std::cout<<"profesorul a fost adaugat cu succes in clasa "<<className<<". detaliile lui sunt: ";
                classTeacher->printTeacher();
            }
            //metoda pt a adauga studenti in clasa curenta
            void addStudent(std::shared_ptr<Student<studentName, studentAge, studentGrades>> newStudent){
                classStudents.push_back(newStudent);
                std::cout<<"studentul a fost adaugat cu succes in clasa "<<className<<". detaliile lui sunt: ";
                newStudent->printStudent();
            }
            //metoda pt afisare studenti
            void showStudents() const {
                for(const auto& student : classStudents){
                    student->printStudent();
                }
            }
    };
}