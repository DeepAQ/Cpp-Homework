/*
 * main.cpp
 *
 *  Created on: 2016年9月25日
 *      Author: adn55
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long a, b, s=0;
	cin >> a >> b;
	for (long i = a; i <= b; i++) {
		bool prime = true;
		if (i == 1) prime = false;
		for (long j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				prime = false;
				break;
			}
		}
		if (prime) s+=i;
	}
	cout << s;
	return 0;
}
