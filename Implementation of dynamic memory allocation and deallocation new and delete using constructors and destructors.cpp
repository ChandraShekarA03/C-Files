#include <iostream>
using namespace std;

class fest {
    char *pname;
    char *event;
    int result;
    static int participantCount;

    void copyString(char* &dest, const char* src) {
        int length = 0;
        while (src[length] != '\0') {
            length++;
        }
        dest = new char[length + 1];
        for (int i = 0; i < length; i++) {
            dest[i] = src[i];
        }
        dest[length] = '\0';
    }

public:
    fest(const char *p, const char *e, int q) {
        copyString(pname, p);
        copyString(event, e);
        result = q;
        participantCount++;
        cout << "Participant Added: " << pname << " | Event: " << event << " | Result: " << result << endl;
    }

    ~fest() {
        delete[] pname;
        delete[] event;
        participantCount--;
    }

    static int getParticipantCount() {
        return participantCount;
    }

    int getResult() const {
        return result;
    }

    const char* getParticipantName() const {
        return pname;
    }
};

int fest::participantCount = 0;

int main() {
    char name[100], event[100];
    int resu;
    char choice;
    int maxResult = -1;
    char winner[100];

    do {
        cout << "Enter Participant Name: ";
        cin >> name;
        cout << "Enter Event Name: ";
        cin >> event;
        cout << "Enter Result: ";
        cin >> resu;

        // Use stack allocation
        fest I(name, event, resu);

        if (resu > maxResult) {
            maxResult = resu;
            int i = 0;
            while (name[i] != '\0') {
                winner[i] = name[i];
                i++;
            }
            winner[i] = '\0';
        }

        cout << "Do you want to add another participant? (y/n): ";
        cin >> choice;
        cout << "\n";

    } while (choice == 'y' || choice == 'Y');

    cout << "Total Participants Registered: " << fest::getParticipantCount() << endl;
    cout << "Winner of the event: " << winner << " with result " << maxResult << endl;
    cout << "Thank You" << endl;

    return 0;
}
