// Laboration2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>;
#include <string>;
#include <algorithm>;
#include <array>;
#include <random>;
#include <ctime>;
using namespace std;

// Returnerar det första elementet i arrayen.
int getCard(int card[]) {
	srand(0);

	return card[rand() % 52];
};

// Blandar korten och hämtar det första kortet med hjälp av funktion ovan
// och returnerar det.
int getRandom(int cards[]) {

	random_shuffle(&cards[0], &cards[52]); // & pekar på pos.

	int card = getCard(cards);

	return card;
};
// getWinner checks who won the round, if the players got the same value, we check the color.
int getWinner(int first, int second, string firstcol, string secondcol) {
	if (first > second) {
		return 1;
	}
	else if (second > first) {
		return 2;
	}
	else if (first == second) {
		if (firstcol == "SPADES") {
			return 1;
		}
		else if (secondcol == "SPADES") {
			return 2;
		}
		else if (firstcol == "HEARTS") {
			return 1;
		}
		else if (secondcol == "HEARTS") {
			return 2;
		}
		else if (firstcol == "DIAMONDS") {
			return 1;
		}
		else if (secondcol == "DIAMONDS") {
			return 2;
		}
	}
};



int main()
{
	int arr[] = { 1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13 }; // KORTLEKEN
	string col[] = { "SPADES","HEARTS","DIAMONDS","CLOVER" }; // färg
	bool cont = true;
	int choose;
	int play1 = 0;
	int play2 = 0;
	int totpl1 = 0;
	int totpl2 = 0;
	int i, j;
	int count = 0;
	int round = 1;
	cout << "Each player draw a card. The player who gets the highest value on the card, wins the round.\n";
	cout << "If the players get the same value, it is the color on the card that decides who wins in the order: spades, hearts, diamonds and cloves.\n"
		"Good luck!\n\n";


	do {

		cout << "Press 1 to draw, 0 to end game.\n";
		cin >> choose;

		if (choose == 1) { // Väljer vi att slumpa kort, genererar vi 2 slumpmässiga tal mellan 0-4 för att bestämma färg.
			cout << "Round: " << round << "\n\n";
			round++;

			srand(time(0));

			i = rand() % 4;
			j = rand() % 4;

			int firstcard = getRandom(arr);
			string firstc = col[i];
			int secondcard = getRandom(arr);
			string secondc = col[j];

			if (firstcard == secondcard && i == j) { // i = color of firs card, j = col of second card

				do { // if the cards value are the same, we change only the "second" card.
					j = rand() % 4;
					secondc = col[j];
				} while (i != j);
			}
			cout << "Player 1 got: " << firstcard << " " << firstc << "\n";
			cout << "Player 2 got: " << secondcard << " " << secondc << "\n";

			if (getWinner(firstcard, secondcard, firstc, secondc) == 1) {
				play1++;

				cout << "\nPlayer 1 won this round.\n"
					"Scores in round: \n Player 1: " << play1;
				cout << "\n Player 2: " << play2 << "\n";
			}
			else if (getWinner(firstcard, secondcard, firstc, secondc) == 2) {
				play2++;

				cout << "\nPlayer 2 won this round.\n"
					"Scores in round: \n Player 1: " << play1;
				cout << "\n Player 2: " << play2 << "\n";
			}
			else if (getWinner(firstcard, secondcard, firstc, secondc) == -1) {
				cout << "NÅGOT BLEV FEL";
				break;
			}
			count++;

			if (round == 4) {
				round = 1;
			}

			if (count == 3) {

				if (play1 > play2) {
					totpl1++;
					cout << "\nPlayer 1 won!\n           \nTotal Scores        Won        Lost \n";
					cout << "Player 1:            " << totpl1 << "          " << totpl2;
					cout << "\nPlayer 2:            " << totpl2 << "          " << totpl1 << "\n";
					play1 = 0;
					play2 = 0;
				}
				else if (play2 > play1) {
					totpl2++;
					cout << "\nPlayer 2 won!\n            \nTotal Scores:        Won        Lost \n";
					cout << "Player 1:             " << totpl1 << "           " << totpl2;
					cout << "\nPlayer 2:             " << totpl2 << "           " << totpl1 << " \n\n";;
					play1 = 0;
					play2 = 0;
				}
				count = 0;
			}
		}

		else if (choose == 0) {
			cont = false;
		}
	} while (cont == true);

}
