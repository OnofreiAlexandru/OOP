#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For find_if

using namespace std;

// Define the Student class
class Student 
{
private:
    int id;
    string name;

public:
    // Constructor
    Student(int studentId, string studentName) : id(studentId), name(studentName) {}

    // Getter for the student ID
    int getId() const 
    {
        return id;
    }

    // Getter for the student name
    string getName() const 
    {
        return name;
    }

    // Display student information
    void display() const 
    {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

// Function to search for a student in a vector using a lambda function
void searchStudentById(const vector<Student>& students, int id) 
{
    // Use find_if with a lambda function
    auto it = find_if(students.begin(), students.end(), [id](const Student& student) 
        {
        return student.getId() == id;
        });

    // Check if the student was found
    if (it != students.end()) 
    {
        cout << "Student found: ";
        it->display();
    }
    else 
    {
        cout << "Student with ID " << id << " not found." << endl;
    }
}

// Function to search for a student by name using a lambda function
void searchStudentByName(const vector<Student>& students, const string& name) 
{
    auto it = find_if(students.begin(), students.end(), [name](const Student& student) {
        return student.getName() == name;
        });

    if (it != students.end()) 
    {
        cout << "Student found: ";
        it->display();
    }
    else 
    {
        cout << "Student with name \"" << name << "\" not found." << endl;
    }
}

int main() 
{
    // Create a list of students
    vector<Student> students = 
    {
        Student(1, "Alice"),
        Student(2, "Bob"),
        Student(3, "Charlie"),
        Student(4, "Diana")
    };

    // Search for a student by ID
    searchStudentById(students, 2);

    // Search for a student by name
    searchStudentByName(students, "Charlie");

    return 0;
}
