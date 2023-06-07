#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

// Function to add a new student record to the file
void addStudentRecord(const Student& student) {
    ofstream file("student_records.txt", ios::app); // Open the file in append mode

    if (file) {
        file << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
        cout << "Student record added successfully!" << endl;
    } else {
        cout << "Error opening the file." << endl;
    }

    file.close();
}

// Function to delete a student record from the file
void deleteStudentRecord(int rollNumber) {
    ifstream inputFile("student_records.txt");
    ofstream outputFile("temp.txt"); // Temporary file for writing the updated records

    bool found = false;
    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        int currentRollNumber;
        string name, division, address;

        if (iss >> currentRollNumber >> name >> division >> address) {
            if (currentRollNumber != rollNumber) {
                outputFile << line << endl; // Write the record to the temporary file
            } else {
                found = true;
            }
        }
    }

    inputFile.close();
    outputFile.close();

    if (found) {
        remove("student_records.txt");    // Delete the original file
        rename("temp.txt", "student_records.txt");    // Rename the temporary file to the original file
        cout << "Student record deleted successfully!" << endl;
    } else {
        cout << "Student record not found." << endl;
        remove("temp.txt");    // Delete the temporary file
    }
}

// Function to display the information of a particular student
void displayStudentRecord(int rollNumber) {
    ifstream file("student_records.txt");
    bool found = false;
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        int currentRollNumber;
        string name, division, address;

        if (iss >> currentRollNumber >> name >> division >> address) {
            if (currentRollNumber == rollNumber) {
                found = true;
                cout << "Student Details:" << endl;
                cout << "Roll Number: " << currentRollNumber << endl;
                cout << "Name: " << name << endl;
                cout << "Division: " << division << endl;
                cout << "Address: " << address << endl;
                break;
            }
        }
    }

    file.close();

    if (!found) {
        cout << "Student record not found." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "-------------------" << endl;
        cout << "Student Information" << endl;
        cout << "-------------------" << endl;
        cout << "1. Add Student Record" << endl;
        cout << "2. Delete Student Record" << endl;
        cout << "3. Display Student Record" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Student student;
                cout << "Enter Roll Number: ";
                cin >> student.rollNumber;
                cout << "Enter Name: ";
                cin.ignore(); // Ignore the newline character left in the input buffer
                getline(cin, student.name);
                cout << "Enter Division: ";
                getline(cin, student.division);
                cout << "Enter Address: ";
                getline(cin, student.address);
                addStudentRecord(student);
                break;
            }
            case 2: {
                int rollNumber;
                cout << "Enter Roll Number of student to delete: ";
                cin >> rollNumber;
                deleteStudentRecord(rollNumber);
                break;
            }
            case 3: {
                int rollNumber;
                cout << "Enter Roll Number of student to display: ";
                cin >> rollNumber;
                displayStudentRecord(rollNumber);
                break;
            }
            case 4:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

