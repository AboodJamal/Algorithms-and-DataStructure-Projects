#include<iostream>
using namespace std;

void moveDisk(string fp, string tp) 
{
	cout << "moving disk from " << fp << "  " << tp << endl;
}

void TowersOfHanoi(int height, string fromPole, string toPole, string withPole, int &counter) {
	if (height >= 1) {
		counter++;
		TowersOfHanoi(height - 1, fromPole, withPole, toPole, counter);
		moveDisk(fromPole, toPole);
		TowersOfHanoi(height - 1, withPole, toPole, fromPole, counter);
	}
}


/*
int main()
{
	int counter=0;
	TowersOfHanoi(3, "A", "B", "C", counter);
	cout << counter;
}
*/