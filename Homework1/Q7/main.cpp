/*
 * main.cpp
 *
 *  Created on: 2016年9月25日
 *      Author: adn55
 */

#include <iostream>

using namespace std;

int main() {
	long n, s, x;
	cin >> n;
	if (n > 0) {
		cin >> s;
	}
	for (int i = 1; i < n; i++) {
		cin >> x;
		if (x < s) {
			s = x;
		}
	}
	cout << s;
	return 0;
}
