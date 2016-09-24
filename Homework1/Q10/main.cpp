/*
 * main.cpp
 *
 *  Created on: 2016年9月24日
 *      Author: adn55
 */

#include <iostream>

using namespace std;

int main()
{
	long n;
	__int128 a=0, b=1, c=1;
	cin >> n;
	for (long i=2; i<=n; i++) {
		c = a+b;
		a = b;
		b = c;
	}
	if (n == 0) c = 0;
	long long pf = c / 100000000000;
	long long sf = c % 100000000000;
	if (pf != 0) {
		cout << pf;
	}
	cout << sf;
	return 0;
}
