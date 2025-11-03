#include <iostream>
using namespace std;

class Employee {
private:
    double salary;
    int workHours;

    void AddSal() {
        if (salary < 5000)
            salary += 1000;
    }

    void AddWork() {
        if (workHours > 6)
            salary += 500;
    }

public:
    void getInfo(double s, int h) {
        salary = s;
        workHours = h;
        AddSal();
        AddWork();
    }

    void displaySalary() {
        cout << "\nFinal Salary: " << salary << endl;
    }
};

int main() {
    Employee e;
    double sal;
    int hours;

    cout << "Enter salary: ";
    cin >> sal;
    cout << "Enter work hours per day: ";
    cin >> hours;

    e.getInfo(sal, hours);
    e.displaySalary();

    return 0;
}
