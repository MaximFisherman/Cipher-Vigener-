// CipherVigener.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

string alphabet = {"abcdefghijklmnopqrstuvwxyz "};


string Key(string cipherWord, string keyInput) {
	int i = 0;
	string key;
	for (int i = 0; i < cipherWord.length(); i++) {
		for (int j = 0; j < keyInput.length(); j++) {
			if (key.length() == cipherWord.length()) {
				break;
			}		
			key = key + keyInput[j];
		}
	}
	return key;
};

int GetNumberLetter(char Letter) {
	int numberPositionAlphabet = 0;
	for (int i = 0; i < alphabet.length(); i++) {
		if(Letter == alphabet[i]){
			numberPositionAlphabet = i;
			break;
		}
	}
	return numberPositionAlphabet;
}

char ConvertInLetter(int ASCII_ALPHABET) {
	return alphabet[ASCII_ALPHABET];
};

string Crypt(string cipherWord, string key) {
	string Crypt;
		for (int j = 0; j < cipherWord.length(); j++) {
			Crypt = Crypt + ConvertInLetter((GetNumberLetter(cipherWord[j]) + GetNumberLetter(key[j]))%alphabet.length());
		}

	return Crypt;
};

string Decode(string cipherWord, string key) {
	string Decrypt;
	for (int j = 0; j < cipherWord.length(); j++) {
		Decrypt = Decrypt + ConvertInLetter((GetNumberLetter(cipherWord[j]) - GetNumberLetter(key[j]) + alphabet.length()) % alphabet.length());
	}

	return Decrypt;
};

int main(){
	string cipherWord;
	string keyInput;
	getline(cin, cipherWord);
	getline(cin, keyInput);//Input user key word

	string cryptWord = Crypt(cipherWord,Key(cipherWord, keyInput));
	cout << "Crypt:" << cryptWord << endl;
	cout << Decode(cryptWord, Key(cipherWord, keyInput));
	system("pause");
    return 0;
}

