#include <iostream>
#include <string>

using namespace std;

class Fest {
private:
    string name;
    int attendance;
    double revenue;
    string pname, college;
    int result;

public:
    Fest(string p, string c, int q) {
        pname = p;
        college = c;
        result = q;
        cout << "Object constructed" << endl
             << "Participant Name: " << pname << endl
             << "College: " << college << endl
             << "Result: " << result << endl;
    }

    Fest(string name = "", int attendance = 0, double revenue = 0.0) {
        this->name = name;
        this->attendance = attendance;
        this->revenue = revenue;
    }

    Fest& operator++() {  
        ++attendance;
        revenue += 0.0;  
        return *this;
    }

    Fest operator++(int) {  
        Fest temp = *this;
        ++attendance;
        revenue += 0.0;  
        return temp;
    }

    Fest& operator--() {
        --attendance;
        revenue -= 0.0;  
        return *this;
    }

    Fest operator--(int) {  
        Fest temp = *this;
        --attendance;
        revenue -= 0.0;  
        return temp;
    }

    bool operator!() const {  
        return attendance == 0;
    }

    Fest operator+(const Fest& other) const {  
        return Fest(name + " + " + other.name, attendance + other.attendance, revenue + other.revenue);
    }

    Fest operator-(const Fest& other) const {  
        return Fest(name + " - " + other.name, attendance - other.attendance, revenue - other.revenue);
    }

    bool operator==(const Fest& other) const {  
        return attendance == other.attendance && revenue == other.revenue;
    }

    void setName(string name) {
        this->name = name;
    }

    string getName() const {
        return name;
    }

    int getAttendance() const {
        return attendance;
    }

    double getRevenue() const {
        return revenue;
    }

    ~Fest() {
        cout << "Object destroyed" << endl;
    }
};

int main() {
    string name1, name2;
    int attendance1, attendance2;
    double revenue1, revenue2;

    cout << "Enter details for Fest 1:" << endl;
    cout << "Name: ";
    cin >> name1;
    cout << "Attendance: ";
    cin >> attendance1;
    cout << "Revenue: ";
    cin >> revenue1;
    cout << endl;

    cout << "Enter details for Fest 2:" << endl;
    cout << "Name: ";
    cin >> name2;
    cout << "Attendance: ";
    cin >> attendance2;
    cout << "Revenue: ";
    cin >> revenue2;
    cout << endl;

    Fest fest1(name1, attendance1, revenue1);
    Fest fest2(name2, attendance2, revenue2);

    if (fest1.getAttendance() == fest2.getAttendance()) {
        cout << "Both festivals have the same attendance." << endl;
    } else {
        cout << "The festivals have different attendance." << endl;
    }
    cout << endl;

    if (fest1.getRevenue() == fest2.getRevenue()) {
        cout << "Both festivals have the same revenue." << endl;
    } else {
        cout << "The festivals have different revenue." << endl;
    }
    cout << endl;

    if (!fest1) {
        cout << "Fest 1 has zero attendance." << endl;
    } else {
        cout << "Fest 1 has non-zero attendance." << endl;
    }
    cout << endl;

    if (!fest2) {
        cout << "Fest 2 has zero attendance." << endl;
    } else {
        cout << "Fest 2 has non-zero attendance." << endl;
    }
    cout << endl;

    ++fest1;
    fest2--;
    fest1.setName("Updated " + name1);
    cout << "Fest name: " << fest1.getName() << endl;
    cout << "Fest attendance: " << fest1.getAttendance() << endl;
    cout << "Fest revenue: " << fest1.getRevenue() << endl;
    cout << endl;

    fest2.setName("Updated " + name2);
    cout << "Fest name: " << fest2.getName() << endl;
    cout << "Fest attendance: " << fest2.getAttendance() << endl;
    cout << "Fest revenue: " << fest2.getRevenue() << endl;
    cout << endl;

    cout << "\nAfter incrementing fest1 and decrementing fest2:" << endl;
    cout << "Fest 1 - Attendance: " << fest1.getAttendance() << ", Revenue: " << fest1.getRevenue() << endl;
    cout << "Fest 2 - Attendance: " << fest2.getAttendance() << ", Revenue: " << fest2.getRevenue() << endl;
    cout << endl;

    Fest combinedFest = fest1 + fest2;
    cout << "\nCombined Fest Details:" << endl;
    cout << "Name: " << combinedFest.getName() << endl;
    cout << "Attendance: " << combinedFest.getAttendance() << endl;
    cout << "Revenue: " << combinedFest.getRevenue() << endl;
    cout << endl;

    Fest diffFest = fest1 - fest2;
    cout << "\nDifference Fest Details:" << endl;
    cout << "Name: " << diffFest.getName() << endl;
    cout << "Attendance: " << diffFest.getAttendance() << endl;
    cout << "Revenue: " << diffFest.getRevenue() << endl;
    cout << endl;

    Fest* I = new Fest("Chandru", "Dancing", 75);
    cout << "\n\n";
    delete I;

    return 0;
}
