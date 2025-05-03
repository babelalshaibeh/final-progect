#include <iostream>
#include <string>
#include <vector>
#include <map>
//#include <limits>

using namespace std;

struct Specialization {
    string name;
    string description;
    int duration; 
    vector<string> courses;
};


struct College {
    string name;
    map<string, string> admissionRequirements;
    vector<Specialization> specializations;
};


struct Student {
    string name;
    string id;
    string college;
    string specialization;
    bool parallelProgram;
};


vector<College> colleges;
vector<Student> registeredStudents;


void initializeData() {
    // Computer Science College
    College cs;
    cs.name = "College of Computer Science and Information";
    cs.admissionRequirements = {
        {"High School", "Minimum 80%  "},
        {"Aptitude Test", "Minimum 75%"},
        
    };
    
    Specialization csSpec1;
    csSpec1.name = "Computer Science";
    csSpec1.description = "Program covering programming fundamentals, data structures, and AI\n\n";
    csSpec1.duration = 4;
    csSpec1.courses = {"Programming 1", "Data Structures", "Algorithms", "Database Systems\n\n"};
    
    Specialization csSpec2;
    csSpec2.name = "Software Engineering";
    csSpec2.description = "Program focused on software development and management\n\n";
    csSpec2.duration = 4;
    csSpec2.courses = {"Software Engineering", "Web Development", "Software Testing", "Project Management\n\n"};
    
    cs.specializations.push_back(csSpec1);
    cs.specializations.push_back(csSpec2);
    
    colleges.push_back(cs);
    
    // Engineering College
    College eng;
    eng.name = "College of Engineering";
    eng.admissionRequirements = {
        {"High School", "Minimum 85% in scientific track"},
        {"Aptitude Test", "Minimum 80%"},
        
    };
    
    Specialization engSpec1;
    engSpec1.name = "Computer Engineering";
    engSpec1.description = "Program combining electrical engineering and computer science\n\n";
    engSpec1.duration = 5;
    engSpec1.courses = {"Electrical Circuits", "Digital Electronics", "Signal Processing", "Computer Networks\n\n"};
    
    Specialization engSpec2;
    engSpec2.name = "Industrial Engineering";
    engSpec2.description = "Program focused on systems and process optimization\n\n";
    engSpec2.duration = 5;
    engSpec2.courses = {"Operations Research", "Human Factors Engineering", "Manufacturing Systems", "Quality Management\n\n"};
    
    eng.specializations.push_back(engSpec1);
    eng.specializations.push_back(engSpec2);
    
    colleges.push_back(eng);
}

// Display main menu
void showMainMenu() {
  
    
    cout << "      University Admission System\n";
    cout << "=====================================\n";
    cout << "     1. View Available Specializations\n";
    cout << "     2. Admission Requirements\n";
    cout << "     3. Registration Process\n";
    cout << "     4. Parallel Program Information\n";
     cout << "     5. View Registered Students\n";
    cout << "     6. Exit\n";
    cout << "=====================================\n";
    cout << "           Enter your choice: ";
}

// Display available specializations
void showSpecializations() {
    
    cout << "Available University Specializations:\n";
  
    
    for (const College& college : colleges) {
        cout << "\nCollege: " << college.name << "\n\n";
        cout << "Specializations:\n\n";
        
        for (const Specialization& spec : college.specializations) {
            cout << "- " << spec.name << " (" << spec.duration << " years)\n";
            cout << "     *Description*: " << spec.description << "\n";
            cout << "     *Core Courses*: ";
            
            for (const string& course : spec.courses) {
                cout << course << ", ,";
            }
            cout << "\n";
        }
    }
    
    cout << "\nPress any key to return to main menu...";
    cin.ignore();
    cin.get();
}

// Display admission requirements
void showAdmissionRequirements() {
    
    cout << "College Admission Requirements:\n\n";
    
    for (const College& college : colleges) {
        cout << "\nCollege: " << college.name << "\n";
        cout << "     *Requirements*:\n";
        
        for (const auto& req : college.admissionRequirements) {
            cout << "- " << req.first << ": " << req.second << "\n";
        }
    }
    
    cout << "\n*Note*\n: Requirements may change according to university policy each year.\n";
    cout << "\nPress any key to return to main menu...";
    cin.ignore();
    cin.get();
}

// Registration process
void registrationProcess() {
   
    cout << "Registration Process\n";
    
    if (colleges.empty()) {
        cout << "No colleges available for registration at this time.\n";
        cout << "\nPress any key to return to main menu...";
        cin.ignore();
        cin.get();
        return;
    }
    
    Student newStudent;
    
    cout << "Full Name: ";
    getline(cin, newStudent.name);
    
    cout << "University ID: ";
    getline(cin, newStudent.id);
    
    // Display available colleges
    cout << "\nAvailable Colleges:\n";
    for (int i = 0; i < colleges.size(); i++) {
        cout << i+1 << ". " << colleges[i].name << "\n";
    }
    
    int collegeChoice;
    cout << "Select college (number): ";
    cin >> collegeChoice;
    
    if (collegeChoice < 1 || collegeChoice > colleges.size()) {
        cout << "Invalid selection!\n";
        cout << "\nPress any key to return to main menu...";
        cin.ignore();
        cin.get();
        return;
    }
    
    newStudent.college = colleges[collegeChoice-1].name;
    
    
    
    
    // Display specializations in selected college
    cout << "\nSpecializations available in " << newStudent.college << ":\n";
    for (int i = 0; i < colleges[collegeChoice-1].specializations.size(); i++) {
        cout << i+1 << ". " << colleges[collegeChoice-1].specializations[i].name << "\n";
    }
    
    int specChoice;
    cout << "Select specialization (number): ";
    cin >> specChoice;
    
    if (specChoice < 1 || specChoice > colleges[collegeChoice-1].specializations.size()) {
        cout << "Invalid selection!\n";
        cout << "\nPress any key to return to main menu...";
        cin.ignore();
        cin.get();
        return;
    }
    
    newStudent.specialization = colleges[collegeChoice-1].specializations[specChoice-1].name;
    
    char parallelChoice;
    cout << "Would you like to join the Parallel Program? (y/n): ";
    cin >> parallelChoice;
    
    newStudent.parallelProgram = (parallelChoice == 'y' || parallelChoice == 'Y');
    
    registeredStudents.push_back(newStudent);
    
    cout << "\nRegistration successful!\n";
    cout << "Your information:\n";
    cout << "Name: " << newStudent.name << "\n";
    cout << "University ID: " << newStudent.id << "\n";
    cout << "College: " << newStudent.college << "\n";
    cout << "Specialization: " << newStudent.specialization << "\n";
    cout << "Parallel Program: " << (newStudent.parallelProgram ? "Yes" : "No") << "\n";
    
    cout << "\nPress any key to return to main menu...";
    cin.ignore();
    cin.get();
}

// Parallel program information
void showParallelProgramInfo() {
 
    cout << "Parallel Program\n";
    
    
    cout << "What is the Parallel Program?\n";
    cout << "The Parallel Program is an academic program that provides university education opportunities\n";
    cout << "for students who didn't get admission in the regular program, with higher tuition fees.\n\n";
    
    cout << "Program Features:\n";
    cout << "- Same curriculum as the regular program\n";
    cout << "- Same faculty members\n";
    cout << "- Same awarded degrees\n\n";
    
    cout << "Tuition Fees:\n";
    cout << "- Fees vary by college and specialization\n";
    cout << "- Average fees between 20,000 to 40,000 SAR annually\n\n";
    
    cout << "Admission Requirements:\n";
    cout << "- High school diploma\n";
    cout << "- Meeting college requirements (typically 5-10% lower than regular program)\n\n";
    
    cout << "Note: Transfer from parallel to regular program is possible according to university policies.\n";
    
    cout << "\nPress any key to return to main menu...";
    cin.ignore();
    cin.get();
}

void showRegisteredStudents() {

    cout << "Registered Students\n\n";
   
    
    if (registeredStudents.empty()) {
        cout << "No students have registered yet.\n";
    } else {
        cout << "Total Registered Students: " << registeredStudents.size() << "\n\n";
        
        for (const Student& student : registeredStudents) {
            cout << "Student Name: " << student.name << "\n";
            cout << "University ID: " << student.id << "\n";
            cout << "College: " << student.college << "\n";
            cout << "Specialization: " << student.specialization << "\n";
            cout << "Parallel Program: " << (student.parallelProgram ? "Yes" : "No") << "\n";
           
        }
    }
    
    cout << "\nPress any key to return to main menu...";
    cin.ignore();
    cin.get();
}
int main() {
    initializeData();
    
    int choice;
    do {
        showMainMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                showSpecializations();
                break;
            case 2:
                showAdmissionRequirements();
                break;
            case 3:
                registrationProcess();
                break;
            case 4:
                showParallelProgramInfo();
                break;
            case 5:
                showRegisteredStudents();
                break;
            case 6:
                cout << "Thank you for using the University Admission System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (choice != 6);
    
    return 0;
}