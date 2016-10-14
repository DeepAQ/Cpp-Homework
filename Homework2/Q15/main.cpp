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
	vector<int> v;
	int n, a;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.insert(v.end(), a);
	}

	int max = v[0], s = v[0];
	for (int i = 1; i < n; i++)
	{
		if (s <= 0)
			s = v[i];
		else
			s += v[i];
		if (s > max)
			max = s;
	}

	cout << max;
	return 0;
}
