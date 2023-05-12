#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main() {
	int index;
	int num;                            // Число, которое мы кладем в стэк
	std::stack<std::string> myStack;    // Стэк чисел
	std::vector<std::string> ansStack;  // Стэк ответов
	std::string command = "";

	while (true) {
		getline(std::cin, command);
		if (command == "exit")
			break;

		if (command == "back") {
			if (myStack.empty())
				ansStack.push_back("error");
			else {
				command = myStack.top();
				ansStack.push_back(command);
			}
		}
		else if (command == "size") {
			command = std::to_string(myStack.size());
			ansStack.push_back(command);
		}
		else if (command == "clear") {
			while (!myStack.empty())
				myStack.pop();
			ansStack.push_back("ok");
		}
		else if (command == "pop") {
			if (myStack.empty())
				ansStack.push_back("error");
			else {
				ansStack.push_back(myStack.top());
				myStack.pop();
			}
		}
		else {
			index = command.find_last_of("push");
			if (index != 0) {
				command = command.substr(index + 2);
				myStack.push(command);
				ansStack.push_back("ok");
			}
		}
	}
	ansStack.push_back("bye");

	std::cout << std::endl;
	for (auto it = ansStack.begin(); it != ansStack.end(); it++)
		std::cout << *it << std::endl;

	ansStack.clear();
	return 0;
}