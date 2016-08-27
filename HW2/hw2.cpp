// Name:			Katie Martin
// UserName:			klm0055
// FileName:			hw2.cpp
// Developing Environment:	vim, g++, Linux
// Compile:			g++ hw2.cpp -o hw2
// Sample Usage:		./hw2


#include<iostream>
#include<cmath>
using namespace std;


int main() {

	const double SWEETNER_AMOUNT = 0.001;
	double weightDesiredHuman = 0;		//Weight at which the dieter will stop dieting
	double lethalMouseSweetner = 0;		
	double weightMouse = 0;
	double numDietSoda = 0;


	cout<< "What is the amount of artificial sweetner needed to kill a mouse: " << endl;
	cin>> lethalMouseSweetner;
	
	cout<< "What is the weight of the mouse: " << endl;
	cin>> weightMouse;

	cout<< "What is the desired weight of the dieter: " << endl;
	cin>> weightDesiredHuman;

	numDietSoda = (weightDesiredHuman / weightMouse) * (lethalMouseSweetner / SWEETNER_AMOUNT);
	numDietSoda = floor(numDietSoda);

	cout<< "You can drink " << numDietSoda << " diet sodas without dying as a result." << endl;

return 0;

}  

