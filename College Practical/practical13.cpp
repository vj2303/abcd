#include <iostream>
#include <fstream>

using namespace std;

struct Employee {
    int emp_id;
    string name;
    string designation;
    double salary;
};

void addEmployee(Employee emp) {
    ofstream file("employee.txt", ios::app);
    if (file.is_open()) {
        file << emp.emp_id << " " << emp.name << " " << emp.designation << " " << emp.salary << endl;
        file.close();
        cout << "Employee added successfully." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

void deleteEmployee(int emp_id) {
    ifstream inFile("employee.txt");
    ofstream outFile("temp.txt");
    bool found = false;
    Employee emp;

    while (inFile >> emp.emp_id >> emp.name >> emp.designation >> emp.salary) {
        if (emp.emp_id != emp_id) {
            outFile << emp.emp_id << " " << emp.name << " " << emp.designation << " " << emp.salary << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    remove("employee.txt");
    rename("temp.txt", "employee.txt");

    if (found) {
        cout << "Employee deleted successfully." << endl;
    } else {
        cout << "Employee does not exist." << endl;
    }
}

void displayEmployee(int emp_id) {
    ifstream file("employee.txt");
    Employee emp;
    bool found = false;

    while (file >> emp.emp_id >> emp.name >> emp.designation >> emp.salary) {
        if (emp.emp_id == emp_id) {
            cout << "Employee ID: " << emp.emp_id << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Designation: " << emp.designation << endl;
            cout << "Salary: " << emp.salary << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Employee does not exist." << endl;
    }
}

int main() {
    int choice, emp_id;
    Employee emp;

    do {
        cout << "Employee Management Menu" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> emp.emp_id;
                cout << "Enter Name: ";
                cin >> emp.name;
                cout << "Enter Designation: ";
                cin >> emp.designation;
                cout << "Enter Salary: ";
                cin >> emp.salary;
                addEmployee(emp);
                break;
            case 2:
                cout << "Enter Employee ID to delete: ";
                cin >> emp_id;
                deleteEmployee(emp_id);
                break;
            case 3:
                cout << "Enter Employee ID to display: ";
                cin >> emp_id;
                displayEmployee(emp_id);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}




































// #include <iostream>
// #include <fstream>
// using namespace std;

// class Employee {
//     int code;
//     char name[30];
//     float salary;


// public:
//     int getEmpCode() { 
//         return code; 
//         }
//     int getSalary() { 
//         return salary; 
//         }


//     void read() {
//         cout << "Enter employee code: ";
//         cin >> code;
//         cin.ignore();
//         cout << "Enter employee name: ";
//         cin.getline(name, 30);
//         cout << "Enter employee salary: ";
//         cin >> salary;
//     }

//     void display() {
//         cout << code << " " << name << "\t" << salary << endl;
//     }

//     void updateSalary(float s) {
//         salary = s;
//     }




      
// };

// fstream file;

// void deleteExistingFile() {
//     remove("EMPLOYEE.DAT");
// } 




// void appendToFile() {
//     Employee x;
//     char ch = 'y';

//     file.open("EMPLOYEE.DAT", ios::binary | ios::out | ios::app);
//     if (!file) {
//         cout << "ERROR IN OPENING FILE\n";
//         return;
// }




//  while (ch == 'y' || ch == 'Y') {
//         x.read();
//         file.write((char*)&x, sizeof(x));
//         cout << "Do you want to add more records (y/n)? ";
//         cin >> ch;
//         cin.ignore();
//     }

//     file.close();
// }

// void displayAll() {
//     Employee x;

//     file.open("EMPLOYEE.DAT", ios::binary | ios::in);
//     if (!file) {
//         cout << "ERROR IN OPENING FILE\n";
//         return;
//     }

//     cout << "\nEmployee records with salary between 10000 and 20000:\n";

//     while (file.read((char*)&x, sizeof(x))) {
//         if (x.getSalary() >= 10000 && x.getSalary() <= 20000) {
//             x.display();
//         }
//     }

//     file.close();
// }

// void searchForRecord() {
//     Employee x;
//     int c;
//     int isFound = 0;

//     cout << "Enter employee code to search for: ";
//     cin >> c;

//     file.open("EMPLOYEE.DAT", ios::binary | ios::in);
//     if (!file) {
//         cout << "ERROR IN OPENING FILE\n";
//         return;
//     }

//     while (file.read((char*)&x, sizeof(x))) {
//         if (x.getEmpCode() == c) {
//             x.display();
//             isFound = 1;
//             break;
//         }
//     }
//     file.close();

//     if (!isFound) {
//         cout << "Record not found.\n";
//     }
// }

// void increaseSalary() {
//     Employee x;
//     int c;
//     float sal;

//     cout << "Enter employee code: ";
//     cin >> c;
//     cout << "Enter salary increment: ";
//     cin >> sal;

//     file.open("EMPLOYEE.DAT", ios::binary | ios::in | ios::out);
//     if (!file) {
//         cout << "ERROR IN OPENING FILE\n";
//         return;
//     }
//     while (file.read((char*)&x, sizeof(x))) {
//         if (x.getEmpCode() == c) {
//             x.updateSalary(x.getSalary() + sal);
//             file.seekp(-sizeof(x), ios::cur);
//             file.write((char*)&x, sizeof(x));
//             cout << "Salary updated successfully.\n";
//             break;
//         }
//     }
//     file.close();
// }

// void insertRecord() {
//     Employee newEmp;
//     newEmp.read();

//     file.open("EMPLOYEE.DAT", ios::binary | ios::in | ios::out);
//     if (!file) {
//         cout << "ERROR IN OPENING FILE\n";
//         return;
//     }
//     Employee x;

//     while (file.read((char*)&x, sizeof(x))) {
//         if (x.getEmpCode() > newEmp.getEmpCode()) {
//             file.seekp(-sizeof(x), ios::cur);
//             file.write((char*)&newEmp, sizeof(newEmp));
//             file.write((char*)&x, sizeof(x));
//             cout << "Record inserted successfully.\n";
//             break;
//         }
//     }

//     if (!file.eof()) {
//         file.write((char*)&newEmp, sizeof(newEmp));
//         cout << "Record inserted successfully.\n";
//     }

//     file.close();
// }

// int main() {
//     int choice;

//     deleteExistingFile();

//     do {
//         cout << "\n***** MENU *****\n";
//         cout << "1. Append to file\n";
//         cout << "2. Display all records with salary between 10000 and 20000\n";
//         cout << "3. Search for a record\n";
//         cout << "4. Increase salary\n";
//         cout << "5. Insert a record in a sorted file\n";
//         cout << "6. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 appendToFile();
//                 break;
//             case 2:
//                 displayAll();
//                 break;
//             case 3:
//                 searchForRecord();
//                 break;
//             case 4:
//                 increaseSalary();
//                 break;
//             case 5:
//                 insertRecord();
//                 break;
//             case 6:
//                 cout << "Exiting program.\n";
//                 break;
//             default:
//                 cout << "Invalid choice. Please try again.\n";
//         }
//     } while (choice != 6);

//     return 0;
// }






// // #include <iostream>
// // #include <fstream>
// // #include <iomanip>

// // using namespace std;

// // // Structure to hold employee information
// // struct Employee {
// //     int id;
// //     string name;
// //     string designation;
// //     double salary;
// // };

// // // Function to display employee information
// // void displayEmployee(const Employee& emp) {
// //     cout << "Employee ID: " << emp.id << endl;
// //     cout << "Name: " << emp.name << endl;
// //     cout << "Designation: " << emp.designation << endl;
// //     cout << "Salary: " << emp.salary << endl;
// // }

// // // Function to add employee information
// // void addEmployee() {
// //     Employee emp;
// //     cout << "Enter employee ID: ";
// //     cin >> emp.id;
// //     cout << "Enter employee name: ";
// //     cin.ignore();
// //     getline(cin, emp.name);
// //     cout << "Enter employee designation: ";
// //     getline(cin, emp.designation);
// //     cout << "Enter employee salary: ";
// //     cin >> emp.salary;

// //     ofstream outFile("employee.dat", ios::binary | ios::app);
// //     outFile.write(reinterpret_cast<const char*>(&emp), sizeof(Employee));
// //     outFile.close();

// //     cout << "Employee added successfully!" << endl;
// // }

// // // Function to delete employee information
// // void deleteEmployee(int empId) {
// //     ifstream inFile("employee.dat", ios::binary);
// //     ofstream outFile("temp.dat", ios::binary);

// //     Employee emp;
// //     bool found = false;

// //     while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
// //         if (emp.id == empId) {
// //             found = true;
// //             continue;
// //         }
// //         outFile.write(reinterpret_cast<const char*>(&emp), sizeof(Employee));
// //     }

// //     inFile.close();
// //     outFile.close();

// //     if (found) {
// //         remove("employee.dat");
// //         rename("temp.dat", "employee.dat");
// //         cout << "Employee deleted successfully!" << endl;
// //     } else {
// //         remove("temp.dat");
// //         cout << "Employee not found!" << endl;
// //     }
// // }

// // // Function to display employee information
// // void displayEmployeeInfo(int empId) {
// //     ifstream inFile("employee.dat", ios::binary);

// //     Employee emp;
// //     bool found = false;

// //     while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
// //         if (emp.id == empId) {
// //             found = true;
// //             displayEmployee(emp);
// //             break;
// //         }
// //     }

// //     inFile.close();

// //     if (!found) {
// //         cout << "Employee not found!" << endl;
// //     }
// // }

// // int main() {
// //     int choice;
// //     int empId;

// //     do {
// //         cout << "1. Add employee" << endl;
// //         cout << "2. Delete employee" << endl;
// //         cout << "3. Display employee information" << endl;
// //         cout << "4. Exit" << endl;
// //         cout << "Enter your choice: ";
// //         cin >> choice;

// //         switch (choice) {
// //             case 1:
// //                 addEmployee();
// //                 break;
// //             case 2:
// //                 cout << "Enter employee ID to delete: ";
// //                 cin >> empId;
// //                 deleteEmployee(empId);
// //                 break;
// //             case 3:
// //                 cout << "Enter employee ID to display information: ";
// //                 cin >> empId;
// //                 displayEmployeeInfo(empId);
// //                 break;
// //             case 4:
// //                 cout << "Exiting..." << endl;
// //                 break;
// //             default:
// //                 cout << "Invalid choice!" << endl;
// //         }

// //         cout << endl;
// //     } while (choice != 4);

// //     return 0;
// // }
