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

	long long max = v[0], min = v[0], globalmax = v[0];
	for (int i = 1; i < n; i++)
	{
		max *= v[i];
		min *= v[i];
		if (min > max)
		{
			long long t = min;
			min = max;
			max = t;
		}
		if (v[i] > max) max = v[i];
		if (v[i] < min) min = v[i];
		if (max > globalmax) globalmax = max;
	}

	cout << globalmax;
	return 0;
}
