/*
 * main.cpp
 *
 *  Created on: 2016年10月14日
 *      Author: adn55
 */

#include <iostream>

using namespace std;

int main()
{
	int n, a, s = 0;
	bool first = true;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == 0)
			s++;
		else
		{
			if (!first) cout << " ";
			first = false;
			cout << a;
		}
	}
	for (int i = 0; i < s; i++)
	{
		if (!first) cout << " ";
		cout << "0";
	}
	return 0;
}
