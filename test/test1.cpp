#include <iostream>
using namespace std;
int main() { 
	int character;
	//cout << cin.eof << endl;
	while ((character = cin.get()) != EOF) {
		cout.put(character);
	}
	cout << character << endl;
	//cout << cin.eof << endl;
	return 0;
} 
