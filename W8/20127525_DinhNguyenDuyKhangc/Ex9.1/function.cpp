#include"function.h"

int hashFunction1(int value, int size) {
	return value % size;
}

void Insert1(vector<int> hash[], int value, int size) {
	int id = hashFunction1(value, size);
	hash[id].push_back(value);
}

bool Search1(vector<int> hash[], int value, int size) {
	int id = hashFunction1(value, size);
	for (auto i : hash[id]) {
		if (i == value)return true;
	}
	return false;
}




int hashFunction2(int value, int size, int i) {
	return (value + i) % size;
}

void Insert2(int hash[], int value, int size, int check) {
	int id = hashFunction2(value, size, 0);
	int i = 1;
	while (hash[id] != check) {
		id = hashFunction2(value, size, i);
		i++;
	}
	hash[id] = value;
}

bool Search2(int hash[], int value, int size) {
	int id = hashFunction2(value, size, 0);
	int i = 1;
	if (hash[id] == value) return true;
	while(i<size){
		id = hashFunction2(value, size, i);
		if (hash[id] == value) return true;
		i++;
	}
	return false;
}




int hashFunction3(int value, int size, int i) {
	return (value + i * i) % size;
}

void Insert3(int hash[], int value, int size, int check) {
	int id = hashFunction3(value, size, 0);
	int i = 1;
	while (hash[id] != check) {
		id = hashFunction3(value, size, i);
		i++;
	}
	hash[id] = value;
}

bool Search3(int hash[], int value, int size) {
	int id = hashFunction3(value, size, 0);
	int i = 1;
	if (hash[id] == value) return true;
	while (i < size) {
		id = hashFunction3(value, size, i);
		if (hash[id] == value) return true;
		i++;
	}
	return false;
}




int hashFunction4(int value, int size, int p, int i) {
	return ((value % size) - i * (p - (value % p))) % size;
}

void Insert4(int hash[], int value, int size, int check) {
	int id = hashFunction4(value, size, size - 2, 0);
	int i = 1;
	while (hash[id] != check) {
		id = hashFunction4(value, size, size - 2, i);
		i++;
	}
	hash[id] = value;
}

bool Search4(int hash[], int value, int size) {
	int id = hashFunction4(value, size,size-2, 0);
	int i = 1;
	if (hash[id] == value) return true;
	while (i < size) {
		id = hashFunction4(value, size,size-2, i);
		if (hash[id] == value) return true;
		i++;
	}
	return false;
}