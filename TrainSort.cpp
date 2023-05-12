#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <fstream>

int main() {
	bool ans = true;
	int n, temp;
	std::stack<int> train;
	std::stack<int> deadlock;
	std::string N, input, num;
	std::stringstream stream;
	std::ifstream fin;

	fin.open("input.txt");
	getline(fin, N);
	n = std::stoi(N);
	getline(fin, input);
	stream << input;

	while (stream >> num) {
		temp = std::stoi(num);
		if (deadlock.empty())
			deadlock.push(temp);
		else if (temp < deadlock.top())
			deadlock.push(temp);
		else{
			while (!deadlock.empty() && deadlock.top() < temp) {
				auto x = deadlock.top();
				deadlock.pop();
				if (train.empty())
					train.push(x);
				else if (train.top() < x)
					train.push(x);
				else {
					ans = false;
					break;
				}
			}
			deadlock.push(temp);
		}
	}

	while (!deadlock.empty()) {
		auto x = deadlock.top();
		deadlock.pop();
		if (train.empty())
			train.push(x);
		else if (train.top() < x)
			train.push(x);
		else {
			ans = false;
			break;
		}
	}

	if (ans)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
	
	fin.close();
	return 0;
}