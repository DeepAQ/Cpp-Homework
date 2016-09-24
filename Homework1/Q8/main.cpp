/*
 * main.cpp
 *
 *  Created on: 2016年9月25日
 *      Author: adn55
 */

#include <iostream>

using namespace std;

int main() {
	long n, a, temp;
	cin >> n;
	a = n;
	temp = 0;
	while (n > 0) {
		temp = temp * 10 + n%10;
		n = n / 10;
	}
	while (temp >= 10) {
		cout << temp%10 << " ";
		temp = temp / 10;
	}
	cout << temp%10;
	if (a > 0 && a%10 == 0) {
		cout << " 0";
	}
	return 0;
}
