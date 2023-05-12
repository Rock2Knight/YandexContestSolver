#include <iostream>
#include <stack>
#include <string>

int main() {
	std::string seq = "";
	std::string answer = "yes";
	std::stack<char> signs;
	std::cin >> seq;

	for (auto s : seq) {

		if (s == '(' || s == '[' || s == '{')
			signs.push(s);
		else if (s == ')') {
			if (!signs.empty()) {
				if (signs.top() == '(')
					signs.pop();
				else {
					answer = "no";
					break;
				}
			}
			else {
				answer = "no";
				break;
			}
		}
		else if (s == ']') {
			if (!signs.empty()) {
				if (signs.top() == '[')
					signs.pop();
				else {
					answer = "no";
					break;
				}
			}
			else {
				answer = "no";
				break;
			}
		}
		else if (s == '}') {
			if (!signs.empty()) {
				if (signs.top() == '{')
					signs.pop();
				else {
					answer = "no";
					break;
				}
			}
			else {
				answer = "no";
				break;
			}
		}

	}

	if (!signs.empty() || seq[0] == ')' || seq[0] == ']' || seq[0] == '}')
		answer = "no";

	std::cout << answer << std::endl;
	return 0;
}