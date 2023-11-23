#include <iostream>
#include <memory>
#include <vector>
#include "Clasa.cpp"
#include "Student.cpp"
#include "Teacher.cpp"

using namespace clasa;
using namespace teacher;
using namespace student;

template<typename gradesType>
void printStudentAvg(Student<std::string, int, gradesType> stud){
    gradesType avg = 1;

    std::vector<gradesType> note_std = stud.getStudentGrades();

    gradesType sum = 0;

    if(note_std.size() == 0){
        std::cout<<"Studentul nu are nicio nota\n";
        return;
    }

    for(const auto& grade : note_std){
        sum += grade;
    }

    std::cout<<"Media pt studentul "<<stud.getStudentName()<<" este "<<sum/note_std.size()<<std::endl;
}

int main(){
    //clasa cu profesori/studenti cu nume in formatul std::string
    Clasa<std::string, int, float, std::string, std::string> clasa1("clasa1");
    std::cout<<"---------------------------------------------------------------------\n";

    //clasa cu profesori/studenti cu nume in formatul std::string
    Clasa<std::string, int, float, std::string, std::string> clasa2("clasa2");
    std::cout<<"---------------------------------------------------------------------\n";

    //clasa cu profesori/studenti in formatul de cod numeric adica un int
    Clasa<int, int, float, int, std::string> clasa3("clasa3");
    std::cout<<"---------------------------------------------------------------------\n";
    
    //profesor pt clasa1
    std::unique_ptr<Teacher<std::string, std::string>> profesor_clasa1 = std::make_unique<Teacher<std::string, std::string>>("Marius", "BIA");
    std::cout<<"---------------------------------------------------------------------\n";

    //profesor pt clasa2
    std::unique_ptr<Teacher<std::string, std::string>> profesor_clasa2 = std::make_unique<Teacher<std::string, std::string>>("Dan", "TS");
    std::cout<<"---------------------------------------------------------------------\n";

    //adaugam un profesor unic pt clasa 1
    clasa1.addProfesor(std::move(profesor_clasa1));
    //cream 3 studenti pt clasa 1, ultimii 2 o sa participe si la materia de la clasa 2
    std::shared_ptr<Student<std::string, int, float>> student_1 = std::make_shared<Student<std::string, int, float>>("Ionut", 15);
    std::shared_ptr<Student<std::string, int, float>> student_2 = std::make_shared<Student<std::string, int, float>>("Andrei", 16);
    std::shared_ptr<Student<std::string, int, float>> student_3 = std::make_shared<Student<std::string, int, float>>("Calin", 17);
    //adaugam studentii la clasa 1
    clasa1.addStudent(student_1);
    clasa1.addStudent(student_2);
    clasa1.addStudent(student_3);
    std::cout<<"---------------------------------------------------------------------\n";

    //adaugam un profesor unic pt clasa 2
    clasa2.addProfesor(std::move(profesor_clasa2));
    //adaugam studentii la clasa 2
    clasa1.addStudent(student_2);
    clasa1.addStudent(student_3);
    std::cout<<"---------------------------------------------------------------------\n";

    //testare shared pointer
    student_3->changeStudentAge(11);
    clasa1.showStudents();
    clasa2.showStudents();
    std::cout<<"---------------------------------------------------------------------\n";

    //testare unique pointer -> profesorul_1 sau 2 trebuie sa fie nullptr pt ca am folosit std::move ca sa transfer ownershipul
    if(profesor_clasa1 == nullptr && profesor_clasa2 == nullptr) std::cout<<"unique pointer functioneaza bine\n";
    std::cout<<"---------------------------------------------------------------------\n";

    //adaugam un student pt clasa 3 doar de test
    std::shared_ptr<Student<int, int, float>> student_4 = std::make_shared<Student<int, int, float>>(125, 15);
    clasa3.addStudent(student_4);
    std::cout<<"---------------------------------------------------------------------\n";

    //test pentru functia templetizata
    Student<std::string, int, int> std_test1("Mihai", 12);
    Student<std::string, int, float> std_test2("Marinel", 12);

    std_test1.addGrade(2);
    std_test1.addGrade(3);
    std_test1.addGrade(5);

    std_test2.addGrade(2);
    std_test2.addGrade(3);
    std_test2.addGrade(5);

    printStudentAvg(std_test1);
    printStudentAvg(std_test2);
    std::cout<<"---------------------------------------------------------------------\n";

    return 0;
}