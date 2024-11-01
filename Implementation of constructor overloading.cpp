#include <iostream>
using namespace std;

class User {
    string participant, Place, email;
    int amt;

public:
    User(string u) {
        participant = u;
        email = "Not provided";
        Place = "Not provided"; 
        amt = 0;
    }

    User(string u, string e, string ev) {
        participant = u;
        email = e;
        Place = ev;
        amt = 0;
    }

    User(string u, string e, string ev, int a) {
        participant = u;
        email = e;
        Place = ev;
        amt = a;
    }

    void display() {
        cout << "\nparticipant: " << participant;
        cout << "\nEmail: " << email;
        cout << "\nPlace: " << Place;
        cout << "\nAmount: " << amt << "\n"; 
    }
};

int main() {
    User user1("Chandru");
    User user2("Ram", "ram2006@gmail.com", "Chennai");
    User user3("Ray", "ray2024@hotmail.com", "Mumbai", 25000);

    cout << "User1 Profile:\n";
    user1.display();

    cout << "\nUser2 Profile:\n";
    user2.display();

    cout << "\nUser3 Profile:\n";
    user3.display();

    return 0;
}
