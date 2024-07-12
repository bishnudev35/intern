#include <bits/stdc++.h>
using namespace std;

class bank {
public:
    string name;
    string accountNo;
    string dob;
    double balance;

    // Constructor
    bank(const string& name, const string& dob, const string& ac, double initial_balance = 0.0)
        : name(name), accountNo(ac), dob(dob), balance(initial_balance) {}

    // Default Constructor
    bank() : name(""), accountNo(""), dob(""), balance(0.0) {}

    // Display function to show account details (optional, but useful for debugging)
    void display() const {
        cout << "Account Holder: " << name << "\n"
             << "Account Number: " << accountNo << "\n"
             << "Date of Birth: " << dob << "\n"
             << "Balance: " << balance << "\n";
    }
};

void create_account(map<string, bank>& byID, map<pair<string, string>, bank>& byName, int& newAc) {
    cout << "Enter Account Holder Name: ";
    string name;
    cin.ignore(); // To handle any leftover newline character in the input buffer
    getline(cin, name);

    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    string dob;
    getline(cin, dob);

    cout << "Enter Initial Balance: ";
    double initial_balance;
    cin >> initial_balance;

    string ac = "743312" + to_string(newAc++);
    bank new_account(name, dob, ac, initial_balance);

    byID[ac] = new_account;
    byName[make_pair(name, dob)] = new_account;

    cout << "Account created successfully! Account Number: " << ac << endl;
    new_account.display();
    cout << "-------------------------" << endl;
}

void depositByID(map<string, bank>& byID,map<pair<string, string>, bank>& byName, double amount, string id) {
     bank bn=byID[id];
    bn.balance+=amount;
    //update
    byID[id]=bn;
    byName[make_pair(bn.name,bn.dob)]=bn;
    double balance=bn.balance;
        cout << "Your amount is successfully deposited \n";
        cout << "Deposited : " << amount << ". New balance: " << bn.balance << endl;
   
    cout << "-------------------------" << endl;
}

void withdrawByID(map<string, bank>& byID,map<pair<string, string>, bank>& byName, double amount, string id) {
     bank bn=byID[id];
    bn.balance+=amount;
   
        if (bn.balance < amount) {
            cout << "Money was not debited due to insufficient balance!" << endl;
       return; }
             //update
    byID[id]=bn;
    byName[make_pair(bn.name,bn.dob)]=bn;
    double balance=bn.balance;
            cout << "Your amount is successfully debited \n";
            cout << "Withdraw amount : " << amount << ". New balance: " << bn.balance << endl;
   
    cout << "-------------------------" << endl;
}

void depositByName(map<string, bank>& byID,map<pair<string, string>, bank>& byName, string name, string dob, double amount) {
     bank bn=byName[make_pair(name,dob)];
       bn.balance += amount;
       byID[bn.accountNo]=bn;
       byName[make_pair(name,dob)]=bn;
        cout << "Your amount is successfully deposited \n";
        cout << "Deposited : " << amount << ". New balance: " <<bn.balance << endl;
   
    cout << "-------------------------" << endl;
}

void withdrawByName(map<string, bank>& byID,map<pair<string, string>, bank>& byName, string name, string dob, double amount) {
     bank bn=byName[make_pair(name,dob)];
   
        if (bn.balance < amount) {
            cout << "Money was not debited due to insufficient balance!" << endl;
        } else {
            bn.balance += amount;
             byID[bn.accountNo]=bn;
            byName[make_pair(name,dob)]=bn;
            cout << "Your amount is successfully debited \n";
            cout << "Withdraw amount : " << amount << ". New balance: " << bn.balance << endl;
        }
    cout << "-------------------------" << endl;
}

void checkByID(const map<string, bank>& byID, string id) {
    auto it = byID.find(id);
    if (it != byID.end()) {
        it->second.display();
    } else {
        cout << "Account not found." << endl;
    }
    cout << "-------------------------" << endl;
}

void checkByName(const map<pair<string, string>, bank>& byName, string name, string dob) {
    auto it = byName.find(make_pair(name, dob));
    if (it != byName.end()) {
        it->second.display();
    } else {
        cout << "Account not found." << endl;
    }
    cout << "-------------------------" << endl;
}
void showMenu() {
    cout << "\n===== Bank Menu =====\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit by Account Number\n";
    cout << "3. Withdraw by Account Number\n";
    cout << "4. Deposit by Name and DOB\n";
    cout << "5. Withdraw by Name and DOB\n";
    cout << "6. Check Account by Account Number\n";
    cout << "7. Check Account by Name and DOB\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}
// void creat(map<string, bank>& byID, map<pair<string, string>, bank> &byName,int newAc ){
    
// }
// Main function
int main() {
    map<string, bank> byID; // Map to store accounts by account number
    map<pair<string, string>, bank> byName; // Map to store accounts by name and DOB
    int newAc = 1000;
    // char choice; // Starting point for account number generation
    
    // do {
    //     create_account(byID, byName, newAc);
    //     cout << "Do you want to create another account? (y/n): ";
    //     cin >> choice;
    // } while (choice == 'y' || choice == 'Y');

     while (true) {
        showMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:{
             char choices;
            create_account(byID, byName, newAc);
           
            cout << "Do you want to create another account? (y/n): ";
            cin >> choices;
            while(choices == 'y' || choices == 'Y'){
           create_account(byID, byName, newAc);
           cout << "Do you want to create another account? (y/n): ";
            cin >> choices;
            }
            break;}

        case 2: {
            cout << "Enter Account Number: ";
            string id;
            cin >> id;
            if (byID.find(id) == byID.end()) {
                cout << "Enter a valid account No!" << endl;
                break;
            }
            cout << "Enter Amount to Deposit: ";
            double amount;
            cin >> amount;
            depositByID(byID,byName, amount, id);
            break;
        }
        case 3: {
            cout << "Enter Account Number: ";
            string id;
            cin >> id;
            if (byID.find(id) == byID.end()) {
                cout << "Enter a valid account No!" << endl;
                break;
            }
            cout << "Enter Amount to Withdraw: ";
            double amount;
            cin >> amount;
            withdrawByID(byID,byName, amount, id);
            break;
        }
        case 4: {
            cout << "Enter Account Holder Name: ";
            string name;
            cin.ignore();
            getline(cin, name);
            cout << "Enter Date of Birth (DD/MM/YYYY): ";
            string dob;
            getline(cin, dob);
            if (byName.find(make_pair(name, dob)) == byName.end()) {
                cout << "Enter a valid Name and Date of birth" << endl;
                break;
            }
            cout << "Enter Amount to Deposit: ";
            double amount;
            cin >> amount;
            depositByName(byID,byName, name, dob, amount);
            break;
        }
        case 5: {
            cout << "Enter Account Holder Name: ";
            string name;
            cin.ignore();
            getline(cin, name);
            cout << "Enter Date of Birth (DD/MM/YYYY): ";
            string dob;
            getline(cin, dob);
            if (byName.find(make_pair(name, dob)) == byName.end()) {
                cout << "Enter a valid Name and Date of birth" << endl;
                break;
            }
            cout << "Enter Amount to Withdraw: ";
            double amount;
            cin >> amount;
            withdrawByName(byID, byName, name, dob, amount);
            break;
        }
        case 6: {
            cout << "Enter Account Number: ";
            string id;
            cin >> id;
            if (byID.find(id) == byID.end()) {
                cout << "Enter a valid account No!" << endl;
                break;
            }
            checkByID(byID, id);
            break;
        }
        case 7: {
            cout << "Enter Account Holder Name: ";
            string name;
            cin.ignore();
            getline(cin, name);
            cout << "Enter Date of Birth (DD/MM/YYYY): ";
            string dob;
            getline(cin, dob);
            if (byName.find(make_pair(name, dob)) == byName.end()) {
                cout << "Enter a valid Name and Date of birth" << endl;
                break;
            }
            checkByName(byName, name, dob);
            break;
        }
        case 8:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
