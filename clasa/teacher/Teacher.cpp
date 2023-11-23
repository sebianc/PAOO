#pragma once
#include <iostream>

namespace teacher{
    template<typename teacherName, typename teacherClass>
    class Teacher{
        private:
            teacherName tchrName;
            teacherClass tchrClass;
        public:
            //constructor default
            Teacher(){
                std::cout<<"un profesor a fost creat\n";
            }
            //destructor default
            ~Teacher(){
                std::cout<<"profesorul "<<tchrName<<" a fost distrus\n";
            }
            //constructor cu param
            Teacher(teacherName name, teacherClass clas): tchrName(name), tchrClass(clas){
                std::cout<<"profesorul "<<tchrName<<" ce preda "<<tchrClass<<" a fost creat\n";
            }
            //print pt profesor
            void printTeacher() const {
                std::cout<<"Profesorul "<<tchrName<<" preda "<<tchrClass<<std::endl;
            }
            //getter pt nume
            teacherName getTeacherName(){
                return tchrName;
            }
            //getter pt clasa
            teacherClass getTeacherClass(){
                return tchrClass;
            }
    };
}