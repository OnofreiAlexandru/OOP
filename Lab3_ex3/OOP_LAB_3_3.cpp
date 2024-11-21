#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define the Student class
class Student 
{
private:
    string name;
    double grade;

public:
    // Constructor
    Student(string studentName, double studentGrade) : name(studentName), grade(studentGrade) {}

    // Getter for the student's name
    string getName() const 
    {
        return name;
    }

    // Getter for the student's grade
    double getGrade() const 
    {
        return grade;
    }

    // Display student details
    void display() const 
    {
        cout << "Name: " << name << ", Grade: " << grade << endl;
    }
};

// Function to find and return the students with the highest grade
vector<Student> getStudentsWithHighestGrade(const vector<Student>& students) 
{
    vector<Student> topStudents;
    double highestGrade = 0.0;

    // Find the highest grade among all students
    for (const Student& student : students) 
    {
        if (student.getGrade() > highestGrade)
            highestGrade = student.getGrade();
    }

    // Collect all students with the highest grade
    for (const Student& student : students) 
    {
        if (student.getGrade() == highestGrade)
            topStudents.push_back(student);
    }

    return topStudents;
}

int main() 
{
    // Create a list of students
    vector<Student> students = 
    {
        Student("Alice", 89.5),
        Student("Bob", 95.0),
        Student("Charlie", 95.0),
        Student("Diana", 88.0)
    };

    // Get the students with the highest grade
    vector<Student> topStudents = getStudentsWithHighestGrade(students);

    // Display the name and grade of the students with the highest grade
    cout << "Students with the highest grade:" << endl;
    for (const Student& student : topStudents) 
        student.display();

    return 0;
}
