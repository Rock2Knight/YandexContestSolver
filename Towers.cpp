#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include <vector>

int main() {
	char temp = 'x';      // Временный символ для сортировки
	int k = 0;            // индекс символа в строке

	std::ifstream fin;
	std::ofstream fout;
	std::string stroka;
	std::map<char, int> countSigns;
	std::vector<char> signs;
	auto maxCount = -1;

	fin.open("input.txt");
	fout.open("output.txt");

	while (!fin.eof()) {
		getline(fin, stroka);

		for (auto i = 0; i < stroka.size(); i++) {
			if (stroka[i] != ' ' && stroka[i] != '\n') {
				if (!countSigns.contains(stroka[i]))
					countSigns[stroka[i]] = 1;
				else
					countSigns[stroka[i]]++;
			}
		}
	}

	for (auto it = countSigns.begin(); it != countSigns.end(); it++) {
		signs.push_back(it->first);
		k++;
	}
	
	for (auto i = 0; i < signs.size(); i++) {
		if (countSigns[signs[i]] > maxCount)
			maxCount = countSigns[signs[i]];
	}

	for (auto i = maxCount; i > 0; i--) {
		for (auto j = 0; j < signs.size(); j++) {
			if (countSigns[signs[j]] >= i)
				fout << "#";
			else
				fout << " ";
		}
		fout << "\n";
	}

	for (auto i = 0; i < signs.size(); i++)
		fout << signs[i];

	fin.close();
	fout.close();

	return 0;
}