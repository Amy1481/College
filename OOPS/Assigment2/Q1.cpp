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

    void deposit(double amount) {
        balance += amount;
        cout << "Amount deposited successfully!\n";
    }

    void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient balance!\n";
        else {
            balance -= amount;
            cout << "Amount withdrawn successfully!\n";
        }
    }

    void display() {
        cout << "\nName: " << name << "\nBalance: " << balance << endl;
    }
};

int main() {
    BankAccount b1;
    b1.assignValues("Amisha Mohanty", 12345, "Savings", 5000);

    b1.deposit(2000);
    b1.withdraw(1000);
    b1.display();

    return 0;
}
