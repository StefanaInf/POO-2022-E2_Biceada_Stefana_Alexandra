#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>

std::ifstream in("input.txt");

bool isSep(char c) {
	if (c == ' ' || c == ',' || c == '.' || c == '!' || c == '?')
		return true;
	return false;
}

class Compare {
public:
	bool operator() (std::pair<std::string, int> p1, std::pair<std::string, int> p2) {
		//comparam nr de aparitii ale fiecarui cuvant
		if (p1.second < p2.second)  return true;
		if (p1.second > p2.second)	return false;
		if (p1.first > p2.first) return true;
		return false;
	}
};

int main()
{
	std::string sentence;

	if (!in) {
		std::cout << "Error! File could not be opened! :(";
		return 0;
	}
	getline(in, sentence);
	std::cout << "The sentence read from the file: " << sentence << std::endl;

	//transformam literele mari in litere mici
	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
			sentence[i] = sentence[i] + 32;
		}
	}

	std::map<std::string, int> mymap;

	std::string aux;
	std::string::iterator i = sentence.begin();

	while (i != sentence.end()) {
		if (isSep(*i) != true) {
			aux += *i;
		}
		else {
			if (aux.empty() == false) {
				if (mymap.count(aux) != 0) {
					mymap[aux] += 1;
				}
				else {
					mymap[aux] = 1;
				}
			}
			aux.clear();
		}
		i++;
	}

	for (auto mapIterator = mymap.begin(); mapIterator != mymap.end(); mapIterator++) {
		std::cout << mapIterator->first << " : " << mapIterator->second << std::endl;
	}

	//coada de prioritati
	std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Compare> myQueue;

	for (auto mapIterator = mymap.begin(); mapIterator != mymap.end(); mapIterator++) {
		myQueue.push(std::pair<std::string, int>(mapIterator->first, mapIterator->second));
	}

	std::cout << std::endl;
	std::cout << "SORTED WORDS: " << std::endl;
	std::cout << std::endl;

	while (!myQueue.empty()) {
		std::cout << myQueue.top().first << " => " << myQueue.top().second << std::endl;
		myQueue.pop();
	}
	
	//std::cout << sentence << std::endl;
	return 0;
}