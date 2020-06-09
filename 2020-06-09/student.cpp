// Basically learning about struct/classes and knowing the differences between them
#include <unordered_map>
#include <iostream>
#include <string>

class Grade {
public:
    double value;
    std::string subject;

    Grade(std::string subject, double value): value(value), subject(subject) {};
    Grade(): value(0.00), subject("") {}
};

// "struct" is a data type that makes every property public
// main difference of class/struct is the default access level (private/protected/etc...)
struct Student {
    std::unordered_map<std::string, Grade> grades;
    std::string name;

    Student(std::string name): name(name), grades() {};

    double calculate_gpa() {
        double val = 0.00;

        for (auto x: grades) {
            std::string subject;
            Grade grade("Unknown", 0.00);
            std::tie(subject, grade) = x;

            val += grade.value;
        }

        return val / grades.size();
    };
};

int main() {
    Student student("Kyle");
    Grade math("Math", 64.75);
    Grade english("English", 75.95);
    Grade biology("Biology", 98.23);

    student.grades["Math"] = math;
    student.grades["English"] = english;
    student.grades["Biology"] = biology;

    std::cout << student.name << " has a GPA of " << student.calculate_gpa() << std::endl;
    return 0;
}