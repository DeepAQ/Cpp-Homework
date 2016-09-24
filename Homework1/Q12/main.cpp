/*
 * main.cpp
 *
 *  Created on: 2016年9月25日
 *      Author: adn55
 */

#include <iostream>

using namespace std;

int main() {
	int n, s=0;
	cin >> n;
	while (n > 0) {
		if (n%2 == 1) s++;
		n /= 2;
	}
	cout << s;
	return 0;
}
