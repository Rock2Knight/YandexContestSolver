#include <iostream>
#include <deque>
#include <string>
#include <vector>

int main() {
	std::string temp = "";
	std::deque<std::string> myDeque;
	std::vector<std::string> ansVector;

	while (true) {
		getline(std::cin, temp);
		
		if (temp == "exit") {
			ansVector.push_back("bye");
			break;
		}
		else if (temp == "back" || temp == "pop_back") {
			if (myDeque.empty())
				ansVector.push_back("error");
			else {
				auto res = myDeque.back();
				ansVector.push_back(res);
				if (temp == "pop_back")
					myDeque.pop_back();
			}
		}
		else if (temp == "front" || temp == "pop_front") {
			if (myDeque.empty())
				ansVector.push_back("error");
			else {
				auto res = myDeque.front();
				ansVector.push_back(res);
				if (temp == "pop_front")
					myDeque.pop_front();
			}
		}
		else if (temp == "size") {
			auto x = myDeque.size();
			auto res = std::to_string(x);
			ansVector.push_back(res);
		}
		else if (temp == "clear") {
			while (!myDeque.empty())
				myDeque.pop_back();
			ansVector.push_back("ok");
		}
		else
	}
}