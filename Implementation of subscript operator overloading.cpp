#include <iostream>
#include <string>

using namespace std;	

class Fest {
private:
    string name;
    int attendance;
    double revenue;

public:
    Fest(string name = "", int attendance = 0, double revenue = 0.0) {
        this->name = name;
        this->attendance = attendance;
        this->revenue = revenue;
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

    void setAttendance(int attendance) {
        this->attendance = attendance;
    }

    void setRevenue(double revenue) {
        this->revenue = revenue;
    }

    void display() const {
        cout << "Fest Name: " << name 
             << ", Attendance: " << attendance 
             << ", Revenue: " << revenue << endl;
    }
};

class FestManager {
private:
    Fest* fests;
    int festCount;

public:
    FestManager(int count) : festCount{count} {
        fests = new Fest[festCount]; 
    }

    ~FestManager() {
        delete[] fests;  
    }

    Fest& operator[](int index) {
        if (index >= 0 && index < festCount) {
            return fests[index];
        } else {
            cout << "Index out of bounds, returning first fest." << endl;
            return fests[0];
        }
    }

    const Fest& operator[](int index) const {
        if (index >= 0 && index < festCount) {
            return fests[index];
        } else {
            cout << "Index out of bounds, returning first fest." << endl;
            return fests[0]; 
        }
    }

    void displayAllFests() const {
        for (int i = 0; i < festCount; i++) {
            cout << "Fest " << i + 1 << ": ";
            fests[i].display();
        }
    }
};

int main() {
    int festCount;

    cout << "Enter the number of festivals: ";
    cin >> festCount;

    FestManager manager(festCount);

    string name;
    int attendance;
    double revenue;

    for (int i = 0; i < festCount; i++) {
        cout << "Enter details for Fest " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> ws;  
        getline(cin, name);  
        cout << "Attendance: ";
        cin >> attendance;
        cout << "Revenue: ";
        cin >> revenue;
        
        manager[i] = Fest{name, attendance, revenue};
    }

    cout << "\nAll fest details:\n";
    manager.displayAllFests();

    int k;
    cout << "Enter a specific position to access: ";
    cin >> k;

    cout << "\nAccessing a specific fest (array position " << k << "):" << endl;
    if (k >= 0 && k < festCount) {
        manager[k].display();
    } else {
        cout << "Invalid position entered." << endl;
    }

    cout << "\nAttempting to access an out-of-bounds fest (index " << festCount + 1 << "):" << endl;
    manager[festCount].display();  

    return 0;
}
