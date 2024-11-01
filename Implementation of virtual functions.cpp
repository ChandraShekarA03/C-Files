#include <iostream>
#include <string>
using namespace std;

class Event { 
protected:
    int eventID;
    string participantName, email;
public:
    Event(int id, string name, string mail): eventID(id), participantName(name), email(mail) {}

    virtual void displayDetails() {
        cout<<"\nParticipant Details:\n";
        cout<<"Participant ID: "<<eventID<<"\nName: "<<participantName<<"\nEmail: "<<email<<endl;
    }
    virtual void performOperation()=0;  
};

class TechnicalEvent: public Event { 
private:
    int score;
public:
    TechnicalEvent(int id, string name, string mail, int scr): Event(id, name, mail), score(scr) {}

    void displayDetails() override {
        Event::displayDetails(); 
        cout<<"Technical Event Score: "<<score<<endl;
    }

    void performOperation() override {
        int points;
        char type;
        cout<<"Enter 'a' to add score, 's' to subtract score: ";
        cin>>type;
        cout<<"Enter points: ";
        cin>>points;
        if(type == 'a') {
            score += points;
            cout<<"Added: "<<points<<" points\nNew Score: "<<score<<endl;
        } else if(type == 's' && points <= score) {
            score -= points;
            cout<<"Subtracted: "<<points<<" points\nNew Score: "<<score<<endl;
        } else {
            cout<<"Invalid operation or insufficient score!"<<endl;
        }
    }
};

class CulturalEvent: public Event { 
private:
    double rating;
public:
    CulturalEvent(int id, string name, string mail, double rtg): Event(id, name, mail), rating(rtg) {}

    void displayDetails() override {
        Event::displayDetails();  
        cout<<"Cultural Event Rating: "<<rating<<endl;
    }

    void performOperation() override {
        double rate;
        cout<<"Enter new rating: ";
        cin>>rate;
        if(rate >= 0 && rate <= 10) {
            rating = rate;
            cout<<"Updated Rating: "<<rating<<endl;
        } else {
            cout<<"Invalid rating! Please enter a value between 0 and 10."<<endl;
        }
    }
};

int main() {
    int eventID;
    string participantName, email;
    int score;
    double rating;
    char choice;

    cout<<"Enter Participant ID: ";
    cin>>eventID;
    cout<<"Enter Name: ";
    cin>>participantName;
    cout<<"Enter Email: ";
    cin>>email;

    cout<<"Enter Initial Technical Event Score: ";
    cin>>score;
    TechnicalEvent tech(eventID, participantName, email, score);

    cout<<"Enter Initial Cultural Event Rating (0-10): ";
    cin>>rating;
    CulturalEvent cultural(eventID, participantName, email, rating);

    Event* eventPtr; 	
    do {
        cout<<"\nSelect event to manage:\n1. Technical Event\n2. Cultural Event\nEnter choice: ";
        cin>>choice;

        if(choice == '1') {
            eventPtr = &tech;  
        } else if(choice == '2') {
            eventPtr = &cultural;  
        }

        eventPtr->displayDetails();  
        eventPtr->performOperation(); 

        cout<<"Do you want to perform another operation? (y/n): ";
        cin>>choice;
    } while(choice == 'y' || choice == 'Y');

    cout<<"Thank you for participating in the Fest!"<<endl;

    return 0;
}
