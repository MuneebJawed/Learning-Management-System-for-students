#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class User {
public:
    void login() {
        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (password.length() != 7 || password.substr(0, 4) != "2023") {
            cout << "Invalid username or password" << endl;
            return;
        }

        cout << "LOGIN ACCESS!" << endl;
        cout << "1. Course Information" << endl;
        cout << "2. Track Progress" << endl;
        cout << "3. Search Courses" << endl;
        cout << "Select(1-3): ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                showCourseInfo();
                break;
            case 2:
                trackProgress();
                break;
            case 3:
                searchCourses();
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

private:
    void showCourseInfo() {
        ifstream courseinfo("info.txt");
        if (courseinfo.is_open()) {
            string line;
            while (getline(courseinfo, line)) {
                cout << line << endl;
            }
            courseinfo.close();
        } else {
            cout << "File not available!" << endl;
        }
    }

    void trackProgress() {
        int courseEnroll;
        cout << "TRACKING PROGRESS" << endl;
        cout << "Enter number of Courses you are enrolled in: ";
        cin >> courseEnroll;

        double totalMarks = 0, obtainedMarks = 0;
        for (int i = 0; i < courseEnroll; i++) {
            string courseCode;
            int totalCourseMarks, marks;
            cout << "Course " << i + 1 << " Code: ";
            cin >> courseCode;
            cout << "Course " << i + 1 << " Total Marks: ";
            cin >> totalCourseMarks;
            cout << "Course " << i + 1 << " Marks: ";
            cin >> marks;
            totalMarks += totalCourseMarks;
            obtainedMarks += marks;
        }

        double percentage = (obtainedMarks / totalMarks) * 100;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Total Marks Obtained: " << obtainedMarks << endl;
        cout << "Percentage: " << percentage << "%" << endl;

        if (percentage >= 80) {
            cout << "Outstanding Performance" << endl;
        } else if (percentage >= 60) {
            cout << "Good Performance" << endl;
        } else if (percentage >= 40) {
            cout << "Average Performance" << endl;
        } else {
            cout << "Poor Performance" << endl;
        }
    }

    void searchCourses() {
        string search;
        char choice;
        do {
            cout << "Enter the Course Code: ";
            cin >> search;
            ifstream file("info.txt");
            if (file.is_open()) {
                string line;
                int lineNumber = 1;
                bool found = false;
                while (getline(file, line)) {
                    if (line.find(search) != string::npos) {
                        cout << "The Course Code is in line " << lineNumber << endl;
                        found = true;
                    }
                    lineNumber++;
                }
                if (!found) {
                    cout << "Course Code not found" << endl;
                }
                file.close();
            } else {
                cout << "File not created" << endl;
            }
            cout << "Continue? (y/n): ";
            cin >> choice;
        } while (tolower(choice) == 'y');
    }
};

class Admin {
public:
    void reg() {
        ofstream input("Registration.txt", ios::app);
        if (!input.is_open()) {
            cout << "Failed to open file!" << endl;
            return;
        }

        input << "New Student Data" << endl;
        int numStudents;
        cout << "Enter number of students: ";
        cin >> numStudents;
        cin.ignore(); // Clear newline left in the input buffer from previous input

        for (int i = 0; i < numStudents; i++) {
            string studentName, fatherName, city, degree;
            int age, year;

            cout << "Enter the name for student " << i + 1 << ": ";
            getline(cin, studentName);
            input << "Name: " << studentName << endl;

            cout << "Enter the Father name for student " << i + 1 << ": ";
            getline(cin, fatherName);
            input << "Father: " << fatherName << endl;

            cout << "Enter the Age for student " << i + 1 << ": ";
            cin >> age;
            input << "Age: " << age << endl;
            cin.ignore(); // Clear newline left in the input buffer from previous input

            cout << "Enter the City for student " << i + 1 << ": ";
            getline(cin, city);
            input << "City: " << city << endl;

            cout << "Enter the Degree for student " << i + 1 << ": ";
            getline(cin, degree);
            input << "Degree: " << degree << endl;

            cout << "Enter the Year for student " << i + 1 << ": ";
            cin >> year;
            input << "Year: " << year << endl;
            cin.ignore(); // Clear newline left in the input buffer from previous input

            input << "---------------------------------------" << endl;
        }
        input.close();
    }
};

int main() {
    cout << "LEARNING MANAGEMENT SYSTEM" << endl;
    cout << "Please Select: " << endl;
    cout << "1. Login" << endl;
    cout << "2. Register Accounts" << endl;
    cout << "3. Courses Information" << endl;
    cout << "4. Track Progress" << endl;
    cout << "5. Exit" << endl;
    cout << "Select: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            User().login();
            break;
        case 2:
            Admin().reg();
            break;
        case 3:
        case 4:
            cout << "Login First!" << endl;
            User().login();
            break;
        case 5:
            cout << "Thank you for using LMS" << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
    }

    return 0;
}
