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
	int a, b, s=0;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
		if (i%2 == 1) s+=i;
	cout << s;
	return 0;
}
