using namespace std;
#include<iostream>

class fest
{
	string participant, institution, event;
	public:
	fest(string participant, string institution, string event)
	{
		this -> participant = participant;
		this -> institution = institution;
		this -> event = event;
	}
	friend string sentence(fest& obj);
};

string sentence(fest& obj)
{
	return obj.participant + " from " + obj.institution + " is participating in " + obj.event + ".";
}

int main()
{
	fest f[] =
	{
		fest("Priya Mohan", "Kristu Jayanti", "How I Met Your Killer"),
		fest("Rahul Sharma", "St. Joseph's College", "Abhivyakti"),
		fest("Ananya Verma", "Mount Carmel College", "Ink and Tale"),
		fest("Vikram Rao", "Christ University", "Switch and Scene"),
		fest("Sneha Iyer", "Jain University", "Frames Unboxed"),
		fest("Rohan Kapoor", "Presidency College", "Ad-venture"),
		fest("Meera Nair", "Bangalore University", "Case Closed"),
		fest("Anil Mehta", "RV College of Engineering", "How I Met Your Killer"),
		fest("Sara Fernandes", "St. Xavier's College", "Abhivyakti"),
		fest("Nikhil Patil", "BITS Pilani", "Ink and Tale"),
		fest("Pooja Desai", "Manipal University", "Switch and Scene"),
		fest("Arjun Sen", "National Institute of Technology", "Frames Unboxed"),
		fest("Naina Gupta", "Symbiosis Institute", "Ad-venture"),
		fest("Karan Rao", "IIM Bangalore", "Case Closed")
	};
	for(int i = 0; i < sizeof(f) / sizeof(fest); i++)
	{
		cout << sentence(f[i]) << endl;
	}
}
