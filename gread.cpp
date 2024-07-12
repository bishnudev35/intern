#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    vector<int> subject;
    string grade;
    int avg_marks;

    // Default constructor
    Student() : name("Unknown"), grade("F"), avg_marks(0) {
        subject = vector<int>(6, 0);
    }

    // Parameterized constructor
    Student(string s) : name(s) {
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            cout << "Enter the subject " << i + 1 << " marks: ";
            int x;
            cin >> x;
            sum += x;
            subject.push_back(x);
        }
        avg_marks = sum / 6;
        setGrade(avg_marks); // Calculate grade based on average
    }

    void setGrade(int average) {
        if (average >= 60) grade = "A";
        else if (average >= 45) grade = "B";
        else if (average >= 30) grade = "C";
        else grade = "D";
    }
};

void take_detail(map<string, Student>& mp, vector<pair<int, string>>& gread_map) {
    cout << "Enter student ID: ";
    string st;
    cin >> st;

    // Clear the newline character left in the buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter student name: ";
    string student_name;
    getline(cin, student_name); // Use getline to read the full name

    Student std(student_name);
    mp[st] = std; // Insert object directly
    gread_map.push_back(make_pair(std.avg_marks, st)); // Add to gread_map
}

void print_allstudent(const map<string, Student>& mp) {
    for (const auto& it : mp) {
        // Print student ID
        cout << "Student ID: " << it.first << endl;

        // Access the Student object
        const Student& st = it.second;

        // Print student's name
        cout << "Name: " << st.name << endl;

        // Print marks for each subject
        for (size_t i = 0; i < st.subject.size(); ++i) {
            cout << "Subject " << i + 1 << " marks: " << st.subject[i] << endl;
        }

        // Print overall percentage and grade
        cout << "Overall Percentage: " << st.avg_marks << "%" << endl;
        cout << "Grade: " << st.grade << endl;

        // Print a separator for clarity
        cout << "-------------------------" << endl;
    }
}

// Comparator function for sorting based on average marks (descending order)
bool comparePairs(const pair<int, string>& a, const pair<int, string>& b) {
    return a.first > b.first; // Sort in descending order
}

void sortGreadMap(vector<pair<int, string>>& gread_map) {
    // Sort the vector using the comparator
    sort(gread_map.begin(), gread_map.end(), comparePairs);
}

void print_student_by_id(const map<string, Student>& mp, const string& id) {
    auto it = mp.find(id);
    if (it != mp.end()) {
        const Student& st = it->second;
        cout << "Student ID: " << id << endl;

        // Print student's name
        cout << "Name: " << st.name << endl;

        // Print marks for each subject
        for (size_t i = 0; i < st.subject.size(); ++i) {
            cout << "Subject " << i + 1 << " marks: " << st.subject[i] << endl;
        }

        // Print overall percentage and grade
        cout << "Overall Percentage: " << st.avg_marks << "%" << endl;
        cout << "Grade: " << st.grade << endl;
    } else {
        // Print error message if ID is not found
        cout << "This is an invalid ID: " << id << endl;
    }

    // Print a separator for clarity
    cout << "-------------------------" << endl;
}


void Rank(const map<string, Student>& mp, vector<pair<int, string>>& gread_map) {
    sortGreadMap(gread_map);
    for (size_t i = 0; i < gread_map.size(); i++) {
        cout << endl << "Rank " << i + 1 << ":" << endl;
        print_student_by_id(mp, gread_map[i].second);
        if(i>4){
            break;

        }
    }
}
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Display all student details\n";
    cout << "2. Display student rank\n";
    cout << "3. Search student details by ID\n";
    cout << "4. Add new student details\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    map<string, Student> mp;
    vector<pair<int, string>> gread_map;
    char choice;
    cout<<"Enter all the students detalis :"<<endl;
    do {
        take_detail(mp, gread_map);
        cout << "Do you want to enter another student? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

  int menuChoice;
    do {
        displayMenu();
        cin >> menuChoice;
        switch (menuChoice) {
            case 1:
                cout << "\nAll student details:\n";
                print_allstudent(mp);
                break;
            case 2:
                cout << "\nRanking of students based on grades:\n";
                Rank(mp, gread_map);
                break;
            case 3: {
                cout << "Enter student ID to search: ";
                string id;
                cin >> id;
                print_student_by_id(mp, id);
                break;
            }
            case 4:
                take_detail(mp, gread_map);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (menuChoice != 5);

    return 0;
}
