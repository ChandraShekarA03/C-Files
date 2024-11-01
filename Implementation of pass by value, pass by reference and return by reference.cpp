#include<iostream>
using namespace std;

int& returnValue(int& a) 
{
	return a;
}

void display(string A, int a, string B, int b) 
{
	cout << A << " = " << a << "\n" << B << " = " << b;
}

int x = 987;
int &y = returnValue(x);

int main()
{
	display("x", x, "y", y);
	x = 654;
	cout << "\n\nAfter x change:\n";
	display("x", x, "y", y);
}