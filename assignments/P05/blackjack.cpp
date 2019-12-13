///////////////////////////////////////////////////////////////////////////////
//
// Author:           Faith Howell
// Assignment:       Program_05
// Date:             13 December 2019
// Description:
//       blackjack.cpp: Main file of blackjack game
//        This program uses TermGame.h to create a visual game of  blackjack
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "term.h"
#include<stdlib.h>

using namespace TermGame;
using namespace std;
class bjackCard {
public:
	bjackCard* next;
	int cnum;
	int face;
	int suit;

	bjackCard() { // this is the defalt constructor
		next = NULL;
		cnum = 0;
		face = 0;
		suit = 0;
	}
	bjackCard(int num) {
		next = NULL;
		cnum = num;
		face = (num % 13) + 1;
		suit = num / 13.1;
	}

	int getface() {
		return face;
	}
	int getSuit() {
		return suit;
	}

	 /**
 * bjackCard
 * Purpose:
 *    Prints the bjackCard
 * Params:
 *     void
 * Returns:
 *     void
 */
	void Print() {
		string crd = "";
		crd += "┌────┐\n│";
		switch (suit) {
		case 0:
			crd += "♥ ";
			break;
		case 1:
			crd += "♦ ";
			break;
		case 2:
			crd += "♣ ";
			break;
		case 3:
			crd += "♠ ";
			break;
		}
		switch (face) {
		case 1:
			crd += "A │\n";
			break;
		case 11:
			crd += "J │\n";
			break;
		case 12:
			crd += "Q │\n";
			break;
		case 13:
			crd += "K │\n";
			break;
		case 10:
			crd += "10│\n";
			break;
		default:
			crd += to_string(face);
			crd += " │\n";
			break;
		}
		crd += "│    │\n";
		crd += "└────┘\n";

		cout << crd;
		
	}
};
// class for deck
class deck {
private:
	bjackCard* top;
	int decksize;

public:


	deck() {
		top = new bjackCard(1);
		bjackCard* temp = top;
		for (int i = 2; i < 53; i++) {
			temp->next = new bjackCard(i);
			temp = temp->next;
		}
		decksize = 52;
	}

	
	void shuffle() {
		srand(time(NULL));
		int num1;
		int num2;
		// cout << num;
		bjackCard* temp = top;
		bjackCard* temp2 = top;
		for (int i = 0; i < 1000; i++) {
			temp = top;
			temp2 = top;
			num1 = rand() % decksize;
			for (int i = 0; i <= num1; i++) {
				temp = temp->next;
			}
			num2 = rand() % decksize;
			for (int i = 1; i <= num2; i++) {
				temp2 = temp2->next;
			}
			swap(temp, temp2);
		}
	}

	void swap(bjackCard* a, bjackCard* b) {
		if (a == b) {
			return;
		}
		bjackCard *prevA = NULL;
		bjackCard *currA = top;
		while (currA != a)
		{
			prevA = currA;
			currA = currA->next;
		}
		bjackCard *prevB = NULL;
		bjackCard *currB = top;
		while (currB != b)
		{
			prevB = currB;
			currB = currB->next;
		}

		if (currA == NULL || currB == NULL)
			return;

		if (prevA != NULL)
			prevA->next = currB;
		else
			top = currB;

		if (prevB != NULL)
			prevB->next = currA;
		else
			top = currA;


		bjackCard* temp = currB->next;
		currB->next = currA->next;
		currA->next = temp;
	}

	void push(int A) {
		bjackCard *anode = new bjackCard(A);        // Allocate new memory
		cout << anode->suit;

		if (!top) {
			top = anode;                  
		}
		else {
			anode->next = top;  
			top = anode;                 
		}
		decksize++;
	}

	bjackCard* pop() {
		if (!top) {
			return NULL;        
		}
		else {
			bjackCard *Temp = top;  

			bjackCard *a = top;
			top = top->next;   
			delete Temp;        

			decksize--;
			return a;
		}

	}

	void print() {
		bjackCard *Temp = top;

		while (Temp != NULL) {
			Temp->Print();
			Temp = Temp->next;
		}
		cout << "Decksize: " << decksize << endl;
		cout << "---------------\n";
	}

};

class challange {
private:
	bjackCard* left;

public:

	challange() { // defalt constructor
		left = NULL;
	}

	void push(bjackCard* anode) {

		if (!left) {
			left = anode;  
			left->next = NULL;
		}
		else {
			anode->next = left;
			left = anode;                 
		}

	}

	int getScore() {
		bjackCard* temp = left;
		int score = 0;
		int ace = 0;

		if (left == NULL)
			return score;

		while (temp) {
			if (temp->face == 1) {
				score += 11;
				ace += 1;

			}
			else if (temp->face == 11 || temp->face == 12 || temp->face == 13) {
				score += 10;
			}
			else {
				score += temp->face;
			}

			temp = temp->next;
		}

		for (int i = 0; i < ace; i++) {
			if (score > 21) {
				score -= 10;
			}
		}
		score = 21 - score;
		return score;
	}
void Printinfo(){
    cout<< "Faith Howell\n";
    cout<< " Black Card Game\n";
    cout<<" 13th December 2019\n";
}
	void print() {
		bjackCard *Temp = left;
		while (Temp != NULL) {
			Temp->Print();
			Temp = Temp->next;
		}
		cout << "---------------\n";
	}

	void Hide() {
		left->Print();
		cout << "┌────┐\n│■■■■│\n│■■■■│\n└────┘\n";
	}

	void startHand(deck* D) {
		push(D->pop());
		push(D->pop());
	}

	int play(deck* D, int pScore) {
		int score = getScore();

		bool risk = true;
		if (pScore < 0) {
			risk = false;
		}
		while (score > pScore && risk) {
			push(D->pop());
			score = getScore();
		}
		return getScore();
	}

};

class current_Player {
private:
	bjackCard* left;

public:

	current_Player() {
		left = NULL;
	}

	void push(bjackCard* anode) {

		if (!left) {
			left = anode;                  
			left->next = NULL;
		}
		else {
			anode->next = left;            
			left = anode;                  
		}
	}

	int getScore() {
		bjackCard* temp = left;
		int score = 0;
		int ace = 0;

		if (left == NULL)
			return score;

		while (temp) {
			if (temp->face == 1) {
				score += 11;
				ace += 1;
			}
			else if (temp->face == 11 || temp->face == 12 || temp->face == 13) {
				score += 10;
			}
			else {
				score += temp->face;
			}
			temp = temp->next;
		}

		for (int i = 0; i < ace; i++) {
			if (score > 21) {
				score -= 10;
			}
		}
		score = 21 - score;

		return score;
	}

	void print() {
		bjackCard *Temp = left;

		while (Temp != NULL) {
			Temp->Print();
			Temp = Temp->next;
		}
		cout << "---------------\n";
	}

	int play(deck* D, challange* dealer) {
		int score;
		bjackCard* selected = left;
		bool fold = false;
		char move;

		cout << "Dealer hand: \n";

		dealer->Hide();

		push(D->pop());
		push(D->pop());

		while (!fold && getScore() >= 0) {
			cout << "Current hand: \n";
			print();

			cout << "What do you want to do?(F = fold, H = hit,D = see dealers hand)\n";
			move = getch();
			move = toupper(move);
			TermPrint::clear();
			if (move == 'F')
				fold = true;
			else if (move == 'H') {
				push(D->pop());
			}
			else if (move == 'D') {
				cout << "Dealers hand: \n";
				dealer->Hide();
			}
			else
				cout << "Wrong input.\n";

		}

		if (getScore() == 0) {
			cout << "21!\n";
		}
		cout << "Your Hand: \n";
		print();

		return score;
	}

};

int main() {
	deck xd;
	current_Player human;
	challange card;
	xd.shuffle();
  card.Printinfo();
	card.startHand(&xd);

	human.play(&xd, &card);

	int playerScore = human.getScore();
	int score;

	score = card.play(&xd, playerScore);

	cout << "Dealers hand: \n";
	card.print();

	cout << "Your score: " << 21 - playerScore << endl;
	cout << "Dealer score: " << 21 - score << endl;

	if (playerScore < 0) {
		cout << "BUST!\n";
	}
	else if (score < 0) {
		cout << "DEALER BUST!\n";
	}
	else {
		if (score < playerScore) {
			cout << "LOSE!\n";
		}
		else if (score == playerScore) {
			cout << "TIE!\n";
		}
		else {
			cout << "WIN!\n";
		}
	}
}
