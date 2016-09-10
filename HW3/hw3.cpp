// Name:		Katie Martin
// FileName:		hw3.cpp
// DevelopingEnviro:	vim, g++, Linux
// Compile:		g++ hw3.cpp -o hw3
// SampleUsage:		./hw3
//

#include <iostream>
#include <iomanip>
using namespace std;


int main()	{

double loanAmt =	0;
double intRate =	0;
double monthlyRate = 	0;
double monthlyInt = 	0;
double monthlyPmt = 	0;
double monthlyPV =	0;
double balance = 	0;
double totalInt = 	0;
int monthCount = 	0;

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

cout<< "User enter loan amount: ";
cin>> loanAmt;
cout<< endl;

cout<< "User enter interest rate per year: ";
cin>> intRate;
cout<< endl;

cout<< "User enter monthly payments: ";
cin>> monthlyPmt;
cout<< endl;

balance = loanAmt;
monthlyRate = intRate/12;

cout<< "************************************************************"<<endl;
cout<< "          Amortization Table                      "<<endl;
cout<< "************************************************************"<<endl;
cout<< left<< setw(10)<< "Month"<< left<<setw(10)<< "Balance"<<left<<setw(10)<< " Payment"<<left<<setw(10)<< " Rate";
cout<< left<< setw(10)<< " Interest"<< left<<setw(10)<< " Principal"<<endl;
cout<< left<< setw(10)<< monthCount<<"$"<< left<< setw(10)<<balance<< left<< setw(10)<< "N/A"<< left<< setw(10) << "N/A";
cout<< left<< setw(10)<< "N/A"<< left<< setw(10)<< "N/A"<<endl;

while(balance > 0 )   {
	if (balance > monthlyPmt)   {
		monthlyInt = (monthlyRate/100) * balance;
		monthlyPV = monthlyPmt - monthlyInt;
		if (monthlyPV < 0)   {
			cout<< "Error" << endl;
			break;
			}
		balance = balance - monthlyPV;
		totalInt = totalInt + monthlyInt;
		monthCount = monthCount + 1;
		//cout<< monthCount<< "$"<< left<<setw(10); 
		cout<< left<< setw(10)<< monthCount<<"$"<<left<<setw(10)<<balance<<left<<setw(10)<< monthlyPmt<<left;
		cout<< left << setw(10)<<monthlyRate<<left<<setw(10)<<monthlyInt<<left<<setw(10)<< monthlyPV<< endl;

	}
	else   {
		monthlyInt = (monthlyRate/100) * balance;
		monthlyPmt = balance + monthlyInt;
		monthlyPV = monthlyPmt - monthlyInt;
		if (monthlyPV < 0)   {
			cout << "Error: monthly payment is less than interest." << endl;
			break;
			}
		balance = balance - monthlyPV;
		monthCount = monthCount + 1;
		totalInt = totalInt + monthlyInt;
		cout<< left << setw(10) << monthCount <<"$"<<left<<setw(10)<< balance <<left<<setw(10)<< monthlyPmt;
                cout<< left << setw(10) << monthlyRate << left << setw(10) <<  monthlyInt << left << setw(10) <<  monthlyPV<< endl;
		}
}
cout<< "************************************************************"<<endl;
cout<< "It takes "<< monthCount<< " months to pay off the loan."<<endl;
cout<< "Total interest paid is: $"<< totalInt<<endl;
return 0;			
}
