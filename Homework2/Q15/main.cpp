/*
 * main.cpp
 *
 *  Created on: 2016年10月14日
 *      Author: adn55
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, a, s, max = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (i == 0)
		{
			max = s = a;
		}
		else
		{
			if (s <= 0)
				s = a;
			else
				s += a;
			if (s > max)
				max = s;
		}
	}

	cout << max;
	return 0;
}
