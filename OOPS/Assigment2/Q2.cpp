#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int accNumber;
    string accType;
    double balance;

public:
    void assignValues(string n, int aNo, string aType, double bal) {
        name = n;
        accNumber = aNo;
        accType = aType;
        balance = bal;
    }

    void deposit(double amount) { balance += amount; }

    void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient balance for " << name << endl;
        else
            balance -= amount;
    }

    void display() {
        cout << "Name: " << name << "\tBalance: " << balance << endl;
    }
};

int main() {
    BankAccount customers[10];

    for (int i = 0; i < 3; i++) { // example: only 3 for demo
        string name, type;
        int accNo;
        double bal;
        cout << "\nEnter details for customer " << i + 1 << ":\n";
        cout << "Name: "; cin >> name;
        cout << "Account Number: "; cin >> accNo;
        cout << "Account Type: "; cin >> type;
        cout << "Initial Balance: "; cin >> bal;

        customers[i].assignValues(name, accNo, type, bal);
    }

    cout << "\n--- Customer Details ---\n";
    for (int i = 0; i < 3; i++) {
        customers[i].display();
    }

    return 0;
}
