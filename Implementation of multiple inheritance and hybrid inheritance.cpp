#include <iostream>
using namespace std;

class Participant 
{
public:
    string name;
    int age;
    float score;

    Participant(string n, int a, float s) : name(n), age(a), score(s) {
	}

    void showParticipant() const {
        cout << "Participant Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Score: " << score << endl;
    }
};

class E {
protected:
    string n;
    int p;
    Participant* participants; 

public:
    E(string name, int part) : n(name), p(part) {
        participants = new Participant[p]; 
        for (int i = 0; i < p; i++) {
            string pName;
            int pAge;
            float pScore;

            cout << "\nEnter Participant " << (i + 1) << " Details:\n";
            cout << "Name: ";
            cin >> pName;
            cout << "Age: ";
            cin >> pAge;
            cout << "Score: ";
            cin >> pScore;

            participants[i] = Participant(pName, pAge, pScore); 
        }
    }

    void show() const {
        cout << "Event Name: " << n << endl;
        cout << "Participants: " << p << endl;
        for (int i = 0; i < p; i++) {
            cout << "\nParticipant " << (i + 1) << " Details:\n";
            participants[i].showParticipant(); 
        }
    }

    Participant getWinner() const {
        Participant winner = participants[0];
        for (int i = 1; i < p; i++) {
            if (participants[i].score > winner.score) {
                winner = participants[i];
            }
        }
        return winner;
    }

    ~E() {
        delete[] participants; 
    }
};

class J {
protected:
    string jName;
    string jRole;

public:
    J(string name, string role) : jName(name), jRole(role) {}

    void showJudge() const {
        cout << "Judge Name: " << jName << endl;
        cout << "Role: " << jRole << endl;
    }

    string getJudgeName() const {
        return jName;
    }
};

class C : public E {
protected:
    string cCat;

public:
    C(string name, int part, string cat)
        : E(name, part), cCat(cat) {}

    void showC() const {
        show();
        cout << "Cultural Category: " << cCat << endl;
    }
};

class D : public C, public J {
private:
    string dType;

public:
    D(string name, int part, string cat, string jName, string jRole, string type)
        : C(name, part, cat), J(jName, jRole), dType(type) {}

    void showD() const {
        showC();
        showJudge();
        cout << "Dance Type: " << dType << endl;
    }

    void showWinner() const {
        Participant winner = getWinner();
        cout << "\nWinner Details:\n";
        winner.showParticipant();
        cout << "Judged by: " << jName << " (" << jRole << ")" << endl;
    }
};

class Fest {
private:
    D** events;
    int size;

public:
    Fest(int s) : size(s) {
        events = new D*[size];
        for (int i = 0; i < size; i++) {
            events[i] = nullptr; 
        }
    }

    void addEvent(int index, D* event) {
        if (index >= 0 && index < size) {
            events[index] = event;
        }
    }

    void showEvents() const {
        for (int i = 0; i < size; i++) {
            if (events[i] != nullptr) {
                cout << "\nEvent " << (i + 1) << " Details:\n";
                events[i]->showD();
            }
        }
    }

    void showWinners() const {
        for (int i = 0; i < size; i++) {
            if (events[i] != nullptr) {
                cout << "\nWinner for Event " << (i + 1) << ":\n";
                events[i]->showWinner();
            }
        }
    }

    ~Fest() 
	{
        for (int i = 0; i < size; i++) {
            delete events[i];
        }
        delete[] events; 
	}
};

int main() 
{
    int numEvents;
    cout << "Enter number of dance events: ";
    cin >> numEvents;

    Fest fest(numEvents);

    for (int i = 0; i < numEvents; i++) {
        string eName, cCat, jName, jRole, dType;
        int p;

        cout << "\nEnter Dance Event " << (i + 1) << " Name: ";
        cin >> eName;
        cout << "Enter number of participants: ";
        cin >> p;
        cout << "Enter Cultural Category: ";
        cin >> cCat;
        cout << "Enter Judge Name: ";
        cin >> jName;
        cout << "Enter Judge Role: ";
        cin >> jRole;
        cout << "Enter Dance Type: ";
        cin >> dType;

        D* danceEvent = new D(eName, p, cCat, jName, jRole, dType);
        fest.addEvent(i, danceEvent);
    }

    cout << "\nAll Dance Events Details: ";
    fest.showEvents();

    cout << "\nWinners of All Events: ";
    fest.showWinners();

    return 0;
}
