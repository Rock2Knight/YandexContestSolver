#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <fstream>

int main() {
	std::string temp = "";
	std::queue<std::string> myQueue;
	std::vector<std::string> ansVector;
	std::ifstream fin;
	std::ofstream fout;

	fin.open("input.txt");
	fout.open("output.txt");

	while (true) {
		getline(fin, temp);
		if (temp == "exit")
			break;
		else if (temp == "pop" || temp == "front") {
			if (myQueue.empty()) {
				ansVector.push_back("error");
				continue;
			}
			auto x = myQueue.front();
			if(temp == "pop")
				myQueue.pop();
			ansVector.push_back(x);
		}
		else if (temp == "size") {
			int x = myQueue.size();
			temp = std::to_string(x);
			ansVector.push_back(temp);
		}
		else if (temp == "clear") {
			while (!myQueue.empty())
				myQueue.pop();
			ansVector.push_back("ok");
		}
		else {
			auto index = temp.find_last_of("push");
			if (index != 0) {
				temp = temp.substr(index + 2);
				myQueue.push(temp);
				ansVector.push_back("ok");
			}
		}
	}

	fin.close();
	while (!myQueue.empty())
		myQueue.pop();

	ansVector.push_back("bye");
	for (auto it = ansVector.begin(); it != ansVector.end(); it++)
		fout << *it << std::endl;

	ansVector.clear();
	fout.close();
	return 0;
}