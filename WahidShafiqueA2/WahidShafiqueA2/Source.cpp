#include "Header.h"
#include <iostream>
#include <time.h>
#include <fstream> //diagnostic 

//RANK DECK
RankDeck::RankDeck() {//here we are simply populating the dealer deck
	//there are 13 ranks, and 4 suits, suits are arbitrary for this version of war
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 13; j++) {
			static int index = 0;
			deck.push_back(j);
			index++;
		}
	}
};

void RankDeck::shuffle() {//shuffle the dealer deck
	srand(time(NULL));
	for (int i = 0; i < DECKSIZE; i++) {
		int r = rand() % DECKSIZE;
		int temp = deck[i];
		deck[i] = deck[r];
		deck[r] = temp;
	}
}

void RankDeck::dealNextCard(Queue<int> *p1, Queue<int> *p2) {//from the dealer deck, evenly divvy out the cards
	ofstream myfile;
	myfile.open("playerHandContents.txt");
	while (!deck.empty()) {
		//push all the cards to the back of the players respective hand
		p1->push(deck.back());
		deck.pop_back();
		p2->push(deck.back());
		deck.pop_back();


		myfile << "the contents of the p1 hand is" << endl;
		myfile << p1->back() << endl;
		myfile << "the contents of the p2 hand is" << endl;
		myfile << p2->back() << endl;
	}
	myfile.close();
}

//WARGAME
WarGame::WarGame(int max) : maxNumGames(max) {
	//cout << maxNumGames;
}

bool WarGame::play() {
	//Queue <int> player1(DECKSIZE / 2);//each player starts with a hand of 26 cards
	//Queue <int> player2(DECKSIZE / 2);
	//Queue <int> prizePile(DECKSIZE);

	RankDeck deck;
	deck.shuffle();
	deck.dealNextCard(&player1, &player2);

	battle();
	//cout << player2.back();
	cout << prizePile.GetSize() << endl;
	return true;
}
void WarGame::battle() {

	static int turns = 0;
	turns += 1;
	//POP IS POP FRONT HERE
	//Get player1’s card from player1’s hand and put in prize pile


	int p1CardTop = player1.front();
	prizePile.push(p1CardTop);
	//Get player2’s card from player2’s hand and put in prize pile
	int p2CardTop = player2.front();
	prizePile.push(p2CardTop);

	if (p1CardTop > p2CardTop) {
		/*Whoever has the higher of the two cards wins the battle prize(the two cards) and places those
		cards at the bottom of their hands.*/

		player1.pop();
		player2.pop();
		//now put the prize pile in the back of p1's hand
		while (!prizePile.isEmpty()) {		//!!!!!!!FAILS HERE: root!= null
			player1.push(prizePile.front());
			prizePile.pop();
		}

		cout << player1.GetSize() << endl;
		cout << player2.GetSize() << endl;
		cout << prizePile.GetSize() << endl;
		cout << "p1 won on turn" << turns << endl;
		this->battle();

} else if (p1CardTop < p2CardTop) {

	player1.pop();
	player2.pop();
		while (prizePile.GetSize() != 0) {
			player2.push(prizePile.front());
			prizePile.pop();
		}
	cout << player1.GetSize() << endl;
	cout << player2.GetSize() << endl;
	cout << prizePile.GetSize() << endl;
	cout << "p2 won on turn" << turns << endl;

	this->battle();
} else {
	//WAR
	cout << "TIE" << endl;
	player1.pop();//removing the dealt cards from both players hands
	player2.pop();
	for (int i = 0; i < 3; i++) {//in addition to keeping the 2 dealt cards, each p places 3 more from their hands -> 2 + 6
		prizePile.push(p1CardTop);
		prizePile.push(p2CardTop);
		player1.pop();//removing the recently pushed cards
		player2.pop();
		//prizePile.pop();
	}
}

}
