#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int main() {
	std::stack<std::string> ariphmStack;
	std::string postfix, operand;
	std::string left, right, res;
	std::stringstream stream;

	getline(std::cin, postfix);
	stream << postfix;
	while (stream >> operand) {
		if (operand == "+" || operand == "-" || operand == "*" || operand == "/") {
			if (ariphmStack.size() < 2) {
				std::cout << "Error! Stack is empty\n";
				break;
			}
			else {
				right = ariphmStack.top();
				ariphmStack.pop();
				left = ariphmStack.top();
				ariphmStack.pop();
				auto l = std::stoi(left);
				auto r = std::stoi(right);
				auto x = 0;

				if (operand == "+") {
					x = l + r;
					res = std::to_string(x);
					ariphmStack.push(res);
				}
				else if (operand == "-") {
					x = l - r;
					res = std::to_string(x);
					ariphmStack.push(res);
				}
				else if (operand == "*") {
					x = l * r;
					res = std::to_string(x);
					ariphmStack.push(res);
				}
				else if (operand == "/") {
					x = l / r;
					res = std::to_string(x);
					ariphmStack.push(res);
				}
			}
		}
		else
			ariphmStack.push(operand);
	}

	res = ariphmStack.top();
	ariphmStack.pop();
	std::cout << res << "\n";
	return 0;
}