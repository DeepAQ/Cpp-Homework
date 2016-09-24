/*
 * main.cpp
 *
 *  Created on: 2016年9月25日
 *      Author: adn55
 */

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n>=90 && n<=100)
			cout << 'A';
	if (n>=80 && n<=89)
			cout << 'B';
	if (n>=70 && n<=79)
			cout << 'C';
	if (n>=60 && n<=69)
			cout << 'D';
	if (n>=0 && n<=59)
			cout << 'E';
	return 0;
}
