//Name:				Katie Martin
//FileName:			hw4.cpp
//DevelopingEnvironment		vim, g++, Linux
//Compile:			g++ hw4.cpp -o hw4
//SampleUsage:			./hw4
//

# include<iostream>
# include<stdlib.h>
# include<assert.h>
# include<ctime>
# include<stdio.h>
# include<termios.h>
# include<unistd.h>
# include<ctype.h>

using namespace std;

// Pre-define functions:
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alivve, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);
void press_any_key(void);
int mygetch(void);

int main() 
{	
	int numA_wins = 0;
	int numB_wins = 0;
	int numC_wins = 0;
	double shootPoint;
	bool A_alive = true;
	bool B_alive = true;
	bool C_alive = true;
	int duel_counter_strategy_one = 0;
	int duel_counter_strategy_two = 0;
	const double A_hit_prob = 33;
	const double B_hit_prob = 50;
	const int numDuels = 10000;
	const int perc_conversion = 100;


	cout<< "*** Welcome to Katie Martin's Duel Simulator ***"<< endl;
	test_at_least_two_alive();
	test_Aaron_shoots1();
	test_Bob_shoots();
	test_Charlie_shoots();
	test_Aaron_shoots2();

// Strategy 1	
	cout<< "Ready to test Strategy 1 (run " << numDuels<< " times):" << endl;
	cout<< "Press any key to continue..." << endl;
	cin.ignore().get();
	
	srand(time(0));

	for (duel_counter_strategy_one; duel_counter_strategy_one < numDuels; duel_counter_strategy_one ++)
	{
		while (at_least_two_alive(A_alive, B_alive, C_alive))
		{
			if (A_alive == true)
				Aaron_shoots1(B_alive, C_alive);
			if (B_alive == true)
				Bob_shoots(A_alive, C_alive);
			if (C_alive == true)
				Charlie_shoots(A_alive, C_alive);
		}
		// Keep track of wins for each guy by using a counter
		if (A_alive == true)
		{
			assert(B_alive == false && C_alive ==false);
			numA_wins = numA_wins + 1;
		}
		if (B_alive == true)
		{
			assert(A_alive == false && C_alive == false);
			numB_wins= numB_wins + 1;
		}
		if (C_alive == true)
		{
			assert(A_alive == false && B_alive == false);
			numC_wins = numC_wins + 1;
		}
	}
	// Print Results from Stratgey 1
	cout<< "Aaron won " << numA_wins<< "/"<< numDuels<< " or  " << ((numA_wins/numDuels)*perc_conversion)<< "%"<< endl;
	cout<< "Bob won " << numB_wins<< "/"<< numDuels<< " or  " << ((numB_wins/numDuels)*perc_conversion)<< "%"<< endl;
	cout<< "Charlie won " << numC_wins<< "/"<< numDuels<< " or " << ((numC_wins/numDuels)*perc_conversion)<< "%"<< endl;


	// Strategy 2	
	cout<< "Ready to test strategy 2 (run " << numDuels<< " times):" << endl;
	cout<< "Press any key to continue..." << endl;
	cin.ignore().get();
	for (duel_counter_strategy_two; duel_counter_strategy_two < numDuels; duel_counter_strategy_two++)
	{
		while (at_least_two_alive(A_alive, B_alive, C_alive))
		{
			if (A_alive == true)
				Aaron_shoots2(B_alive, C_alive);
			if (B_alive == true)
				Bob_shoots(A_alive, C_alive);
			if (C_alive == true)
				Charlie_shoots(A_alive, C_alive);
		}
		// Keep record of wins of each guy by using a counter
		if (A_alive == true)
		{
			assert(B_alive == false && C_alive == false);
			numA_wins = numA_wins + 1;
		}
		if (B_alive == true)
		{	
			assert (A_alive == false && C_alive == false);
			numB_wins = numB_wins + 1;
		}
		if (C_alive == true)
		{ 	
			assert (A_alive == false && B_alive == false);
			numC_wins = numC_wins + 1;
		}
	}
	// Print results from Strategy 2
	cout<< "Aaron won " << numA_wins<< "/"<< numDuels<< " or  " << ((numA_wins/numDuels)*perc_conversion)<< "%"<< endl;
        cout<< "Bob won " << numB_wins<< "/"<< numDuels<< " or  " << ((numB_wins/numDuels)*perc_conversion)<< "%"<< endl;
        cout<< "Charlie won " << numC_wins<< "/"<< numDuels<< " or " << ((numC_wins/numDuels)*perc_conversion)<< "%"<< endl;
	
	cout<< endl;
	cout<< "Strategy 2 is better than Strategy 1"<< endl;
	cout<< endl;

	cout<< "For some reason I couldn't get my counter to add up the number of wins for each guy. I know that startegy 2  is the best strategy" << endl;
	cout<< " I am not sure if it has to do something with my random number generator or what. I worked and worked at it to try to fix it, but" << endl;
	cout<< "just coudlnt get it. I will get with you to look over what I did that didn't make the counter work."<< endl;
return 0;
}

// 5 Defined functions with 5 test cases
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive)
{
	if ((A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive))
		return true;
	else
		return false;

}



void Aaron_shoots1(bool& B_alive, bool& C_alive)
{
	double shootPoint;
	int A_hit_prob = 33;
	shootPoint = rand() % 100;
	if (C_alive == true)
	{	if (shootPoint < A_hit_prob)
		{	//cout<<"Charlie is killed." << endl;
			C_alive = false;
		}
	}
	else if (B_alive == true)
	{	if (shootPoint < A_hit_prob)
		{ 	//cout<< "Bob is killed."<< endl;
			B_alive = false;
		}
	}
	else 
		cout<< "Error Message: Aaron shoots nobody."<< endl;
return;
}



void Bob_shoots(bool& A_alive, bool& C_alive)
{
	double shootPoint;
	int B_hit_prob = 0.67;
	shootPoint = rand() % 100;
        if (C_alive == true)
        {       if (shootPoint < B_hit_prob)
                {       //cout<<"Charlie is killed." << endl;
                        C_alive = false;
                }
        }
        else if (A_alive == true)
        {       if (shootPoint < B_hit_prob)
                {       //cout<< "Aaron is killed."<< endl;
                        A_alive = false;
                }
        }
        else
                cout<< "Error Message: Bob shoots nobody."<< endl;
return;
}




void Charlie_shoots(bool& A_alive, bool& B_alive)
{
	if (B_alive == true)
		{B_alive = false;
		//cout<< "Bob is killed." << endl;
		}
	else if (A_alive == true)
		{ A_alive = false;
		//cout<< "Aaron is killed."<< endl;
		}
	else
		cout<< "Error Message: Charlie shoots nobody."<<endl;
return;
}




void Aaron_shoots2(bool& B_alive, bool& C_alive)
{
	if (B_alive == true && C_alive == true)
		cout<< "Aaron intentionally misses the first shot"<<endl;
	else 
		Aaron_shoots1(B_alive, C_alive);
return;
}



	
void test_at_least_two_alive(void)
{
	cout<< "Unit Testing 1: Function - at_least_two_alive()"<< endl;
        cout<< "Case 1: Aaron alive, Bob alive, Charlie alive"<< endl;
		assert(true == at_least_two_alive(true, true, true));
		cout<< "Case passed..."<< endl;

        cout<< "Case 2: Aaron dead, Bob alive, Charlie alive"<< endl;
	        assert(true == at_least_two_alive(false, true, true));
                cout<< "Case passed..."<< endl;

        cout<< "Case 3: Aaron alive, Bob dead, Charlie alive"<< endl;
		assert(true == at_least_two_alive(true, false, true));
                cout<< "Case passed..."<< endl;

        cout<< "Case 4: Aaron alive, Bob alive, Charlie dead"<< endl;
                assert(true == at_least_two_alive(true, true, false));
                cout<< "Case passed..."<< endl;

        cout<< "Case 5: Aaron dead, Bob dead, Charlie alive"<< endl;
                assert(false == at_least_two_alive(false, false, true));
                cout<< "Case passed..."<< endl;

        cout<< "Case 6: Aaron dead, Bob alive, Charlie dead"<< endl;
                assert(false == at_least_two_alive(false, true, false));
                cout<< "Case passed..."<< endl;

        cout<< "Case 7: Aaron alive, Bob dead, Charlie dead"<< endl;
                assert(false == at_least_two_alive(true, false, false));
                cout<< "Case passed..."<< endl;

        cout<< "Case 8: Aaron dead, Bob dead, Charlie dead"<< endl;
                assert(false == at_least_two_alive(false, false, false));
                cout<< "Case passed..."<< endl;

	cout<< "Press any key to continue..."<< endl;
	cin.ignore().get();
return;
}




void test_Aaron_shoots1(void)
{ 	 
        cout<< "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)"<< endl;
        cout<< "Case 1: Bob alive, Charlie alive"<< endl;
        cout<< "Aaron is shooting at Charlie"<< endl;
		bool B_alive = true;
		bool C_alive = true; 
		Aaron_shoots1(B_alive, C_alive);
		assert(B_alive == true);
		if (C_alive == true)
			cout<< "Aaron misses."<< endl;
		else
			cout<< "Charlie is killed."<< endl;

        cout<< "Case 2: Bob dead, Charlie alive"<< endl;
        cout<< "Aaron is shooting at Charlie"<< endl;
		B_alive = false;
		C_alive = true;
		Aaron_shoots1(B_alive, C_alive);
		assert(B_alive == false);
		if (C_alive == true)
			cout<< "Aaron misses."<< endl;
		else
			cout<< "Charlie is dead."<< endl;

        cout<< "Case 3: Bob alive, Charlie dead"<< endl;
        cout<< "Aaron is shooting at Bob"<< endl;
		B_alive = true;
		C_alive = false;
		Aaron_shoots1(B_alive, C_alive);
		assert(C_alive == false);
		if (B_alive == true)
			cout<< "Aaron misses." << endl;
		else
			cout<< "Bob is dead." << endl;

	cout<< "Press any key to continue..."<< endl;
	cin.ignore().get();
return;
}




void test_Bob_shoots(void)
{
        cout<< "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive"<< endl;
        cout<< "Case 1: Aaron alive, Charlie alive"<< endl;
        cout<< "Bob is shooting at Charlie"<< endl;
                bool A_alive = true;
                bool C_alive = true;
                Bob_shoots(A_alive, C_alive);
                assert(A_alive == true);
                if (C_alive == true)
                        cout<< "Bob misses." << endl;
                else
                        cout<< "Charlie is dead." << endl;
	
	cout<< "Case 2: Aaron dead, Charlie alive"<< endl;
        cout<< "Aaron is shooting at Charlie"<< endl;
                A_alive = false;
                C_alive = true;
                Bob_shoots(A_alive, C_alive);
                assert(A_alive == false);
                if (C_alive == true)
                        cout<< "Bob misses." << endl;
                else
                        cout<< "Charlie is dead." << endl;

        cout<< "Case 3: Aaron alive, Charlie dead"<< endl;
        cout<< "Bob is shooting at Aaron"<< endl;
                A_alive = true;
                C_alive = false;
                Bob_shoots(A_alive, C_alive);
                assert(C_alive == false);
                if (A_alive == true)
                        cout<< "Bob misses." << endl;
                else
                        cout<< "Aaron is dead." << endl;

	cout<< "Press any key to continue..."<< endl;
	cin.ignore().get();
return;
}





void test_Charlie_shoots(void)
{
        cout<< "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Charlie_alive)"<< endl;
        cout<< "Case 1: Aaron alive, Bob alive"<< endl;
        cout<< "Charlie is shooting at Bob"<< endl;
                bool A_alive = true;
                bool B_alive = true;
                Charlie_shoots(A_alive, B_alive);
                assert(A_alive == true && B_alive == false);
       		cout<< "Bob is dead." << endl;

        cout<< "Case 2: Aaron dead, Bob alive"<< endl;
        cout<< "Charlie is shooting at Bob"<< endl;
                A_alive = false;
                B_alive = true;
                Charlie_shoots(A_alive, B_alive);
                assert(A_alive == false && B_alive == false);
                cout<< "Bob is dead." << endl;

        cout<< "Case 3: Aaron alive, Bob dead"<< endl;
        cout<< "Charlie is shooting at Aaron"<< endl;
                A_alive = true;
                B_alive = false;
                Charlie_shoots(A_alive, B_alive);
                assert(A_alive == false && B_alive == false);
                cout<< "Aaron is dead."<< endl;
	
	cout<< "Press any key to continue..."<< endl;
	cin.ignore().get();
return;
}





void test_Aaron_shoots2(void)
{
        cout<< "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)"<< endl;
        cout<< "Case 1: Bob alive, Charlie alive"<< endl;
        cout<< "Aaron intentionally misses his first shot"<< endl;
		bool B_alive = true;
		bool C_alive = true;
		Aaron_shoots2(B_alive, C_alive);
		assert(B_alive == true && C_alive == true);
        	cout<< "Both Bob and Charlie are alive."<< endl;

        cout<< "Case 2: Bob dead, Charlie alive"<< endl;
        cout<< "Aaron is shooting at Charlie"<< endl;
		B_alive = false;
		C_alive = true;
		Aaron_shoots2(B_alive, C_alive);
		assert(B_alive == false);
		if (C_alive == true)
			cout<< "Aaron misses."<< endl;
		else 
			cout<< "Charlie is dead."<< endl;

        cout<< "Case 3: Bob alive, Charlie dead"<< endl;
        cout<< "Aaron is shooting at Bob"<< endl;
		B_alive = true;
		C_alive = false;
		Aaron_shoots2(B_alive, C_alive);
		assert(C_alive == false);
		if (B_alive == true)
			cout<< "Aaron misses."<< endl;
		else
			cout<< "Bob is dead."<< endl;

	cout<< "Press any key to continue..."<< endl;
	cin.ignore().get();
return;
}
