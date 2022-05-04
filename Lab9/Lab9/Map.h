#pragma once
#include "Pair.h"

template<class K, class V>
class Map
{
private:
	Pair<K, V> pairs;
	int number_elements;
public:
	Map(); //constructor
	~Map(); //deconstructor

	V& operator [](K key);
	K getKey(int index);
	V getValue(int index);

	void Set(const K& key, const V& val); //method that associates the value to a key
	bool Get(const K& key, V& value); //method that will copy the value from key into the value parameter and return ture
	int Count(); //method that returns the number of elements in the map
	void Clear(); //method that clears the entire map
	bool Delete(const K& key); //method that deletes a specific key 
	bool Includes(const Map<K, V>& map); //checks if the map is included in another one
};

template<class K, class V>
Map<K, V>::Map() {
	//alocam memorie
	pairs = (Pair<K, V>*)malloc(2 * sizeof(Pair<K, V>));
	pairs = nullptr;

	this->number_elements = 0;
}

template<class K, class V>
Map<K, V>::~Map() {
	delete pairs;
}

template<class K, class V>
void Map<K, V>::Set(const K& key, const V& value) {
	bool IsKey = false;
	for (int index = 0; index < this->number_elements; index++) {
		if (pairs[index].key == key) {
			IsKey = true;
			pairs[index].value = value;
		}
	}

	if (IsKey == false) {
		pairs = (Pair<K, V>*)realloc(pairs, (number_elements + 2) * sizeof(Pair<K, V>));
		pairs[number_elements].key = key;
		pairs[number_elements].index = number_elements;
		pairs[number_elements].value = value;
		number_elements++;
	}
}

template<class K, class V>
bool Map<K, V>::Get(const K& key, V& value) {
	for (int index = 0; index < this->number_elements; index++) {
		if (pairs[index].key == key) {
			value = pairs[index].value;
			return true;
		}
	}
	return false;
}

template<class K, class V>
int Map<K, V>::Count() {
	return this->number_elements;
}

template<class K, class V>
void Map<K, V>::Clear() {
	delete(pairs);
	this->number_elements = 0;
	//pairs = (Pair<K, V>*)malloc(2 * size(Pair<K, V>));
}

template<class K, class V>
bool Map<K, V>::Delete(const K& key) {
	bool existKey = false;
	int index; //if the key exist, we save the position in intex
	for (int i = 0; i < this->number_elements; i++) {
		if (pairs[i].key == key) {
			existKey = true;
			index = i;
		}
	}

	if (existKey == false) {
		return false;
	}

	if (existKey == true) {
		for (int i = index; i < this->number_elements; i++) {
			pairs[i] = pairs[i + 1];
		}
		this->number_elements--;
		return true;
	}
}

template<class K, class V>
bool Map<K, V>::Includes(const Map<K, V>& map) {
	bool find;
	for (int i = 0; i < map.number_elements; i++) {
		find = false;
		for (int j = 0 j < this->number_elements; j++) {
			if (this->pairs[j].key == map.pairs[i].key) {
				find = true;
				break;
			}
		}
	}
	if (find = false) {
		return false;
	}
	return true;
}

template<class K, class V>
V& Map<K, V>::operator[](K key) {
	bool existKey = false;
	int index = -1;

	for (int i = 0; i < this->number_elements; i++) {
		if (key == pairs[i].key) {
			existKey = true;
			index = i;
		}
	}

	if (existKey == false) {
		pairs = (Pair<K, V>*)realloc(pairs, (number_elements + 2) * sizeof(Pair<K, V>));
		pairs[number_elements].key = key;
		pairs[number_elements].index = number_elements;
		number_elements++;
		return pairs[number_elements - 1].value;
	}
	else {
		return pairs[index].value;
	}
}


template<class K, class V>
K Map<K, V>::getKey(int index) {
	return pairs[index].key;
}

template<class K, class V>
V Map<K, V>::getValue(int index) {
	return pairs[index].value;
}

