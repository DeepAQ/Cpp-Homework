/*
 * main.cpp
 *
 *  Created on: 2016年9月25日
 *      Author: adn55
 */

#include <iostream>

using namespace std;

int main() {
	int n, a=1, b=0, c;
	cin >> n;
	while (b < n) {
		b += a;
		a++;
	}
	c = n - b + a-1;
	if (a%2 == 0)
		cout << a-c << '/' << c;
	else
		cout << c << '/' << a-c;
	return 0;
}
