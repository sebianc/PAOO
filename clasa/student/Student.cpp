#pragma once

#include <iostream>
#include <vector>

namespace student{
    template<typename studentName, typename studentAge, typename studentGrades>
    class Student
    {
    private:
        studentName stdName;
        studentAge stdAge;
        std::vector<studentGrades> stdGrades;
    public:
        //constructor default
        Student(){
            std::cout<<"un student a fost creat\n";
        }
        //constructor cu param
        Student(studentName name, studentAge age): stdName(name), stdAge(age){}
        //destructor default
        ~Student(){
            std::cout<<"studentul "<<stdName<<" a fost distrus\n";
        }
        //adaugare de note
        void addGrade(studentGrades grade){
            stdGrades.push_back(grade);
        }
        //print pt student
        void printStudent() const{
            std::cout<<"Studentul "<<stdName<<" are varsta de "<<stdAge<<" ani\n";
        }
        //student age
        void changeStudentAge(studentAge newAge){
            stdAge = newAge;
        }
        //getter pt nume student
        studentName getStudentName(){
            return stdName;
        }
        //getter pt varsta student
        studentAge getStudentAge(){
            return stdAge;
        }
        //getter pt note student
        std::vector<studentGrades> getStudentGrades(){
            return stdGrades;
        }
    };
    
}