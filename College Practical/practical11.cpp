#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Patient {
    string name;
    int priority;

    // Overloading the comparison operator for priority queue
    bool operator<(const Patient& other) const {
        return priority < other.priority;
    }
};

// Function to display all Patients in the priority queue
void display(priority_queue<Patient> queue) {
    if (queue.empty()) {
        cout << "No patients in the queue!\n";
        return;
    }

    cout << "Patients in the queue:\n";
    while (!queue.empty()) {
        Patient patient = queue.top();
        queue.pop();
        cout << "Name: " << patient.name << " (Priority: " << patient.priority << ")\n";
    }
}

int main() {
    priority_queue<Patient> hospitalQueue;

    int choice;
    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Add a patient\n";
        cout << "2. Serve the next patient\n";
        cout << "3. Display all patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Patient newPatient;
                cout << "Enter patient name: ";
                cin >> newPatient.name;
                cout << "Enter patient priority (1 - Serious, 2 - Non-Serious, 3 - General Checkup): ";
                cin >> newPatient.priority;

                hospitalQueue.push(newPatient);
                cout << "Patient added to the queue!\n";
                break;
            }
            case 2:
                if (!hospitalQueue.empty()) {
                    Patient servingPatient = hospitalQueue.top();
                    hospitalQueue.pop();
                    cout << "Serving patient: " << servingPatient.name << " (Priority: " << servingPatient.priority << ")\n";
                } else {
                    cout << "No patients in the queue!\n";
                }
                break;
            case 3:
                display(hospitalQueue);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
