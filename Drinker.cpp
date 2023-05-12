#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <fstream>

int main() {
	bool isBotva = false;
	int countOfAction = 0;
	std::queue<int> player1, player2;
	std::string winner, input, num;
	std::stringstream stream1, stream2;
	std::ifstream fin;
	std::ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");

	// Считывание номеров карт первого игрока и складывание их в очередь
	getline(fin, input);
	stream1 << input;
	while (stream1 >> num) {
		auto x = std::stoi(num);
		player1.push(x);
	}

	// Считывание номеров карт второго игрока и складывание их в очередь
	getline(fin, input);
	stream2 << input;
	while (stream2 >> num) {
		auto x = std::stoi(num);
		player2.push(x);
	}

	while (!player1.empty() && !player2.empty()) {
		if (countOfAction > 1000000) {
			isBotva = true;
			break;
		}

		auto card1 = player1.front();
		auto card2 = player2.front();
		player1.pop();
		player2.pop();

		if (card1 == 0) {
			if (card2 == 9) {
				player1.push(card1);
				player1.push(card2);
			}
			else {
				player2.push(card1);
				player2.push(card2);
			}
		}
		else if (card2 == 0) {
			if (card1 == 9) {
				player2.push(card1);
				player2.push(card2);
			}
			else {
				player1.push(card1);
				player1.push(card2);
			}
		}
		else if (card1 > card2) {
			player1.push(card1);
			player1.push(card2);
		}
		else if (card2 > card1) {
			player2.push(card1);
			player2.push(card2);
		}
		countOfAction++;
	}

	if (isBotva)
		fout << "botva" << std::endl;
	else if (!player1.empty())
		fout << "first " << countOfAction << std::endl;
	else
		fout << "second " << countOfAction << std::endl;

	while (!player1.empty())
		player1.pop();
	while (!player2.empty())
		player2.pop();

	fout.close();
	return 0;
}