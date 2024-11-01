#include<string>
#include<iostream>
using namespace std;

class fest
{

static int nextRegNo;
int RegNo, Slot_NO;
string Name;
public:
fest()
{
RegNo = nextRegNo++;
Slot_NO = 18;
}
fest(fest& obj)
{
RegNo = nextRegNo++;
Slot_NO = obj.Slot_NO;
Name = obj.Name;
}
void setName(string Name)
{
this -> Name = Name;
}
friend void display(fest& obj);
};

int fest::nextRegNo = 2441500;

void display(fest& obj)
{
cout << "RegNo: " << obj.RegNo << "\nParticipant Name: " << obj.Name << "\nSlot_NO: " <<
obj.Slot_NO << "\n";
}

int main()

{
fest Student1;
Student1.setName("Abdul");
fest Student2(Student1);
cout << "Student1:\n";
display(Student1);
cout << "\nStudent2:\n";
display(Student2);
}