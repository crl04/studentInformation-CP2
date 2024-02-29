#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100; // Maximum number of students

struct Student {
    // Information
    string name, sex, course, year, standing;
    int age = 0, id = 0;
    bool deleted = false;
};

void AddStudent(Student students[], int &studentCounter);
void ShowStudents(const Student students[], int studentCounter);
void DeleteStudent(Student students[], int &studentCounter);

int main() {
    int choice, studentCounter = 0;
    Student students[MAX_STUDENTS];

    do {
    	cout << "==============\n";
    	cout << "MAIN MENU\n";
    	cout << "==============" << endl;
        cout << "1. Add Student\n"
             << "2. Show Students\n"
             << "3. Delete Student\n"
             << "4. Exit\n";
        cout << "Enter your choice: ";
        cout << ">> ";
        cin >> choice;
        cout << "\n\n";
        

        switch (choice) {
            case 1:
                AddStudent(students, studentCounter);
                system("cls");
                break;
            case 2:
                ShowStudents(students, studentCounter);
                break;
            case 3:
                DeleteStudent(students, studentCounter);
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (true);
}

void AddStudent(Student students[], int &studentCounter) {
    if (studentCounter >= MAX_STUDENTS) {
        cout << "Maximum number of students reached!" << endl;
        return;
    }

    Student &student = students[studentCounter];
    cout << "-- Student Information Form --\n\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Age: ";
    cin >> student.age;
    cin.ignore();
    cout << "Sex: ";
    getline(cin, student.sex);
    cout << "Course: ";
    getline(cin, student.course);
    cout << "Year: ";
    getline(cin, student.year);
    cout << "ID: ";
    cin >> student.id;

    studentCounter++;
}


void ShowStudents(const Student students[], int studentCount) {
    const int STUDENTS_PER_PAGE = 5;
    int totalPages = (studentCount - 1) / STUDENTS_PER_PAGE + 1;
    int currentPage = 0;

    char option;
    do {
        system("cls");
        cout << "Page " << currentPage + 1 << " of " << totalPages << "\n";
        for (int i = currentPage * STUDENTS_PER_PAGE; i < min((currentPage + 1) * STUDENTS_PER_PAGE, studentCount); ++i) {
            const Student& student = students[i];
            cout << "Name: " << student.name << endl;
            cout << "Age: " << student.age << endl;
            cout << "Sex: " << student.sex << endl;
            cout << "Course: " << student.course << endl;
            cout << "Year: " << student.year << endl;
            cout << "ID: " << student.id << endl;
            cout << "====================================================" << endl;
        }

        cout << "N - Next Page, P - Previous Page, E - Exit to Main Menu\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 'N':
            case 'n':
                if (currentPage < totalPages - 1) {
                    currentPage++;
                }
                break;
            case 'P':
            case 'p':
                if (currentPage > 0) {
                    currentPage--;
                }
                break;
        }
    } while (option != 'E' && option != 'e');
}

void DeleteStudent(Student students[], int &studentCounter) {
    if (studentCounter == 0) {
        cout << "No students to delete." << endl;
        return;
    }

    int id;
    cout << "Enter ID of student to delete: ";
    cin >> id;

    for (int i = 0; i < studentCounter; ++i) {
        if (students[i].id == id && !students[i].deleted) {
            students[i].deleted = true;
            cout << "Student with ID " << id << " deleted successfully." << endl;
            return;
        }
    }

    cout << "Student with ID " << id << " not found or already deleted." << endl;
}
