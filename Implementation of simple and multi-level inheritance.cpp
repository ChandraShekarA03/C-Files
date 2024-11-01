#include <iostream>
using namespace std;

class Event {
protected:
    string name;
    int part;

public:
    Event(string nm, int p) : name(nm), part(p) {}

    void show() {
        cout << "Event Name: " << name << endl;
        cout << "Number of Participants: " << part << endl;
    }

    int getPart() const {
        return part;
    }

    string getName() const {
        return name;
    }

    void addPart(int add) {
        if (add >= 0) {
            part += add;
        } else {
            cout << "Participants cannot be negative." << endl;
        }
    }
};

class TechEvent : public Event {
private:
    string cat;

public:
    TechEvent(string nm, int p, string c)
        : Event(nm, p), cat(c) {}

    void showTech() {
        show();
        cout << "Technical Category: " << cat << endl;
    }
};

class DanceEvent : public Event {
private:
    string type;

public:
    DanceEvent(string nm, int p, string t)
        : Event(nm, p), type(t) {}

    void showDance() {
        show();
        cout << "Dance Type: " << type << endl;
    }
};

void findWinner(const Event &e1, const Event &e2) {
    if (e1.getPart() > e2.getPart()) {
        cout << "\nWinner: " << e1.getName() << " with " << e1.getPart() << " participants!" << endl;
    } else if (e2.getPart() > e1.getPart()) {
        cout << "\nWinner: " << e2.getName() << " with " << e2.getPart() << " participants!" << endl;
    } else {
        cout << "\nIt's a tie between " << e1.getName() << " and " << e2.getName() << " with " << e1.getPart() << " participants each!" << endl;
    }
}

int main() {
    string name, techCat, danceType;
    int part, addPart;

    cout << "Enter Technical Event Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Enter number of participants: ";
    cin >> part;
    cout << "Enter Technical Category: ";
    cin >> techCat;

    TechEvent tech(name, part, techCat);

    cout << "\nEnter Dance Event Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Enter number of participants: ";
    cin >> part;
    cout << "Enter Dance Type: ";
    cin >> danceType;

    DanceEvent dance(name, part, danceType);

    cout << "\nTechnical Event Details: " << endl;
    tech.showTech();

    cout << "\n===========================\n" << endl;

    cout << "Dance Event Details: " << endl;
    dance.showDance();

    cout << "\nDo you want to add more participants to the Technical Event? Enter number: ";
    cin >> addPart;
    tech.addPart(addPart);

    cout << "\nDo you want to add more participants to the Dance Event? Enter number: ";
    cin >> addPart;
    dance.addPart(addPart);

    findWinner(tech, dance);

    return 0;
}
