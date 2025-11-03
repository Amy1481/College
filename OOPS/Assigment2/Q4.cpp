#include <iostream>
using namespace std;

class DB; // Forward declaration

class DM {
    float meters;
    float centimeters;

public:
    void getdata() {
        cout << "Enter distance in meters and centimeters: ";
        cin >> meters >> centimeters;
    }

    friend DM add(DM, DB);

    void display() {
        cout << "\nDistance: " << meters << " meters " << centimeters << " centimeters\n";
    }
};

class DB {
    float feet;
    float inches;

public:
    void getdata() {
        cout << "Enter distance in feet and inches: ";
        cin >> feet >> inches;
    }

    friend DM add(DM, DB);
};

DM add(DM m, DB b) {
    DM result;
    float total_m = m.meters + (b.feet * 0.3048);
    float total_cm = m.centimeters + (b.inches * 2.54);

    if (total_cm >= 100) {
        total_m += int(total_cm / 100);
        total_cm = (int)total_cm % 100;
    }

    result.meters = total_m;
    result.centimeters = total_cm;
    return result;
}

int main() {
    DM m1, result;
    DB b1;

    m1.getdata();
    b1.getdata();

    result = add(m1, b1);
    result.display();

    return 0;
}
