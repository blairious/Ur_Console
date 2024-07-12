#include <iostream>
#include <cstdlib>
using namespace std;

//Board Default Values
string board_def[20] = { "[O 1]", "[O 2]", "[O 3]", "[O 4]", "[P 1]", "[P 2]", "[P 3]", "[P 4]", "[C 1]", "[C 2]", "[C 3]", "[C 4]", "[C 5]", "[C 6]", "[C 7]", "[C 8]", "[O 5]", "[O 6]", "[P 5]", "[P 6]" };

//Board Default Value
string board_player[20] = { "[O01]", "[O02]", "[O03]", "[O04]", "[P01]", "[P02]", "[P03]", "[P04]", "[C01]", "[C02]", "[C03]", "[C04]", "[C05]", "[C06]", "[C07]", "[C08]", "[O05]", "[O06]", "[P05]", "[P06]" };

//Board Default Values
string board_oppo[20] = { "[OX1]", "[OX2]", "[OX3]", "[OX4]", "[PX1]", "[PX2]", "[PX3]", "[PX4]", "[CX1]", "[CX2]", "[CX3]", "[CX4]", "[CX5]", "[CX6]", "[CX7]", "[CX8]", "[OX5]", "[OX6]", "[PX5]", "[PX6]" };

//current player progress
bool player_progress[14] = { false, false, false, false, false, false, false, false, false, false, false, false, false, false };

//current player progress
bool oppo_progress[14] = { false, false, false, false, false, false, false, false, false, false, false, false, false, false };

//Scores of opponent and player
int player_score = 0;
int oppo_score = 0;

int player_bank = 7;
int oppo_bank = 7;

void graphics_update() {

	//map board top
	for (int i = 3; i >= 0; --i) {
		if (oppo_progress[i] == true) {
			cout << board_oppo[i];
		}
		else {
			cout << board_def[i];
		}
	}
	cout << "          ";
	for (int i = 17; i > 15; --i) {
		if (oppo_progress[i - 2] == true) {
			cout << board_oppo[i];
		}
		else {
			cout << board_def[i];
		}
	}
	cout << "\n";
	//Board Middle
	for (int i = 8; i < 16; i++) {
		if (player_progress[i] == true) {
			cout << board_player[i];
		}
		else if (oppo_progress[i] == true) {
			cout << board_oppo[i];
		}
		else {
			cout << board_def[i];
		}
	}
	cout << "\n";
	//map board bottom
	for (int i = 7; i >= 4; --i) {
		if (player_progress[i] == true) {
			cout << board_player[i];
		}
		else {
			cout << board_def[i];
		}
	}
	cout << "          ";
	for (int i = 19; i > 17; --i) {
		if (player_progress[i] == true) {
			cout << board_player[i];
		}
		else {
			cout << board_def[i];
		}
	}
	cout << "\n";
};



int main() {

	bool player_move = true;
	int player_response;
	while (player_move == true) {
		graphics_update();
		cout << "How many spaces?\n";
		cin >> player_response;
		for (int i = 0; i < 14; i++) {
			player_progress[i] = false;
		}
		player_progress[player_response + 1] = true;
	}
	

	return 0;
}


