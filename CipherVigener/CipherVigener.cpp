// CipherVigener.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

string alphabet = {"abcdefghijklmnopqrstuvwxyz"};

string Key(string cipherWord, string keyInput) {
	int i = 0;
	string key;
	for (int i = 0; i < cipherWord.length(); i++) {
		cout << "len cipher loop: " << cipherWord.length() - keyInput.length();
		for (int j = 0; j < keyInput.length(); j++) {
			cout << " key len: " << key.length() << " cipher len: " << cipherWord.length() << endl;
			if (key.length() == cipherWord.length()) {
				cout << "yea" << endl;
				break;
			}
			
			key = key + keyInput[j];
			cout << " Key : " << key<<endl;

			
			/*cout << "len: " << cipherWord.length() << endl;
			cout << "Key interation:" << i << endl;*/

		}
	}
	return key;
};

int main(){
	string cipherWord;
	string keyInput;
	getline(cin, cipherWord);
	getline(cin, keyInput);

	cout << Key(cipherWord, keyInput);
	system("pause");
    return 0;
}

