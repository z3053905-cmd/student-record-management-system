#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Base Class: Person
class Person {
public:
    string name;
    int id;

    Person() {
        name = "Unknown";
        id = 0;
    }

    Person(string n, int i) {
        name = n;
        id = i;
    }
};

// Derived Class: Student (Inheritance)
class Student : public Person {
public:
    string degree;
    float gpa[3]; // Array to store GPAs of 3 semesters

    // Constructor
    Student(string n, int i, string deg, float g1, float g2, float g3) : Person(n, i) {
        degree = deg;
        gpa[0] = g1;
        gpa[1] = g2;
        gpa[2] = g3;
    }

    // Function to display data
    void displayStudent() {
        cout << "Student ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Degree: " << degree << endl;
        cout << "Semester GPAs: ";
        
        // For Loop to iterate through array
        for (int i = 0; i < 3; i++) {
            cout << gpa[i] << "  ";
        }
        cout << "\n-------------------------\n";
    }
};

int main() {
    cout << "=== University Student Record System ===\n\n";

    // Creating Student Objects
    Student s1("Zubair Amin", 2927, "BS CS", 3.5, 3.7, 3.8);
    Student s2("Ali Ahmad", 1022, "BS SE", 3.2, 3.4, 3.5);
    Student s3("Asad Khan", 4055, "BS IT", 2.9, 3.1, 3.0);

    // Array of Objects
    Student university_students[3] = {s1, s2, s3};

    // Displaying on console using For Loop
    for (int i = 0; i < 3; i++) {
        university_students[i].displayStudent();
    }

    // File Handling: Writing Data to Text File
    ofstream studentFile("student_records.txt");
    
    if (studentFile.is_open()) {
        studentFile << "=== ENROLLED STUDENTS DATABASE ===\n\n";
        
        for (int i = 0; i < 3; i++) {
            studentFile << "ID: " << university_students[i].id << "\n";
            studentFile << "Name: " << university_students[i].name << "\n";
            studentFile << "Degree: " << university_students[i].degree << "\n";
            studentFile << "GPAs: " << university_students[i].gpa[0] << ", " 
                        << university_students[i].gpa[1] << ", " 
                        << university_students[i].gpa[2] << "\n\n";
        }
        
        studentFile.close();
        cout << "\n[Success] All student records saved to 'student_records.txt' successfully!" << endl;
    } else {
        cout << "[Error] Unable to open file for writing!" << endl;
    }

    return 0;
}
