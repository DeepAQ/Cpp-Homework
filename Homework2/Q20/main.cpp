/*
 * main.cpp
 *
 *  Created on: 2016年10月14日
 *      Author: adn55
 */

#include <iostream>
#include <vector>

using namespace std;

int check(vector<int>& v, int target)
{
	int s = 0, t = 1;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		s += v[i];
		if (s > target)
		{
			s = v[i];
			t++;
		}
	}
	return t;
}

int main()
{
	vector<int> v;
	int n, m, a;

	cin >> m >> n;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.insert(v.end(), a);
		if (a > max) max = a;
	}

	while (check(v, max) > m) max++;

	cout << max;
	return 0;
}
