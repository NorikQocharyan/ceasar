#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>


//using namespace std;

int main()

{
	std::string message = "caesar salad very tasty";
	char ch;
	int i, key;
	std::cout << message << message.size();
	std::cout << "Enter key: ";
	std::cin >> key;
	for (i = 0; i < message.size(); ++i) {
		ch = message[i];
		if (ch >= 'a' && ch <= 'z') {
			ch = ch + key;
			if (ch > 'z') {
				ch = ch - 'z' + 'a' - 1;
			}
			message[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch + key;
			if (ch > 'Z') {
				ch = ch - 'Z' + 'A' - 1;
			}
			message[i] = ch;
		}
	}
	std::cout << "Encrypted message: " << message;
	    


	for (i = 0; i <message.size(); ++i) {
		ch = message[i];
		if (ch >= 'a' && ch <= 'z') {
			ch = ch - key;
			if (ch < 'a') {
				ch = ch + 'z' - 'a' + 1;
			}
			message[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch - key;
			if (ch > 'a') {
				ch = ch + 'Z' - 'A' + 1;
			}
			message[i] = ch;
		}
	}
	std::cout << "Decrypted message: " << message;
	return 0;
}