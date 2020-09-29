// inl1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <string>

using namespace std;
// randnum generates a random number between 1 and 36
int randnum() {
	srand(time(0));
	int n = rand() % 36 + 1;
	return n;
};

// Check if the player has enough money on account.
bool checksald(int monleft, int bet) {
	if (monleft - bet > 99) {
		return true;
	}
	else if (monleft == 0) {
		return false;
	}
	return false;
};
// Calculate the profit if player wins. 
int checkprof(int bet, int mult) {
	return bet * mult;
};

int main()
{

	int chocol;
	int choose;
	int chonum;
	bool cont = true;
	int totprof = 0;
	int monleft = 1000;
	int con;

	bool hi = false;
	int bet;


	string randcol;

	cout << "The game has begun!\n";

	do {
		int actprof = 0;

		cout << "You have " << monleft << " in your account.\n";
		if (checksald(monleft, 0)) {
			cont = true;
		}
		else cont = false;


		// save what the user wants to bet, so we can use it to calculate profit.
		// We have to convert the input to the acutal bet. Here we also check if the user have enough money on account and tell the user what he/she can bet.
		do {
			
			cout << "How much do you want to bet?\n";
			cout << "1. 100kr\n2. 300kr\n3. 500kr\n0. End Game.\n";
			cin >> bet;


			if (bet != 1 && bet != 2 && bet != 3 && bet != 0) {
				hi = false;
				bet = -1;
			}
			if (bet != -1) {
				if (bet == 1) {
					bet = 100;
				}
				else if (bet == 2) {
					bet = 300;
				}
				else if (bet == 3) {
					bet = 500;
				}
				else if (bet == 0) {
					cont = false;
					break;
				}

				if (bet == 500 && (monleft < 500 && monleft >= 300)) {
					cout << "You can only bet 100 or 300.\n";
					hi = false;
				}
				else if (bet == 500 && (monleft == 200)) {
					cout << "You can only bet 100.\n";
					hi = false;
				}
				else if (bet == 300 && (monleft < 300 && monleft >= 100)) {
					cout << "You can only bet 100.\n";
					hi = false;
				}
				else if (bet != 100 && monleft == 100) {
					cout << "You can only bet 100.\n";
					hi = false;
				}
				else {
					hi = true;
					monleft = monleft - bet;
					cout << "The money has now withdrawl from your account.\n";
				}
			}

		} while (hi == false);


		if (cont == false) {
			break;
		}

		cout << "You have " << monleft << " left.\n";


		do {
			cout << "\nDo you want to guess number or color?\n"
				"1. Number \n2. Color\n0. End Game!\n";
			// save what the user wants to choose, so we know how to calc profit
			cin >> choose;
		} while (choose != 1 && choose != 2);

		// If the random generated number is even, the color is black, else its red. Checked using modulus.
		int randnom = randnum();
		if (randnom % 2 == 0) {
			randcol = "BLACK";
		}
		else {
			randcol = "RED";
		}

		if (choose == 1) {
			do {
				cout << "What number between 1 - 36 do you want to bet on? \nPress 0 to end game.\n";
				// save users guess and check if the random generated number is equal to the guess or not.
				cin >> chonum;
			} while (chonum > 36 || chonum < 0);

			int n;
			if (chonum == randnom) {
				cout << "Result: " << randcol << " " << randnom << "\nYou won!\n";
				actprof = checkprof(bet, 10);
				// calculate and save current balance if the user wins.
				monleft = bet + monleft + actprof;
				totprof = totprof + actprof;
				cout << "\nCurrent profit: " << actprof;
			}
			else if (chonum == 0) {
				cont = false;
				break;
			}
			else {
				cout << "\nResult: " << randcol << " " << randnom << "\n You lost..\n";
				cout << "\nCurrent proft: 0";
			}
		}
		else if (choose == 2) {
			actprof = checkprof(bet, 2);
			cout << "What color do you want to bet on?\n1.RED\n2.BLACK\n0. End Game.\n";
			// save what color the user want to guess and check if the random generated color and users guess are equal.
			// We also calc the profit if user wins.
			cin >> chocol;
			if (chocol == 1 && randcol == "BLACK") {
				cout << "Result: " << randcol << " " << randnom << " \n You lost..\n";
				cout << "Current profit: 0\n";
			}
			else if (chocol == 1 && randcol == "RED") {
				cout << "Result: " << randcol << " " << randnom << "\n You won!\n";
				monleft = bet + monleft + actprof;
				totprof = totprof + actprof;
				cout << "Current profit: " << actprof << "\n";
			}
			else if (chocol == 2 && randcol == "BLACK") {
				cout << "Result: " << randcol << " " << randnom << " \n You won!\n";
				monleft = bet + monleft + actprof;
				totprof = totprof + actprof;
				cout << "Current profit: " << actprof << "\n";

			}
			else if (chocol == 2 && randcol == "RED") {
				cout << "Result: " << randcol << " " << randnom << " \n You lost..\n";
				cout << "Current profit: 0\n";
			}
			else if (chocol == 0) {
				cont == false;
				break;
			}

		}
		else if (choose == 0) {
			cont = false;
			break;
		}

		// Asks if the user want to bet again and printing out how much money the user has left + total profit.

		cout << "\nYou have " << monleft << " left\nTotal profit: " << totprof << "\n";

		cout << "\nDo you want to bet again?\n"
			"\n1. Yes \n2. No\n";
		cin >> con;
		if (con == 1) {
			cont = true;
		}
		else if (con == 2) {
			cont = false;
		}
	} while (cont == true && checksald(monleft, 0));

	// If we have ended the game manually, we will print out "The game has ended"
	// Else that the player doesn't have enough money on account.
	if (monleft > 99 && cont == false) {
		cout << "The game has ended!";
	}
	else if (checksald(monleft, 0) < 99) {
		cout << "You don't have enough money in your account!\n"
			"The game is now over.";
	}
}
