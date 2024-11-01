#include <iostream>
using namespace std;
class room {
    int RegNo;
    int Slot;
    string Name;
public:
    static int nextRegNo;
    static int noOfObj() {
        return nextRegNo - 2441516;
    }
    room() {
        RegNo = nextRegNo++;
        Slot = 1001; 
    }
    room(const room &obj) {
        RegNo = nextRegNo++;
        Slot = obj.Slot;
        Name = obj.Name;
    }
    void setName(string Name) {
        this->Name = Name;
    }
    friend void display(room &obj);
};
int room::nextRegNo = 2441516;
void display(room &obj) {
    cout << "RegNo: " << obj.RegNo << "\nName: " << obj.Name << "\nSlot: " << obj.Slot << "\n";
}

int main() {
    room Student1;
    Student1.setName("Thejus");
    room Student2(Student1);
    cout << "Participant:\n";
    display(Student1);
    cout << "\nParticipant:\n";
    display(Student2);
    cout << "\nNext RegNo: " << room::nextRegNo << "\n";
    cout << "No of objects: " << room::noOfObj() << endl;
    return 0;
}
